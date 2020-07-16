Kata
====

Source code of a tiny CLI social network.

(Suggested) How to compile using CentOS 7 on Docker
------------
```
docker build . -t kata
docker run --privileged --detach \
    --mount type=volume,dst=/root/kata,volume-driver=local,volume-opt=type=none,volume-opt=o=bind,volume-opt=device=$(pwd) \
    --hostname kata --name kata kata /sbin/init
docker exec -it kata /bin/bash
sh ./install-dependencies.sh # only first time
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
Database in sqlite will be stored in `/tmp/kata.db`

What if you already have CentOS 7 environment?
-------------------------

```
git clone <repo-url>
cd kata
sudo sh ./install-dependencies.sh # only first time
source envvar
autoreconf -i
./configure
make
```
run unit test
```
make check
```