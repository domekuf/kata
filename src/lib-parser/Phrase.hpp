#ifndef SRC_LIB_PARSER_PHRASE_HPP_
#define SRC_LIB_PARSER_PHRASE_HPP_
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
     * @return boost::optional<std::string> 
     */
    boost::optional<std::string>    object() const;
    verb                            predicate() const;
    std::string                     subject() const;
private:
    boost::optional<std::string>    object_;
    verb                            predicate_;
    std::string                     subject_;
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_PARSER_PHRASE_HPP_
