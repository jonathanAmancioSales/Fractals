#!/bin/bash
rm Folha.txt

g++ -O3 Samambaia_Fractal.cpp
./a.out

rm a.out

gnuplot Folha.txt
