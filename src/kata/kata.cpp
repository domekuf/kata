#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::getline;
using std::endl;
using std::string;

#include <kata-odb.hxx>
#include <Core.hpp>
using ddi::kata::Core;

#include "Console.hpp"
using ddi::kata::Console;

void welcome()
{
    cout << "Welcome to Kata" << endl;
    cout << "Using " << Core::dbFile() << " as database" << endl;
}

int main(int /*ac*/, const char* /*av*/[])
{
    Core::migration();
    welcome();
    string command;
    do {
        cout << "(kata) ";
        getline(cin, command);
        if (command.empty())
            continue;
        cout << Console::command(command) << endl;
    } while (true);
}