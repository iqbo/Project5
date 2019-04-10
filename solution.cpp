/*Omar Iqbal
 *cs302 Project 5
 *
 */

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <vector>

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



		void checkWord();
		void BFS(int);


};


int main(int argc, char** argv){

	//input file stream ()
	ifstream diceFile;
	ifstream wordFile;

	diceFile.open(argv[1]);
	wordFile.open(argv[2]);

	Graph *g1;


	g1 = new Graph(diceFile,wordFile);

	diceFile.close();
	wordFile.close();
	return 0;

}


Graph::Graph(ifstream &dice, ifstream &word){


	//holds dice data
	string diceTemp = "";

	//holds word
	string temp = "";


	//nodes and dest iterators
	map<int,Node >::iterator ms;
	set<int>::iterator ss;


	//creates Source Node
	Node source;
	source.id = 0;
	source.data = "";

	set<int> sourceSet;

	source.dests = sourceSet;

	int counter = 1;

	nodes.insert(make_pair(0,source));

	//fill edges for source node
	while(dice >> diceTemp){

		Node diceNode;
		diceNode.id = counter;
		diceNode.data = diceTemp;

		//creates nodes in the graph for the dice
		nodes.insert(make_pair(counter,diceNode));

		nodes.find(0)->second.dests.insert(counter);

		counter++;

	}

	//sets number of dice
	numOfDice = counter;


	while(word >> temp){

		//resets counter to be used for numOfLetters
		counter = 0;

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

						n.id = (nodes.size()+j);
						n.data = temp.at(j);

						//inserts new node into map
						nodes.insert(make_pair(numOfDice+j,n));
						counter++;	

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
		//	cout << "# of letters in word: " << numOfLetters << endl;

		//adds sink node
		Node sink;
		sink.id = numOfDice+numOfLetters;
		sink.data = "";

		nodes.insert(make_pair((sink.id),sink));

		//cout << "current size of map: " << nodes.size() << endl;

		for(int i = numOfDice;i<sink.id;i++){

			//		cout << "sink.id currently = " << sink.id << endl;
			//		cout << "# of letters: " << numOfLetters << endl;


			nodes.find(i)->second.dests.insert(sink.id);

		}

		//PRINTS OUT THE MAP TO TEST
		cout << "\ntest print: " << endl;

		cout << "word: " << temp << endl;

		for(ms = nodes.begin();ms!=nodes.end();++ms){

			cout << "key: " << ms->first << " , NodeIds: ";
			for(ss = ms->second.dests.begin();ss!=ms->second.dests.end();++ss){

				cout << *ss << "(" << nodes.find(*ss)->second.data << ") ";
			}
			cout << endl;
		}


		BFS(0);

		//clears out word data from map

		//		clears all sets after sink
		for(ms = nodes.find(1);ms!=nodes.end();++ms){
			ms->second.dests.clear();
		}

		nodes.erase(nodes.find(numOfDice),nodes.end());

	}


}

void Graph::checkWord(){

	set<int>::iterator ss;

	list<int> queue;
	list<int> backEdge;
	list<int> visited;



	//load each neighbor to the queue
	if(nodes.find(0)->second.dests.size()>0){

		//for each node in dests for the source node
		for(ss = nodes.find(0)->second.dests.begin();ss!=nodes.find(0)->second.dests.end();++ss){

			//push them on to the queue
			queue.push_back(*ss);			
		


		}



	}

}

void Graph::BFS(int source){

	vector<int> visited;

	//All nodes are unvisited
	visited.resize(nodes.size(),false);

	//BFS queue
	list<int> queue;

	visited.at(source) = true;
	queue.push_back(source);

	set<int>::iterator i;

	while(!queue.empty()){

		source = queue.front();

		cout << source << " ";

		queue.pop_front();


		//gets destination nodes
		for(i = nodes.find(source)->second.dests.begin();i!=nodes.find(source)->second.dests.end();++i){

			if(!visited.at(*i)){

				visited.at(*i) = true;
				queue.push_back(*i);
			}

		}


	}


}
