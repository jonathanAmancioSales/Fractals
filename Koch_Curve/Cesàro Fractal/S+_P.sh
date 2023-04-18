#!/bin/bash
###################
file_cpp=Koch_Cesaro_2019_1.1_Poligono.cpp
###################
g++ -O3 -std=c++11 $file_cpp
Iteration=5
angle=60
for P in $(seq 3 1 36); do
	echo $P
	file=$(./a.out $Iteration $angle $P)
	gnuplot -c Vetores_Box.gnu $file
done
#########
rm a.out
###################
Pasta=PNG_0$Iteration
mkdir $Pasta
mv T_*.png $Pasta
###################
Pasta=Data_0$Iteration
mkdir $Pasta
mv T_*.txt $Pasta
###################