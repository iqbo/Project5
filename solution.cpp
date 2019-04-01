#include <iostream>
#include <fstream>

using namespace std;

int main(){

	//input file stream
	ifstream ifs;

	ifs.open("input.txt");
	
	string txt = "";

	while(ifs >> txt)
		cout << txt << " ";


	ifs.close();


  return 0;

}
