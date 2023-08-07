wc -l < data/data.dat
grep d[ao]lor data/data.dat | wc -l
wc -w < data/data.dat
grep -o '\<mol' data/data.dat | wc -w
ls data/test_folder/*.txt | wc -l