reset
###################
H=5.0/8.0
H=sqrt(3)/2.0
H=sqrt(3)/4.0	#City
set terminal wxt size 800,800*H enhanced font 'Times-New-Roman,14'
###################
set macros
EPS = "set term eps color size 10,10*H"
PDF = "set term pdf color size 10,10*H"
SVG = "set term svg size 1000,1000*H dynamic enhanced mousing name 'Fractal' butt solid"
SVG1 = "set term svg size 1000,1000*H dynamic enhanced mousing butt solid"
PNG = "set term png size 1000,1000*H notransparent"
###################
A="set arrow from"
B="nohead lw 1.4 lt 3 lc 'blue'"
#@A 0,0 to 0,0.5 @B
###################
#file='T_01.txt'
file=ARG1
load file
###################
Save=0
if(Save==1){
#@EPS; ext='.eps'
#@PDF; ext='.pdf'
@PNG; ext='.png'
#@SVG; ext='.svg'
file_out=file.ext; set output file_out
}
###################
unset tics; unset border; unset key
###################
set lmargin 0; set tmargin 0; set rmargin 0; set bmargin 0
###################
#set size square
###################
L=1
set xr[-0.1*L:3.1*L]
set yr[-0.1*L:1.6*L]
set yr[-0.01*L:0.9*L]	#City
###################
p -5*L, 5*L
###################
if(Save==0){pause -1 "Press Enter"}
#gnuplot -c Vetores.gnu T_01.txt
#l 'Vetores.gnu'
###################