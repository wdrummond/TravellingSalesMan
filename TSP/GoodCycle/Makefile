all: TSP-GOOD

test: TSP-GOOD
	./TSP-GOOD < graph-1000-03.txt

TSP.o: TSP.cpp
	g++ -c TSP.cpp

TSP-GOOD: TSP.o
	g++ -o  TSP-GOOD TSP.o

clean:
		-rm -f *.o *~

spotless: clean
		-rm -f TSP-GOOD