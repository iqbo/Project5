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
	int numOfDice;
	int numOfLetters;
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

	//nodes and dest iterators
	map<int,Node >::iterator ms;
	set<int>::iterator ss;

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

		//creates nodes in the graph for the dice
		nodes.insert(make_pair(counter,diceNode));

		nodes.find(0)->second.dests.insert(counter);

		counter++;

	}

	//sets number of dice
	numOfDice = counter;

	//resets counter to be used for numOfLetters
	counter = 0;



	//temp = word to look through
	temp = "RAGE";
	//adds dice to letter edges

	//iterates through each dice node
	for(ss = nodes.find(0)->second.dests.begin();ss!=nodes.find(0)->second.dests.end();++ss){

		//iterates through each character in a dice node
		for(int i = 0;i<nodes.find(*ss)->second.data.size();i++){


			//iterates through character in a word
			for(int j = 0;j<temp.size();j++){

				//creates temporary node to become a letter node
				Node n;


				//checks to see if letter node is in the map
				if(nodes.find(numOfDice+j) == nodes.end()){

					cout << "nodes.find(" << numOfDice+j << ")"  << endl;

					cout << "j is " << j << endl;
					cout << "adding node to index " << nodes.size()+j << endl;

					n.id = (nodes.size()+j);
					n.data = temp.at(j);

					//inserts new node into map
					nodes.insert(make_pair(numOfDice+j,n));
					counter++;	

					//sets letter node dest to sink node


				}

				if(nodes.find(*ss)->second.data.at(i) == temp.at(j)){
				
					//inserts new node destination set
					nodes.find(*ss)->second.dests.insert(numOfDice+j);

				}

			}

		}


	}

		//sets number of letters
		numOfLetters = counter;
		cout << "# of letters in word: " << numOfLetters << endl;

//adds sink node
	Node sink;
	sink.id = numOfDice+numOfLetters;
	sink.data = "";

	nodes.insert(make_pair((sink.id),sink));



	for(int i = numOfDice;i<sink.id;i++){

		nodes.find(i)->second.dests.insert(sink.id);

	}



	//PRINTS OUT THE MAP TO TEST
	cout << "test print: " << endl;
	for(ms = nodes.begin();ms!=nodes.end();++ms){

		cout << "key: " << ms->first << " , NodeIds: ";
		for(ss = ms->second.dests.begin();ss!=ms->second.dests.end();++ss){

			cout << *ss << "(" << nodes.find(*ss)->second.data << ") ";
		}
		cout << endl;
	}

}


