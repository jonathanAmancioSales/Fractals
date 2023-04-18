#!/bin/bash
###################
#file_cpp=Koch_Cesaro_2019_1.0.cpp
file_cpp=Koch_Cesaro_2019_1.1.cpp
###################
g++ -O3 -std=c++11 $file_cpp
#./a.out $1 $2
Iteration=6
for angle in $(seq 0 1 180); do
	echo $angle
	./a.out $Iteration $angle
done
#########
rm a.out
###################
for i in $(ls T*.txt); do
	#gnuplot -c Vetores.gnu $i
	gnuplot -c Vetores_Box.gnu $i
done
###################
Pasta=PNG_0$Iteration
mkdir $Pasta
mv T_*.png $Pasta
###################
Pasta=Data_0$Iteration
mkdir $Pasta
mv T_*.txt $Pasta
###################