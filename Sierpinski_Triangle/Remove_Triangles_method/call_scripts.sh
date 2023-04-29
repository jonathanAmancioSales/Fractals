#!/bin/bash

file_cpp=Sierpinski_Triangle_1.2.cpp

g++ -O3 -std=c++11 $file_cpp
./a.out

rm a.out
###################
# Create data folder if it does not exist:
data_folder=data_files
test -d $data_folder || mkdir $data_folder

mv T_*.txt $data_folder
###################
# Generate images:
for i in $(ls $data_folder/T*.txt); do
  gnuplot -c Triangulo.gnu $i
done
###################