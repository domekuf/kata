#ifndef SRC_LIB_CORE_WALL_HPP_
#define SRC_LIB_CORE_WALL_HPP_
#include <ctime>
#include <map>
#include <memory>
#include <utility>
#include <vector>

namespace ddi {
namespace kata {

class User;
class Post;

class Wall
{
public:
    typedef const std::shared_ptr<User> user;
    typedef const std::shared_ptr<Post> post;
    typedef std::pair<user, post>       pair;
    typedef std::vector<pair>           vector;
    typedef std::map<time_t, vector>    map;
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_WALL_HPP_
