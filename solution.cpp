#include <iostream>
#include <fstream>

using namespace std;

int main(){

	//input file stream
	ifstream ifs;

	ifs.open("input.txt");
	ifs << "Writing...\n";
	ifs.close();


  return 0;

}
