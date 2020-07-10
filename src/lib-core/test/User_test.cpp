#include <memory>
using std::shared_ptr;

#include <User.hpp>
#include <Wall.hpp>
using ddi::kata::User;
using ddi::kata::Wall;

#include <CppUTest/TestHarness.h>

TEST_GROUP(UserGroup)
{
};

TEST(UserGroup, constructor)
{
    User alice("Alice");
    CHECK_EQUAL("Alice", alice.name());
    CHECK_EQUAL(0, alice.timeline().size());
}

TEST(UserGroup, post)
{
    User alice("Alice");
    alice.post("Hey there!");
    CHECK_EQUAL(1, alice.timeline().size());
}

TEST(UserGroup, followsAndWall)
{
    shared_ptr<User> alice(new User("Alice"));
    shared_ptr<User> bob(new User("Bob"));
    alice->follows(bob);
    bob->post("Hello world!");
    {
        const shared_ptr<Wall> w = alice->wall();
        CHECK_EQUAL(1, w->get().size());
    }
    alice->post("Hey there!");
    {
        const auto w = alice->wall()->get();
        CHECK_EQUAL(2, w.size());
        CHECK_EQUAL("Alice", w.at(0).first->name());
        CHECK_EQUAL("Bob", w.at(1).first->name());
    }
}