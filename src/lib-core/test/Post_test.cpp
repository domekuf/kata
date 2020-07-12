#include <ctime>
using std::time;
using std::time_t;

#include <Post.hpp>
using ddi::kata::Post;

#include <CppUTest/TestHarness.h>

TEST_GROUP(PostGroup)
{
};

TEST(PostGroup, constructor)
{
    Post post("Hey there!");
    const time_t now = time(nullptr);
    CHECK_EQUAL("Hey there!", post.content());
    /**
     it's quite unlikely to take more than one second 
     between post construction and 'now' initialization
     */
    CHECK(now <= post.created());
    CHECK(now > (post.created() - 1));
}