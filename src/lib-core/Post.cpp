#include <ctime>
using std::time;
using std::time_t;

#include <string>
using std::string;

#include "Post.hpp"
namespace ddi {
namespace kata {

Post::Post(const string& content)
: content_(content)
, created_(time(nullptr))
{
}

const string& Post::content() const
{
    return content_;
}

time_t Post::created() const
{
    return created_;
}

} // namespace kata
} // namespace ddi
