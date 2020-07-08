#include <string>
#include <map>
using std::string;
using std::map;

#include "Console.hpp"
namespace ddi {
namespace kata {

map<const string, Console::action> Console::command_map_ = {
    {"help", help}
};

string Console::help(const string&)
{
    return "Kata usage:";
}

string Console::command(const string& command)
{
    if (command_map_.find(command) != command_map_.end())
        return command_map_[command](command);
    return command;
}

} // namespace kata
} // namespace ddi
