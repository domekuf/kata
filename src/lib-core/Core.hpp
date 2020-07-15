#define DB_BASE_VERSION        1
#define DB_VERSION             1

#ifdef ODB_COMPILER

/// The version number represented as the base version,
/// and the latest version.
/// With each schema migration, the latest version should be incremented.

#pragma db model version(DB_BASE_VERSION, DB_VERSION)

#endif // ODB_COMPILER

#ifndef SRC_LIB_CORE_CORE_HPP_
#define SRC_LIB_CORE_CORE_HPP_
#include <map>
#include <memory>
#include <string>

namespace ddi {
namespace kata {

class Phrase;
class User;

class Core
{
public:
    /**
     * @brief get current database path
     *
     * @return const std::string&   current database path
     */
    static const std::string&       dbFile();

    /**
     * @brief perform migration to create or migrate schema and data
     *
     */
    static void                     migration();

    /**
     * @brief set database path
     *
     * @param dbf                   new database path
     */
    static void                     overrideDbFile(const std::string& dbf);

    static std::string              process(const std::shared_ptr<Phrase> p);
private:
    static std::string              db_file_;

    static std::map<const std::string, const std::shared_ptr<User>>
                                    user_map_;

    static std::shared_ptr<User>    findUser(const std::string& user);
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_CORE_HPP_
