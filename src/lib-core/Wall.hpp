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
    const std::vector< std::pair< std::shared_ptr<User>, std::shared_ptr <Post> > >
                                                    get() const;
private:
    const std::vector< std::pair< std::shared_ptr<User>, std::shared_ptr <Post> > >
                                                    content_;
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_WALL_HPP_
