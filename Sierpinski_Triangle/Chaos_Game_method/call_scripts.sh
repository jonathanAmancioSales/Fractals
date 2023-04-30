#!/bin/bash

file_cpp=Sierpinski_Triangle_Chaos_Game.cpp

g++ -O3 -std=c++11 $file_cpp
./a.out

rm a.out
###################
# Create data folder if it does not exist:
data_folder=data_images
test -d $data_folder || mkdir $data_folder

mv Sierpinski_Triangle_pontos.txt $data_folder
###################
# Generate images:
for i in $(ls $data_folder/*.txt); do
  gnuplot -c Triangulo.gnu $i
done
###################