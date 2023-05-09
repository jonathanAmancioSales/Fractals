reset
set term png size 5000,3750 notransparent
file_out='Folha.png'; set output file_out
unset tics; unset border; unset key
set lmargin 0; set tmargin 0; set rmargin 0; set bmargin 0

set xr [-8.2:8.2]
set yr [-0:10.8]

p 'Folha_1.txt' pt 5 ps 0.3 lc 0,\
  'Folha_2.txt' pt 5 ps 0.1 lc 1,\
  'Folha_3.txt' pt 5 ps 0.1 lc 2,\
  'Folha_4.txt' pt 5 ps 0.1 lc 3
