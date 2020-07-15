#include <ctime>
using std::time;
using std::time_t;

#include <sstream>
#include <string>
using std::string;
using std::stringstream;

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
    const time_t now = time(nullptr);
    unsigned gap = now - created_;
    stringstream out;
    if (gap < 60) {
        out << gap << " seconds ago";
        return out.str();
    }
    gap = (gap/60);
    if (gap < 60) {
        out << gap << " minutes ago";
        return out.str();
    } else {
        out << gap/60 << " hours ago";
        return out.str();
    }
}

} // namespace kata
} // namespace ddi
