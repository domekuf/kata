#include <string>
using std::string;
#include <boost/optional.hpp>
using boost::optional;

#include "Phrase.hpp"
namespace ddi {
namespace kata {

Phrase::Phrase(const string& /* command */)
{
}

optional<string> Phrase::object() const
{
    return object_;
}

Phrase::verb Phrase::predicate() const
{
    return predicate_;
}

string Phrase::subject() const
{
    return subject_;
}

} // namespace kata
} // namespace ddi
