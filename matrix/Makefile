# Change these
cxxtestpath = /info/cprog11/cxxtest/
testcode    = MatrixTest.h

testcode.cpp: $(testcode)
	python $(cxxtestpath)cxxtestgen.py --error-printer -o testcode.cpp $(testcode)

runtest0%: testcode.cpp
	g++ -I $(cxxtestpath) -o runtest0$* testcode.cpp Matrix0$*.o
	./runtest0$*
	rm runtest*

clean:
	touch runtest01 testcode.cpp
	rm runtest0* testcode.cpp

