#include <memory>
using std::shared_ptr;

#include <User.hpp>
using ddi::kata::User;

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

TEST(UserGroup, follows)
{
    shared_ptr<User> alice(new User("Alice"));
    shared_ptr<User> bob(new User("Bob"));
    alice->follows(bob);
}