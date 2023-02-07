
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

//function to create data and put it into the data.csv file
void createData()
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

string keepGoing = "done";
string tempAnswer = "ahhhh";

do {

cout << "What would you like to do with the data? (create, done)" << endl;
cin >> tempAnswer;
if (tempAnswer == "done" || tempAnswer == "create"){
    keepGoing = tempAnswer;
    if (keepGoing == "create"){
        createData();
    }
} else{
    cout << "Try again.";
}

} while (keepGoing != "done");

}