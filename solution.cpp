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

int main(){

	//input file stream ()
	ifstream diceFile;
	ifstream wordFile;

	diceFile.open("diceInput.txt");
	wordFile.open("wordInput.txt");

	diceFile.close();
	wordFile.close();

	//checks if the word can be spelled
	
	checkWord("test");

  return 0;

}

void checkWord(string){


}

