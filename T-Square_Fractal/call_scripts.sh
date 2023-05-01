#!/bin/bash
###################
file=T-Square.cpp
###################
#N=1
N=$1
###################
sed -i '/#define n_iter/c\#define n_iter '$N'' $file
###################
file3=Box_0$N.txt
echo $file3
###################
g++ -O3 -std=c++11 $file
./a.out > $file3
###################
rm a.out
###################
file2=T-Square.gnu
sed -i '/file=/c\file="'$file3'"' $file2
# read
gnuplot $file2
mv Box.png Box_0$N.png
###################
