reset
###################
set terminal wxt size 600,600 enhanced font 'Times-New-Roman,14'
###################
set macros
H=sqrt(3)/2.0
EPS = "set term eps color size 10,10*H"
PDF = "set term pdf color size 10,10*H"
SVG = "set term svg size 2000,2000*H dynamic enhanced mousing name 'Fractal' butt solid"
PNG = "set term png size 3000,3000*H notransparent"
###################
#file='Pontos.txt'
file=ARG1
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
stats file nooutput
# show variables all
###################
#set xr[-2:542]; set yr[-257:2]
dy=2
print STATS_min_y, STATS_max_y
set yr[-dy + STATS_min_y:STATS_max_y + dy]
###################
#p file pt 9 ps 1.6 lc rgb 'black'
#p file pt 9 ps 0.86 lc rgb 'black'
p file pt 9 ps 0.3 lc rgb 'black'
###################
if(Save==0){pause -1 "Press Enter"}
###################