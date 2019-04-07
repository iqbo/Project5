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
		set<int> dests;

};


class Graph {


	public:
		map<int,Node > nodes;

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
	source.id = 0;
	source.data = "";

	set<int> sourceSet;

	source.dests = sourceSet;

	int counter = 1;

	nodes.insert(make_pair(0,source));

	//fill edges for source node
	while(dice >> temp){


		Node diceNode;
		diceNode.id = counter;
		diceNode.data = temp;

		cout << "temp is being stored as: " << diceNode.data << endl;


		//creates nodes in the graph for the dice
		nodes.insert(make_pair(counter,diceNode));









		nodes.find(0)->second.dests.insert(counter);

		counter++;

	}


	//PRINTS OUT THE MAP TO TEST
	cout << "test print: " << endl;
	map<int,Node >::iterator ms;
	set<int>::iterator ss;
	for(ms = nodes.begin();ms!=nodes.end();++ms){

		cout << "key: " << ms->first << " , NodeIds: ";
		for(ss = ms->second.dests.begin();ss!=ms->second.dests.end();++ss){

			cout << *ss << "(" << nodes.find(*ss)->second.data << ") ";
		}
		cout << endl;
	}

}


