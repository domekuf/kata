#include <ctime>
using std::time;
using std::time_t;

#include <TimeAgo.hpp>
using ddi::kata::TimeAgo;

#include <CppUTest/TestHarness.h>

TEST_GROUP(TimeAgoGroup)
{
};

TEST(TimeAgoGroup, constructor)
{
    CHECK_EQUAL("1 second ago", TimeAgo::human(1, 0));
    CHECK_EQUAL("5 seconds ago", TimeAgo::human(5, 0));
    CHECK_EQUAL("1 minute ago", TimeAgo::human(60, 0));
    CHECK_EQUAL("2 minutes ago", TimeAgo::human(120, 0));
    CHECK_EQUAL("1 hour ago", TimeAgo::human(3600, 0));
    CHECK_EQUAL("2 hours ago", TimeAgo::human(7200, 0));
    CHECK_EQUAL("1 day ago", TimeAgo::human(3600 * 24, 0));
    CHECK_EQUAL("2 days ago", TimeAgo::human(3600 * 48, 0));
}