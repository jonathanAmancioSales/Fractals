#!/bin/bash
#############################
min=1
max=6
for ((i=$min; i<=$max; i=i+1));
do
	#########################
	echo "$i"
	bash call_scripts.sh $i
	#########################
done
#############################
#Pasta1=Data
#mkdir $Pasta2
#mv *.dat $Pasta
#############################
# Pasta2=IMG-
# mkdir $Pasta2
# mv *.svg $Pasta2
#############################
#rm *~
#############################
