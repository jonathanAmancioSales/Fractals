reset
###################
H=1
H=7.0/8.0
set terminal wxt size 600,600*H enhanced font 'Times-New-Roman,14'
###################
set macros
EPS = "set term eps color size 10,10*H"
PDF = "set term pdf color size 10,10*H"
SVG = "set term svg size 1000,1000*H dynamic enhanced mousing name 'Fractal' butt solid"
SVG1 = "set term svg size 1000,1000*H dynamic enhanced mousing butt solid"
PNG = "set term png size 1000,1000*H notransparent"
###################
A="set arrow from"
B="nohead lw 0.2 lt 3 lc 'black'"
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
Fundo=1
if(Fundo==1){
set object 1 rect from screen 0,0 to screen 1,1
set object 1 fc rgb "#fefbd8" fillstyle solid noborder
#set object 1 fc rgb "yellow" fillstyle pattern 1 noborder
}
###################
angle=ARG2; s1='Angle='; s2='º'
set label s1.angle.s2 at 2.01,2.8 front font 'Times,28'
set label "Jonathan Sales" at 2.09,-2.9 front font 'Times-Italic,24'
###################
unset tics; unset border; unset key
###################
set lmargin 0; set tmargin 0; set rmargin 0; set bmargin 0
###################
fx=1.01; fy=1.01;
L=3; set xr[-fx*L:fx*L]; set yr[-fy*L:fy*L]; set size square
###################
p -5*L, 5*L
###################
if(Save==0){pause -1 "Press Enter"}
#gnuplot -c Vetores.gnu T_01.txt
#l 'Vetores.gnu'
###################