#include <string>
#include <sstream>
#include <map>
#include <memory>
using std::shared_ptr;
using std::string;
using std::stringstream;
using std::map;

#include <Phrase.hpp>
#include <Core.hpp>

#include "Console.hpp"
namespace ddi {
namespace kata {

map<const string, Console::action> Console::command_map_ = {
    {"help", help}
};

string Console::help(const string&)
{
    return
    "Kata usage:\n"
    "   <username>: read user's wall\n"
    "   <username> -> <message> : post on user's wall\n";
}

string Console::command(const string& command)
{
    if (command_map_.find(command) != command_map_.end())
        return command_map_[command](command);
    const shared_ptr<Phrase> p(new Phrase(command));
    return Core::process(p);
}

} // namespace kata
} // namespace ddi
