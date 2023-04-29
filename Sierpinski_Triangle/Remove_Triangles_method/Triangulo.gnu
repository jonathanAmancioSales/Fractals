reset
###################
set terminal wxt size 600,600 enhanced font 'Times-New-Roman,14'
###################
set macros
H=sqrt(3)/2.0
EPS = "set term eps color size 10,10*H"
PDF = "set term pdf color size 10,10*H"
SVG = "set term svg size 1000,1000*H dynamic enhanced mousing name 'Fractal' butt solid"
PNG = "set term png size 5000,5000*H notransparent"
###################
#file='T_1.txt'
file=ARG1
load file
###################
Save=1
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
set size square
###################
A=0.87
set xr[-0.6*A:0.6*A]
set yr[-0.335*A:0.665*A]
###################
L=1.0
a=L*sqrt(3)/6.0
h=L*sqrt(3)/2.0
set xr[-0.5*L:0.5*L]
dy=0.01
#set yr[-a:-a+L]
set yr[-a-dy:h-a+dy]
###################
p -L, L
###################
if(Save==0){pause -1 "Press Enter"}
#l 'Triangulo.gnu'
###################