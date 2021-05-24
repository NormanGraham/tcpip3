

ubuff_regressiontest : ubuff_regressiontest.o ubuff.o
	g++ -o ubuff_regressiontest ubuff.o ubuff_regressiontest.o

ubuff_regressiontest.o : ubuff.cpp ubuff.h ubuff_regressiontest.cpp 
	g++ -c ubuff_regressiontest.cpp

ubuff.o : ubuff.cpp ubuff.h 
	g++ -o ubuff.o -c ubuff.cpp

clean :
	rm -f ubuff_regressiontest ubuff.o
