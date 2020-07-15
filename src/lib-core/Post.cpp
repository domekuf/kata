#include <ctime>
using std::time;
using std::time_t;

#include <sstream>
#include <string>
using std::string;
using std::stringstream;

#include "TimeAgo.hpp"

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

const string Post::createdHuman() const
{
    return TimeAgo::human(time(nullptr), created_);
}

} // namespace kata
} // namespace ddi
