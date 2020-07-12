#ifndef SRC_LIB_PARSER_PHRASE_HPP_
#define SRC_LIB_PARSER_PHRASE_HPP_
#include <map>
#include <string>
#include <boost/optional.hpp>
namespace ddi {
namespace kata {

class Phrase
{
public:
    typedef enum {
        POST,
        READ,
        FOLLOW,
        WALL
    } verb;
    /**
     * @brief Construct a new Phrase object
     *
     * @param command               command that will be parsed 
     */
    Phrase(const std::string& command);

    /**
     * @brief get phrase direct object
     *
     * @return boost::optional<std::string> direct object 
     */
    boost::optional<std::string>    object() const;

    /**
     * @brief get phrase predicate
     *
     * @return verb                 predicate
     */
    verb                            predicate() const;

    /**
     * @brief get phrase subject
     *
     * @return std::string          subject
     */
    std::string                     subject() const;
private:
    static const std::map<std::string, verb> verb_map_;
    boost::optional<std::string>    object_;
    verb                            predicate_;
    std::string                     subject_;
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_PARSER_PHRASE_HPP_
