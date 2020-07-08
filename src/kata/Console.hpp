#ifndef SRC_KATA_CONSOLE_HPP_
#define SRC_KATA_CONSOLE_HPP_

#include <map>
#include <string>

namespace ddi {
namespace kata {

class Console
{
public:
    /**
     * @brief processes command and returns output as a string
     * 
     * @param   command     command to be processed
     * @return              std::string console output
     */
    static std::string     command(const std::string& command);
private:
    typedef std::string (* action)(const std::string&);
    static std::map<const std::string, action> command_map_;

    static std::string     help(const std::string& command);
};

} // namespace kata
} // namespace ddi
#endif // SRC_KATA_CONSOLE_HPP_
