#!/bin/bash
###################
file_cpp=Triangulo_Pascal.cpp

div=$1
D=$2
sed -i '/#define D /c\#define D '$D'' $file_cpp
sed -i '/#define div /c\#define div '$div'' $file_cpp

###################
g++ -O3 -std=c++11 $file_cpp
./a.out

rm a.out

###################
# Generate images:
for i in $(ls Pontos*.txt); do
  gnuplot -c generate_image.gnu $i
done

###################
# Mover dados e imagens para pastas:
move=0

if [ $move -eq 1 ]; then
  ###################
  # Create data folder if it does not exist:
  data_folder=data_files
  test -d $data_folder || mkdir $data_folder

  mv Pontos*.txt $data_folder
  ###################
  # Create image folder if it does not exist:
  image_folder=images
  test -d $image_folder || mkdir $image_folder

  mv Pontos*.png $image_folder
  ###################
fi

###################
#bash call_scripts.sh 3 127
###################
