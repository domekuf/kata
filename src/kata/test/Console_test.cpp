#include <Console.hpp>
using ddi::kata::Console;

#include <CppUTest/TestHarness.h>

TEST_GROUP(KataGroup)
{
};

TEST(KataGroup, helpTest)
{
    CHECK_EQUAL("User not found: foo", Console::command("foo"));
}
