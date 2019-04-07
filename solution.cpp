/*Omar Iqbal
 *cs302 Project 5
 *
 */

#include <iostream>
#include <fstream>
#include <set>
#include <map>

using namespace std;

class Node {

	public:
	// id of that node
	int id;
	string data;

};


class Graph {


	public:
		map<int,set<int> > nodes;
		Graph(ifstream, ifstream);


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

Graph::Graph(ifstream dice, ifstream words){


	string temp = "";

	//creates Source Node
	Node source;
	source.id = 0;
	source.data = "";

	

}

void checkWord(string){


}

