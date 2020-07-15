#ifndef SRC_LIB_CORE_POST_HPP_
#define SRC_LIB_CORE_POST_HPP_
#include <ctime>
#include <string>

#include <odb/core.hxx>

#include "Object.hpp"

namespace ddi {
namespace kata {

PRAGMA_DB(object optimistic)
class Post: public Object
{
public:
    /**
     * @brief Construct a new Post object
     * 
     * @param content       post's content 
     */
    Post(const std::string& content);

    /**
     * @brief get post's content
     * 
     * @return const std::string& post's content 
     */
    const std::string&      content() const;

    /**
     * @brief get post's creation datetime
     * 
     * @return std::time_t  post's creation datetime
     */
    std::time_t             created() const;

    /**
     * @brief get post's creation date as a human readable string
     *
     * @return const std::string&
     */
    const std::string       createdHuman() const;
private:
    friend class odb::access;
    Post() {}
    const std::string       content_;
    std::time_t             created_;
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_POST_HPP_
