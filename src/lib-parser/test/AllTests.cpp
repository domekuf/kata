#include "CppUTest/CommandLineTestRunner.h"

int main(int ac, const char* av[])
{
    MemoryLeakWarningPlugin::turnOffNewDeleteOverloads();
    int rc = CommandLineTestRunner::RunAllTests(ac, av);
    return rc;
}
