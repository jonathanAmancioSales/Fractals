reset
set term wxt size 1000,1000
###################
# SVG
#set terminal svg enhanced size 600,600 font 'Times-Italic,12'
#set output "M.svg"
###################
# PNG
set terminal png nocrop enhanced size 3000,3000 font 'Times-Italic,12'
set output "M.png"
###################
T=3**7-0.5
set xtics -0.5,1,T
set ytics -0.5,1,T
#set xr[-0.5:2.5]
#set yr[-0.5:2.5]
###################
set grid front lc rgb "black" lt 1 lw 1
unset tics
unset border
unset key
unset colorbox
#set cbtics 0.1
#set cbtics scale 0
set size square
#set size 0.5,1
###################
# Remover as margens:
set lmargin 0
set tmargin 0
set rmargin 0
set bmargin 0
###################
#set object 1 rect from screen 0,0 to screen 1,1
#set object 1 fc rgb "#fefbd8" fillstyle solid
###################
#set palette defined (0 "black", 1 "red")
set palette defined (0 "black", 1 "white")
###################
file="data_files/M_07.dat"
###################
plot file matrix with image #pixels
###################
#set hidden3d
#splot file matrix w pm3d
###################
#pause -1"Press Enter"
###################
# l 'matrix+.gnu' # to run
###################
