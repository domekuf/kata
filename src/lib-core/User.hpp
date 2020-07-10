#ifndef SRC_LIB_CORE_USER_HPP_
#define SRC_LIB_CORE_USER_HPP_

#include <memory>
#include <string>
#include <vector>

namespace ddi {
namespace kata {

class Post;
class Wall;
class User
{
public:
    /**
     * @brief Construct a new User object
     * 
     * @param name                          username
     */
    User(const std::string& name);

    /**
     * @brief start following given user
     * 
     * @param user                          reference to user to be followed 
     */
    void                                    follows(const std::shared_ptr<User> user);

    /**
     * @brief get user's name
     * 
     * @return const std::string&           user's name 
     */
    const std::string&                      name() const;

    /**
     * @brief create a post on user's timeline
     * 
     * @param content                       post's content
     */
    void                                    post(const std::string& content);

    /**
     * @brief get user's timeline
     * 
     * @return std::vector< std::shared_ptr<Post> > user's timeline 
     */
    std::vector< std::shared_ptr<Post> >    timeline();

    /**
     * @brief get user's wall
     * 
     * @return std::shared_ptr< Wall >      user's wall
     */
    std::shared_ptr< Wall >                 wall();
private:
    const std::string                       name_;
    std::vector< std::shared_ptr<Post> >    timeline_;
    std::vector< std::shared_ptr<User> >    followed_;

};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_USER_HPP_
