#ifndef SRC_LIB_CORE_USER_HPP_
#define SRC_LIB_CORE_USER_HPP_

#include <memory>
#include <string>
#include <vector>

#include <odb/core.hxx>

#include "Object.hpp"
#include "Wall.hpp"

namespace ddi {
namespace kata {

class Post;

PRAGMA_DB(object optimistic)
class User: public std::enable_shared_from_this<User>, public Object
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
    const std::shared_ptr<Post>             post(const std::string& content);

    /**
     * @brief get user's timeline
     * 
     * @return std::vector< std::shared_ptr<Post> > user's timeline 
     */
    std::vector< std::shared_ptr<Post> >    timeline();

    /**
     * @brief get user's wall
     * 
     * @return Wall::type .                 user's wall
     */
    Wall::map                               wall();
private:
    friend class odb::access;
    User() {}
    const std::string                       name_;
    std::vector< std::shared_ptr<Post> >    timeline_;
    std::vector< std::shared_ptr<User> >    followed_;

};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_USER_HPP_
