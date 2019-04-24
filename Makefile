all: worddice

worddice: worddice.cpp
	g++ -g worddice.cpp -o worddice
clean:
	rm worddice
