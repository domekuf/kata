yum install -y epel-release
yum install -y \
    autoconf \
    automake \
    make \
    gcc-c++
yum install -y
    cpputest-3.8-0.x86_64.rpm \
    sqlite-devel \
    odb \
    boost-devel \
    libtool \
    libodb-devel \
    libdob-sqlite-devel \
    libodb-boost-devel
pkg_path=$(rpm -ql cpputest | grep cpputest.pc | sed 's/cpputest.pc//')
echo "export PKG_CONFIG_PATH=$pkg_path"
