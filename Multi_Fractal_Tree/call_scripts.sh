#!/bin/bash
###################
file_cpp=Multi_Fractal_Tree.cpp

g++ -O3 -std=c++11 $file_cpp
#########
op=1
if [ "$op" = 1 ]; then
 for angle in $(seq 0 1 180); do
	echo $angle
	./a.out $1 $angle $2
 done
else
  #{Iteracao, Angulo e Numero de ramos};
  ./a.out $1 $2 $3
fi
#########
rm a.out
###################
for i in $(ls T*.txt); do
	gnuplot -c Vetores_Circles_fundo.gnu $i
done
###################
g=1
if [ "$g" = 1 ]; then
  mkdir PNG; mv T_*.png PNG
  mkdir Data
  mv T_*.txt Data
fi
###################