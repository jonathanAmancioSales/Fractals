reset
set term wxt size 600,600
###################
#set terminal svg enhanced size 600,600 font 'Times-Italic,12'
#set output "Box.svg"
###################
set terminal png nocrop enhanced size 3000,3000 font 'Times-Italic,12'
set output "Box.png"
###################
set macros
Margens="set lmargin 0; set rmargin 0; set bmargin 0; set tmargin 0;"
Margens_Screen="set lmargin screen 0; set rmargin screen 1; set bmargin screen 0; set tmargin screen 1;"
###################
unset key
unset border
unset tics
set size square
#@Margens
###################
#set object 1 rect from screen 0,0 to screen 1,1 fc rgb "#fefbd8" fs solid
###################
A="set object"
B="rectangle from"
C="fc rgb 'black' fs pattern 3 noborder"
#@A 1 @B -0.5,-0.5 to 0.5,0.5 @C
###################
file="Box_010.txt"
load file
###################
p -10
###################
#pause -1"Press Enter"
###################
