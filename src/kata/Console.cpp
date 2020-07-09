#include <string>
#include <sstream>
#include <map>
using std::string;
using std::stringstream;
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

    stringstream ss;
    ss << command << ": command not found";
    return ss.str();
}

} // namespace kata
} // namespace ddi
