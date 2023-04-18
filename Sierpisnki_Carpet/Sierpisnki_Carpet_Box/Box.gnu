reset
###################
set terminal wxt size 600,600 enhanced font 'Times-New-Roman,14'
###################
set macros
EPS = "set term eps color size 10,10"
PDF = "set term pdf color size 10,10"
SVG = "set term svg size 1000,1000 dynamic enhanced mousing name 'Fractal' butt solid"
PNG = "set term png size 5000,5000 notransparent"
###################
A="set object rectangle center"
B="size"
#C="fc rgb 'black' fs pattern 3 noborder"
C="fc rgb 'black' fillstyle solid noborder"
#@A x,y @B L,L @C
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
L=3.0
set xr[-0.5*L:0.5*L]
set yr[-0.5*L:0.5*L]
###################
p -2*L, 2*L
###################
if(Save==0){pause -1 "Press Enter"}
#l 'Box.gnu'
###################