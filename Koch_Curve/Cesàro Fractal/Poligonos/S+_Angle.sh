#!/bin/bash
###################
file_cpp=Koch_Cesaro_2019_1.1_Poligono.cpp
###################
g++ -O3 -std=c++11 $file_cpp
Iteration=5
P=6
for angle in $(seq 0 2 360); do
	echo $angle
	file=$(./a.out $Iteration $angle $P)
	#((angle=90-angle))
	angle=`echo "90-$angle * 0.5" | bc`
	gnuplot -c Vetores_Box_Angle.gnu $file $angle
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