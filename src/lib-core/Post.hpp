#ifndef SRC_LIB_CORE_POST_HPP_
#define SRC_LIB_CORE_POST_HPP_
#include <ctime>
#include <string>

namespace ddi {
namespace kata {

class Post
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
private:
    const std::string       content_;
    const std::time_t       created_;
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_POST_HPP_
