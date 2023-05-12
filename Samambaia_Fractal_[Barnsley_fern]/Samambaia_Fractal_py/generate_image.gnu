reset
file=ARG1

set term png size 5000,3750 notransparent
file_out=file.'.png'; set output file_out
unset tics; unset border; unset key
set lmargin 0; set tmargin 0; set rmargin 0; set bmargin 0

stats file nooutput
# show variables all

print STATS_min_x, STATS_max_x, ' | ', STATS_min_y, STATS_max_y

dx=2*STATS_max_x; dy=0.03*STATS_max_y
#dx=0.4*STATS_max_x; dy=0.04*STATS_max_y  # fractal_tree

set xr[-dx + STATS_min_x:STATS_max_x + dx]
set yr[STATS_min_y:STATS_max_y + dy]

p file pt 7 ps 0.1 lc rgb 'forest-green'
