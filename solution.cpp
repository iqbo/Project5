/*Omar Iqbal
 *cs302 Project 5
 * determines if a set of words
 * can be spelled with a set of dice
 *
 * (This is the Project that I have Redone)
 *
 */

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

class Node {

	public:
		// id of that node
		int id;

		//string data of the node
		string data;

		//outgoing edges
		set<int> dests;

		//id of the backedge node
		int backedge;

};

class Graph {

	public:
		map<int,Node > nodes;

		//holds each node with their string data
		Graph(ifstream&, ifstream&);
		int numOfDice;
		int numOfLetters;

		int BFS(int);


};


int main(int argc, char** argv){

	//input file stream ()
	ifstream diceFile;
	ifstream wordFile;

	diceFile.open(argv[1]);
	wordFile.open(argv[2]);

	Graph *g1;

	g1 = new Graph(diceFile,wordFile);

	delete g1;
	diceFile.close();
	wordFile.close();
	return 0;
}


Graph::Graph(ifstream &dice, ifstream &word){

	map<int,Node> initState;

	//holds dice data
	string diceTemp = "";

	//holds word
	string temp = "";


	//holds # of the Source's incoming edges
	int numOfIncomingEdges;

	//holds result of bfs
	int result;


	//nodes and dest iterators
	map<int,Node >::iterator ms;
	set<int>::iterator ss;

	//holds all dice characters
	//to make sure it has all the
	//required letters
	string diceChars = "";

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

		//inserts into diceChars
		for(int i = 0;i<diceTemp.size();i++)
			diceChars.push_back(diceTemp.at(i));

		//creates nodes in the graph for the dice
		nodes.insert(make_pair(counter,diceNode));

		nodes.find(0)->second.dests.insert(counter);

		counter++;

	}

	//sets number of dice
	numOfDice = counter;

	//ensures each word in the Words file is read
	int flag = 0;

	while(word >> temp){
		flag = 0;

		for(int i = 0;i<temp.size();i++){

			if(find(diceChars.begin(),diceChars.end(),temp.at(i)) == diceChars.end()){

				cout << "Cannot spell " << temp << endl;
				flag = 1;
				break;
			}

		}

		if(flag == 1)
			continue;

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

		//adds sink node
		Node sink;
		sink.id = numOfDice+numOfLetters;
		sink.data = "";

		nodes.insert(make_pair((sink.id),sink));

		for(int i = numOfDice;i<sink.id;i++){

			nodes.find(i)->second.dests.insert(sink.id);

		}

		/*		//PRINTS OUT THE MAP TO TEST
				cout << "\ntest print: " << endl;

				cout << "word: " << temp << endl;

				for(ms = nodes.begin();ms!=nodes.end();++ms){

				cout << "key: " << ms->first << " , NodeIds: ";
				for(ss = ms->second.dests.begin();ss!=ms->second.dests.end();++ss){

				cout << *ss << "(" << nodes.find(*ss)->second.data << ")";
				}
				cout << endl;
				}
				*/

		//holds initial state of nodemap
		initState = nodes;
		while(true){
			result = BFS(0);

			//if result ==-1, there are no more paths
			if(result == -1){

				numOfIncomingEdges = ((numOfDice -1)- nodes.begin()->second.dests.size());
				if(numOfIncomingEdges != numOfLetters){
					cout << "Cannot spell " << temp << endl;
				}
				else{

					//goes through sink backedges
					for(set<int>::iterator ss = nodes.find(nodes.size()-1)->second.dests.begin();ss!=nodes.find(nodes.size()-1)->second.dests.end();++ss){

						if(ss != nodes.find(nodes.size()-1)->second.dests.begin())
							cout << ","; 

						//points to first (and only) edge in the dests
						cout << (*(nodes.find(*ss)->second.dests.begin())-1);

					}

					cout << ": " << temp << endl;
				}
				break;
			}



		}

		//resets node map to initial state, so the dices
		//don't need to be re-read
		nodes = initState;

		//clears out word data from map

		//		clears all sets after sink
		for(ms = nodes.find(1);ms!=nodes.end();++ms){
			ms->second.dests.clear();
		}

		nodes.erase(nodes.find(numOfDice),nodes.end());

	}

}


/*BFS was implemented
 *using https://www.geeksforgeeks.org/breadth-first-search-or-bfs-for-a-graph/
 *as a model*/ 
int Graph::BFS(int source){
	vector<int> visited;

	//All nodes are unvisited
	visited.resize(nodes.size(),false);

	//BFS queue
	list<int> queue;

	visited.at(source) = true;
	queue.push_back(source);

	set<int>::iterator i;

	//checks if the sink has been added to the queue
	int sinkFound = 0;

	while(!queue.empty()){

		source = queue.front();

		//displays BFS traversal
		queue.pop_front();

		//gets destination nodes
		for(i = nodes.find(source)->second.dests.begin();i!=nodes.find(source)->second.dests.end();++i){

			if(!visited.at(*i) && (find(queue.begin(),queue.end(),*i) == queue.end())){

				visited.at(*i) = true;

				queue.push_back(*i);

				//should set the node's backedge
				nodes.find(*i)->second.backedge = source;

				//quits if the sink is added to the queue
				if(*i == nodes.find(nodes.size()-1)->second.id){
					sinkFound = 1;

					break;
				}


			}
		}

		//sink added to queue
		if(sinkFound==1)
			break;

	}


	if(sinkFound==0)
		return -1;


	//reverse edges down the path
	int counter = nodes.size()-1;

	while(true){

		int b = nodes.find(counter)->second.backedge;

		//create edge going back
		nodes.find(counter)->second.dests.insert(b);

		//delete edge coming towards this one
		nodes.find(b)->second.dests.erase(counter);

		counter = b;

		if(counter==0)
			break;

	}

	return 0;

}
