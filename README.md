Kata
====

Source code of a tiny CLI social network.

How to compile on CentOS7
-------------------------

```
git clone <repo-url>
cd kata
sudo sh install-dependencies # only first time
source envvar
autoreconf -i
./configure
make
```
run unit test
```
make check
```

Using docker
------------
```
docker build . -t kata
docker run --privileged --detach \
    --mount type=volume,dst=/root/kata,volume-driver=local,volume-opt=type=none,volume-opt=o=bind,volume-opt=device=$(pwd) \
    --hostname kata --name kata kata /sbin/init
docker exec -it kata /bin/bash
sudo sh install-dependencies # only first time
source envvar
autoreconf -i
./configure
make
make check #optionally
````

Run
---
```
src/kata/kata
```
Database in sqlite will be stored in /tmp/kata.db