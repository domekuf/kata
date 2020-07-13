#ifndef SRC_LIB_CORE_OBJECT_HPP_
#define SRC_LIB_CORE_OBJECT_HPP_

#include <odb/core.hxx>

namespace ddi {
namespace kata {


PRAGMA_DB(object optimistic abstract)
class Object
{
public:
    typedef unsigned long                   key_t;
    typedef unsigned long                   version_t;
    friend class odb::access;
    PRAGMA_DB(id auto)
    key_t                                   key_;
    PRAGMA_DB(version)
    version_t                               version_;
    Object() {}
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_OBJECT_HPP_
