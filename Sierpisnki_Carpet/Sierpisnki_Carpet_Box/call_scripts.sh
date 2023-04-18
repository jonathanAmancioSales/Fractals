#!/bin/bash

file_cpp=Sierpisnki_Carpet_Box.cpp

g++ -O3 -std=c++11 $file_cpp
./a.out $1

rm a.out
###################
# Create data folder if it does not exist:
data_folder=data_files
test -d $data_folder || mkdir $data_folder

file_name=T_0$1
data_file=$data_folder/$file_name.txt
mv $file_name.txt $data_file
###################
# Generate images:
gnuplot -c Box.gnu $data_file

# Create image folder if it does not exist:
img_folder=images
test -d $img_folder || mkdir $img_folder

#ext=svg
ext=png
mv $data_file.$ext $img_folder/$file_name.$ext
