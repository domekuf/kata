#include <memory>
using std::shared_ptr;
#include <string>
using std::string;
#include <utility>
using std::pair;
#include <vector>
using std::vector;

#include "Post.hpp"
#include "Wall.hpp"
#include "User.hpp"

namespace ddi {
namespace kata {

User::User(const string& name)
: name_(name)
{
    timeline_ = {};
    followed_ = {};
}

const string& User::name() const
{
    return name_;
}

void User::follows(shared_ptr<User> user)
{
    followed_.push_back(user);
}

const shared_ptr<Post> User::post(const string& content)
{
    const shared_ptr<Post> post(new Post(content));
    timeline_.insert(timeline_.begin(), post);
    return post;
}

vector<shared_ptr<Post>> User::timeline()
{
    return timeline_;
}

Wall::map User::wall()
{
    Wall::map wall = {};
    for (const shared_ptr<User> user : followed_) {
        for (const shared_ptr<Post> post : user->timeline()) {
            wall[post->created()].push_back({user, post});
        }
    }
    for (const shared_ptr<Post> post : timeline()) {
        wall[post->created()].push_back({shared_from_this(), post});
    }
    return wall;
}

} // namespace kata
} // namespace ddi
