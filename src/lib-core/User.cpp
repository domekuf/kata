#include <memory>
using std::shared_ptr;
#include <string>
using std::string;
#include <vector>
using std::vector;

#include "Post.hpp"
#include "Wall.hpp"
#include "User.hpp"

namespace ddi {
namespace kata {

User::User(const string& /* name */)
{
}

const string& User::name() const
{
    return name_;
}

void User::follows(shared_ptr<User> /* user */)
{
}

void User::post(const string& /* content */)
{
}

vector<shared_ptr<Post>> User::timeline()
{
    return timeline_;
}

shared_ptr<Wall> User::wall()
{
    return nullptr;
}

} // namespace kata
} // namespace ddi
