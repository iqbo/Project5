/*Omar Iqbal
 *cs302 Project 5
 *
 */

#include <iostream>
#include <fstream>

using namespace std;

class Node {

	int src, dest;

};


class Graph {
	
	Node source, sink;

};

void checkWord(string);

int main(int argc, char** argv){

	//input file stream ()
	ifstream diceFile;
	ifstream wordFile;

	diceFile.open(argv[1]);
	wordFile.open(argv[2]);


	//checks if the word can be spelled
	
	checkWord("test");

	diceFile.close();
	wordFile.close();
  return 0;

}

void checkWord(string){


}

