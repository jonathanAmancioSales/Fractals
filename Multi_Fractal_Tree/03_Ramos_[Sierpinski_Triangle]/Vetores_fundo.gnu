reset
###################
set terminal wxt size 600,600 enhanced font 'Times-New-Roman,14'
###################
set macros
H=sqrt(3)/2.0
EPS = "set term eps color size 10,10*H"
PDF = "set term pdf color size 10,10*H"
SVG = "set term svg size 1000,1000*H dynamic enhanced mousing name 'Fractal' butt solid"
SVG1 = "set term svg size 1000,1000*H dynamic enhanced mousing butt solid"
PNG = "set term png size 1000,1000*H notransparent"
###################
A="set arrow from"
B="nohead lw 0.6 lt 3 lc 'black' front"
#@A 0,0 to 0,0.5 @B
###################
#file='T_01.txt'
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
L=1
a=L*sqrt(3)/6.0
h=L*sqrt(3)/2.0
#set xr[-0.5*L:0.5*L]
#set yr[-a:h-a]
#set yr[-a:-a+L]
###################
#Angle ate 120
set xr[-0.55*L:0.55*L]
set yr[-1.5*a:h-a]
###################
#Angle ate 180
#set xr[-0.7*L:0.7*L]
#set yr[-2*a:h-a]
###################
set object 1 rect from screen 0,0 to screen 1,1
set object 1 fc rgb "yellow" fillstyle pattern 1 noborder
#set object 1 fc rgb "#fefbd8" fillstyle solid noborder
###################
p -L, 1.5*L
###################
if(Save==0){pause -1 "Press Enter"}
#gnuplot -c Vetores.gnu T_01.txt
#l 'Vetores.gnu'
###################