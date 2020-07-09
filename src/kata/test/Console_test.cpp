#include <Console.hpp>
using ddi::kata::Console;

#include <CppUTest/TestHarness.h>

TEST_GROUP(KataGroup)
{
};

TEST(KataGroup, isCbrsCell)
{
    CHECK_EQUAL("Kata usage:", Console::command("help"));
    CHECK_EQUAL("foo: command not found", Console::command("foo"));
}
