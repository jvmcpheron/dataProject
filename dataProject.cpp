
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

	cout << "Enter their id number, name and favorite food:"
		<< " number name food" << endl;

	int i;
    int number;
    string food;
	string name;

	// Read the input
	for (i = 0; i < 3; i++) {

		cin >> number
            >> name
			>> food;

		// Insert the data to file
		fout << number << ", "
            << name << ", "
			<< food << "\n";
	}
}

//function to read specific data
void readData(){

    ifstream myFile;
    myFile.open("data.csv");

    while (myFile.good()){
        string line;
        getline(myFile, line, ',');
        cout << line << endl;
    }


}

int main (){

string keepGoing = "done";
string tempAnswer = "ahhhh";

do {

cout << "What would you like to do with the data? (create, done, read)" << endl;
cin >> tempAnswer;
if (tempAnswer == "done" || tempAnswer == "create" || tempAnswer == "read"){
    keepGoing = tempAnswer;
    if (keepGoing == "create"){
        createData();
    }else if (keepGoing == "read"){
        readData();
    }
} else{
    cout << "Try again.";
}

} while (keepGoing != "done");



}