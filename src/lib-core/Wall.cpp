#include <memory>
using std::shared_ptr;
#include <utility>
using std::pair;
#include <vector>
using std::vector;

#include "Wall.hpp"
namespace ddi {
namespace kata {

Wall::Wall(shared_ptr<User> /* user */)
{
}

const vector<pair<User, Post>> Wall::get() const
{
    return content_;
}

} // namespace kata
} // namespace ddi
