#ifndef SRC_LIB_CORE_TIMEAGO_HPP_
#define SRC_LIB_CORE_TIMEAGO_HPP_
#include <ctime>
#include <string>
namespace ddi {
namespace kata {

class TimeAgo
{
public:
    static std::string human(const time_t now, const time_t t);
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_TIMEAGO_HPP_
