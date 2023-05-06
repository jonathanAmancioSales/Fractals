#!/bin/bash

file_cpp=Triangulo_Pascal.cpp

g++ -O3 -std=c++11 $file_cpp
./a.out

rm a.out
###################
# Create data folder if it does not exist:
data_folder=data_files
test -d $data_folder || mkdir $data_folder

mv Pontos*.txt $data_folder
###################
# Generate images:
for i in $(ls $data_folder/*.txt); do
  gnuplot -c generate_image.gnu $i
done

# Create image folder if it does not exist:
image_folder=images
test -d $image_folder || mkdir $image_folder

mv $data_folder/*.png $image_folder
###################