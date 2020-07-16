#include <map>
using std::map;
#include <boost/regex.hpp>
using boost::regex;
using boost::regex_match;
using boost::smatch;
#include <string>
using std::string;
#include <boost/optional.hpp>
using boost::optional;

#include "Phrase.hpp"
namespace ddi {
namespace kata {

const map<string, Phrase::verb> Phrase::verb_map_ = {
    {"",        READ},
    {"follows", FOLLOW},
    {"->",      POST},
    {"wall",    WALL}
};

Phrase::Phrase(const string& command)
{
    regex re("(.*)( +(->|follows|wall)( +(.*)?)?)|(.*)", regex::extended);
    //        ^--^|  ^---------------^   ^--^   | ^--^
    //            ^-----------------------------^
    //        1      3                   5        6
    // $1: subject
    // $3: predicate
    // $5: direct object
    // $6: subject when no verb
    smatch sm;
    if (regex_match(command, sm, re)) {
        unsigned c = 0;
        for (const auto s : sm) {
            switch (c) {
                case 1:
                subject_ = s;
                break;
                case 3:
                if (verb_map_.find(s) != verb_map_.end())
                    predicate_ = verb_map_.at(s);
                break;
                case 5:
                if ("" != s)
                    object_ = s;
                break;
                case 6:
                if ("" != s)
                    subject_ = s;
                break;
                default:
                break;
            }
            c ++;
        }
    }
}

optional<string> Phrase::object() const
{
    return object_;
}

Phrase::verb Phrase::predicate() const
{
    return predicate_;
}

string Phrase::subject() const
{
    return subject_;
}

} // namespace kata
} // namespace ddi
