#include <iostream>
#include <fstream>

using namespace std;

int main(){

	//input file stream ()
	ifstream diceFile;
	ifstream wordFile;

	diceFile.open("diceInput.txt");
	wordFile.open("wordInput.txt");


	diceFile.close();
	wordFile.close();

  return 0;

}
