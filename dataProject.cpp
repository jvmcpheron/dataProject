
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class MyData {       // The class
  public:             // Access specifier
    int myNum;        // Attribute (int variable)
    string myName; 
    string myFood;
};

//function to create data and put it into the data.csv file
void createData()
{
	// file pointer
	fstream fout;

	// opens an existing csv file or creates a new file.
	fout.open("data.csv", ios::out | ios::app);

    int numOfInputs;

    cout << "How many people's data would you like to add to the file?";
    cin >> numOfInputs;


	cout << "Enter their id number, name and favorite food:"
		<< " number name food" << endl;

	int i;
    int number;
    string food;
	string name;

	// Read the input
	for (i = 0; i < numOfInputs; i++) {

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

void findData(){

    //declaring vector


    vector<MyData> foodData;


    //open data
    ifstream myFile;
    myFile.open("data.csv");

    string line = "";

    //grabbing and parsing data
    while (getline(myFile, line)){

        //data variables
        int number;
        string name;
        string food;
        string tempString;


        //putting data into variables
        stringstream inputString(line);

        getline(inputString, tempString, ',');
        number = atoi(tempString.c_str());
        getline(inputString, name, ',');
        getline(inputString, food, ',');

        //putting variables into object
        MyData dataEntry;
        dataEntry.myNum = number;
        dataEntry.myName = name;
        dataEntry.myFood = food;

        //appending object to list
        foodData.push_back(dataEntry);


    }

    int searchNum = 0;

    //getting id number to look for in data
    cout << "What is the ID number of the data entry you are looking for?";
    cin >> searchNum;

    //searching for and outputting info from object
    for (int i = 0; i < foodData.size(); i++){
        if (foodData[i].myNum == searchNum){
            cout << "ID Number: " << searchNum <<endl;
            cout << "Name: " << foodData[i].myName << endl;
            cout << "Favorite Food: " << foodData[i].myFood << endl;
            break;
        } 
    }
}

int main (){

string keepGoing = "done";
string tempAnswer = "ahhhh";

do {

cout << "What would you like to do with the data? (create, read, find, done)" << endl;
cin >> tempAnswer;
if (tempAnswer == "done" || tempAnswer == "create" || tempAnswer == "read" || tempAnswer == "find"){
    keepGoing = tempAnswer;
    if (keepGoing == "create"){
        createData();
    }else if (keepGoing == "read"){
        readData();
    }else if (keepGoing == "find"){
        findData();
    }
} else{
    cout << "Try again.";
}

} while (keepGoing != "done");



}