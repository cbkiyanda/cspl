

from ubuntu:14.04.1

maintainer Brian Larsen <balarsen@lanl.gov>

run apt-get update
run apt-get upgrade -y

run apt-get install -y build-essential
run apt-get install -y cmake
run apt-get install -y git
#run apt-get install -y doxygen
run apt-get install -y valgrind 

WORKDIR /cspl
run git clone https://github.com/cbkiyanda/cspl.git
run cd cspl

run ["cmake", "cspl", "-DBUILD_SHARED_LIBS=ON", "-DBUILD_TESTS=ON", "-DBUILD_EXAMPLES=ON"]
run make -j2
run make install

entrypoint [ "ctest" ]
