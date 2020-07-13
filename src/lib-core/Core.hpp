#ifndef SRC_LIB_CORE_CORE_HPP_
#define SRC_LIB_CORE_CORE_HPP_
namespace ddi {
namespace kata {

#define DB_BASE_VERSION        1
#define DB_VERSION             1

#ifdef ODB_COMPILER

/// The version number represented as the base version,
/// and the latest version.
/// With each schema migration, the latest version should be incremented.

#pragma db model version(DB_BASE_VERSION, DB_VERSION)

#endif // ODB_COMPILER

class Core
{
public:
    int test();
};

} // namespace kata
} // namespace ddi
#endif // SRC_LIB_CORE_CORE_HPP_
