make testcode.cpp

for i in `seq 1 9`
do
	make runtest0$i > testlog0$i.txt
	if grep -q .OK! testlog0$i.txt; then
	    echo "test case $i is OK"
    else
    	echo "test case $i failed"
	fi
done
