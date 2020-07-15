#include <ctime>
using std::time_t;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include "TimeAgo.hpp"
namespace ddi {
namespace kata {

string TimeAgo::human(const time_t now, const time_t t)
{
    unsigned gap = now - t;
    stringstream out;
    if (gap < 60) {
        out << gap << " second" << (gap > 1 ? "s":"") << " ago";
        return out.str();
    }
    gap = gap/60;
    if (gap < 60) {
        out << gap << " minute" << (gap > 1 ? "s":"") << " ago";
        return out.str();
    }
    gap = gap/60;
    if (gap < 24) {
        out << gap << " hour" << (gap > 1 ? "s":"") << " ago";
        return out.str();
    }
    gap = gap/24;
    out << gap << " day" << (gap > 1 ? "s":"") << " ago";
    return out.str();
}

} // namespace kata
} // namespace ddi
