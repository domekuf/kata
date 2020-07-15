yum install -y \
    autoconf \
    automake \
    make \
    cpputest-3.8-0.x86_64.rpm \
    odb \
    boost-devel \
    libodb-devel \
    libdob-sqlite-devel \
    libodb-boost-devel \
    sqlite-devel
pkg_path=$(rpm -ql cpputest | grep cpputest.pc | sed 's/cpputest.pc//')
echo "export PKG_CONFIG_PATH=$pkg_path"
