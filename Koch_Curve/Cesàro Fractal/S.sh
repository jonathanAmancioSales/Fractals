#!/bin/bash
###################
#file_cpp=Koch_Cesaro_2019_1.0.cpp
file_cpp=Koch_Cesaro_2019_1.1.cpp
###################
g++ -O3 -std=c++11 $file_cpp
./a.out $1 $2
#########
rm a.out
###################
#gnuplot -c Vetores.gnu 'T_0'$1'.txt'
for i in $(ls T*.txt); do
	#gnuplot -c Vetores.gnu $i
	gnuplot -c Vetores_Box.gnu $i
	#gnuplot -c Vetores_fundo.gnu $i
done
###################
rm T*.txt
###################