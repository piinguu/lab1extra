make testcode.cpp

for i in 1 2 3 4 5 6 7 8 9
do
	make runtest0$i > testlog0$i.txt
	if grep -q .OK! testlog0$i.txt; then
	    echo "test case $i is OK"
    else
    	echo "test case $i failed"
	fi
done
