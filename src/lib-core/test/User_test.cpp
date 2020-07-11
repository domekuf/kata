#include <memory>
using std::shared_ptr;

#include <Post.hpp>
#include <User.hpp>
#include <Wall.hpp>
using ddi::kata::Post;
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
        const Wall::map w = alice->wall();
        size_t wall_size = 0;
        for (const auto wit : w) {
            for (const Wall::pair wp : wit.second) {
                wall_size ++;
            }
        }
        CHECK_EQUAL(1, wall_size);
    }
    alice->post("Hey there!");
    {
        const Wall::map w = alice->wall();
        size_t wall_size = 0;
        bool alice_found = false, bob_found = false;
        for (const auto wit : w) {
            for (const Wall::pair wp : wit.second) {
                wall_size ++;
                alice_found |= wp.first->name() == "Alice";
                bob_found |= wp.first->name() == "Bob";
            }
        }
        CHECK(alice_found);
        CHECK(bob_found);
        CHECK_EQUAL(2, wall_size);
    }
}