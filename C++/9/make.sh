#! /bin/sh
cd build/
make clean
cmake ..
make
./DonorList
