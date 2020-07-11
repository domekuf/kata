yum install -y cpputest-3.8-0.x86_64.rpm
rpm -ql cpputest | grep cpputest.pc
export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig/
