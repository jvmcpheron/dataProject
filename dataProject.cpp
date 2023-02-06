
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


void create()
{
	// file pointer
	fstream fout;

	// opens an existing csv file or creates a new file.
	fout.open("data.csv", ios::out | ios::app);

	cout << "Enter their name and their favorite food:"
		<< " name food" << endl;

	int i;
    string food;
	string name;

	// Read the input
	for (i = 0; i < 3; i++) {

		cin >> name
			>> food;

		// Insert the data to file
		fout << name << ", "
			<< food << "\n";
	}
}



int main (){

create();

}