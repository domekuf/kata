yum install -y cpputest-3.8-0.x86_64.rpm autoconf automake make
pkg_path=$(rpm -ql cpputest | grep cpputest.pc | sed 's/cpputest.pc//')
echo "export PKG_CONFIG_PATH=$pkg_path"
