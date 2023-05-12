#!/bin/bash
###################
file_py=samambaia_fractal.py

echo 'Generate data file...'
python3 $file_py $1 $2
###################
data_file=fern_data_$2_$1.txt

# Generate image:
echo 'Generate image...'
gnuplot -c generate_image.gnu $data_file
###################
# bash call_scripts.sh 1000000 barnsley
#barnsley, modified_barnsley, culcita, cyclosorus, fractal_tree
