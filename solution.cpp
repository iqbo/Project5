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

		//holds each node with their string data
		Graph(ifstream&, ifstream&);


};


int main(int argc, char** argv){

	//input file stream ()
	ifstream diceFile;
	ifstream wordFile;

	diceFile.open(argv[1]);
	wordFile.open(argv[2]);


	//checks if the word can be spelled

	Graph *g1 = new Graph(diceFile,wordFile);



	diceFile.close();
	wordFile.close();
	return 0;

}

Graph::Graph(ifstream &dice, ifstream &words){

	string temp = "";

	//creates Source Node
	Node source;
//	source.id = 0;
//	source.data = "";




	int counter = 1;

	set<int> sourceSet;
	nodes.insert(make_pair(0,sourceSet));

	//fill edges for source node
		while(dice >> temp){

		set<int> tempSet;

		//creates nodes in the graph for the dice
		nodes.insert(make_pair(counter,tempSet));









		nodes.find(0)->second.insert(counter);

		counter++;

		}


		//PRINTS OUT THE MAP TO TEST
	cout << "test print: " << endl;
	map<int,set<int> >::iterator ms;
	set<int>::iterator ss;
	for(ms = nodes.begin();ms!=nodes.end();++ms){

		cout << "key: " << ms->first << " , NodeIds: ";
		for(ss = ms->second.begin();ss!=ms->second.end();++ss){
		
			cout << *ss << " ";
		}
		cout << endl;
	}

}


