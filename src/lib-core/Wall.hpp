#ifndef SRC_LIB_CORE_WALL_HPP_
#define SRC_LIB_CORE_WALL_HPP_
#include <memory>
#include <utility>
#include <vector>

#include "Post.hpp"
#include "User.hpp"

namespace ddi {
namespace kata {

class Wall
{
public:
    Wall(std::shared_ptr<User> user);
    const std::vector< std::pair<User, Post> >      get() const; 
private:
    const std::vector< std::pair<User, Post> >      content_; 
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_WALL_HPP_
