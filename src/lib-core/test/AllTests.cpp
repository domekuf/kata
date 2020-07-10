#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, const char* av[])
{
    int rc = CommandLineTestRunner::RunAllTests(ac, av);
    return rc;
}
