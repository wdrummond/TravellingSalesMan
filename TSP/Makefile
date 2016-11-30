all: TSP

test: TSP
	./TSP < graph005.txt

TSP.o: TSP.cpp
	g++ -c TSP.cpp

TSP: TSP.o
	g++ -o  TSP TSP.o

clean:
		-rm -f *.o *~

spotless: clean
		-rm -f TSP