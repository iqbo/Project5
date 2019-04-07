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

	//src = name of that node
	//dest = destination node
	int src, dest;

};


class Graph {


	public:
		map<int,set<Node> > nodes;
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

	//creates Source Node
}

void checkWord(string){


}

