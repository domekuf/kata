#include <iostream>
using std::endl;
#include <map>
using std::map;
#include <memory>
using std::shared_ptr;
#include <stdexcept>
using std::runtime_error;
#include <string>
#include <sstream>
using std::string;
using std::stringstream;

#include <odb/core.hxx>
#include <odb/database.hxx>
#include <odb/sqlite/database.hxx>
#include <odb/schema-catalog.hxx>
using odb::database;
using odb::schema_version;
using odb::schema_catalog;
using odb::transaction;
using odb::session;

#include "kata-odb.hxx"
#include <Phrase.hpp>
#include <User.hpp>
#include <Wall.hpp>

#include "Core.hpp"
namespace ddi {
namespace kata {

string Core::db_file_ = "/tmp/kata.db";
map<const string, const shared_ptr<User>> Core::user_map_;

const string& Core::dbFile()
{
    return db_file_;
}

void Core::migration()
{
    user_map_ = {
        {"Alice", shared_ptr<User>(new User("Alice"))},
        {"Bob", shared_ptr<User>(new User("Bob"))},
        {"Charlie", shared_ptr<User>(new User("Charlie"))}
    };

    shared_ptr<database>   db(new odb::sqlite::database (db_file_, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE));

    const string schema_nm("kata");

    schema_version version(db->schema_version(schema_nm));
    schema_version base_version(schema_catalog::base_version(*db, schema_nm));
    schema_version curr_version(schema_catalog::current_version(*db, schema_nm));

    if (version == 0) {
        // No schema in the database
        // Create the schema and initalize the database.
        transaction trxn(db->begin());
        schema_catalog::create_schema(*db, schema_nm, false);
        trxn.commit();
    } else if (version < curr_version) {
        // Old schema (and data), migrate.
        if (version < base_version) {
            throw runtime_error("Unable to upgrade this database.");
        }
        version = schema_catalog::next_version(*db, version, schema_nm);
        while (version <= curr_version) {
            session sess;
            transaction trxn(db->begin());
            schema_catalog::migrate_schema_pre(*db, version, schema_nm);
            schema_catalog::migrate_data(*db, version, schema_nm);
            schema_catalog::migrate_schema_post(*db, version, schema_nm);
            trxn.commit();
            version = schema_catalog::next_version(*db, version, schema_nm);
        }
    }
}

void Core::overrideDbFile(const std::string& dbf)
{
    db_file_ = dbf;
}

shared_ptr<User> Core::findUser(const string& name)
{
    const auto uit = user_map_.find(name);
    if (uit == user_map_.end())
        return nullptr;
    return uit->second;
}

string Core::process(const shared_ptr<Phrase> p)
{
    const string& subject = p->subject();
    stringstream out;
    const shared_ptr<User> user = findUser(subject);
    if (!user) {
        out << "User not found: " << subject;
        return out.str();
    }
    switch (p->predicate()) {
        case Phrase::READ :
            for (shared_ptr<Post> p : user->timeline()) {
                out << p->content() << " (" << p->createdHuman() << ")" << endl;
            }
            return out.str();
        break;
        case Phrase::POST :
            if (p->object()) {
                const string& obj = p->object().get();
                user->post(obj);
                out << subject << " posted: " << obj;
            } else {
                out << "No content set";
            }
            return out.str();
        break;
        case Phrase::FOLLOW :
            if (p->object()) {
                const string& obj = p->object().get();
                const shared_ptr<User> obj_user = findUser(obj);
                if (!obj_user) {
                    out << "User not found: " << obj;
                    return out.str();
                }
                user->follows(obj_user);
                out << subject << " is now following " << obj;
            } else {
                out << "No user to follow";
            }
            return out.str();
        break;
        case Phrase::WALL :
            for (const auto wit : user->wall()) {
                for (const Wall::pair wp : wit.second) {
                    out << wp.first->name() << " - "
                        << wp.second->content()
                        << " (" << wp.second->createdHuman() << ")" << endl;
                }
            }
            return out.str();
        break;
        default:
            return "";
        break;
    }
    return "";
}


} // namespace kata
} // namespace ddi