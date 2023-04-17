#!/bin/bash

cpp_script=Sierpisnki_Carpet_Matrix.cpp

#N=6
N=$1
let pN=3**N
###################
sed -i '/#define n_iter/c\#define n_iter '$N'' $cpp_script
# sed -i '/#define N/c\#define N '$((3**$N))'' $cpp_script
sed -i '/#define N/c\#define N '$pN'' $cpp_script
###################
data_folder=data_files
# Create data folder if it does not exist:
test -d $data_folder || mkdir $data_folder
data_file=$data_folder/M_0$N.dat
echo $data_file
###################
# Compile and execute:
g++ $cpp_script
./a.out > $data_file

rm a.out
###################
# Generate images:
gnu_script=matrix+.gnu
sed -i '/T=/c\T=3**'$N'-0.5' $gnu_script
sed -i '/file=/c\file="'$data_file'"' $gnu_script
gnuplot $gnu_script

img_folder=images
# Create image folder if it does not exist:
test -d $img_folder || mkdir $img_folder
#ext=svg
ext=png
mv M.$ext $img_folder/M_0$N.$ext
