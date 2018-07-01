/*
 * Gurvir Sandhar
 * CS311
 *
 * This program receives input from a file called "input.txt"
 * and represents a DFA to determine floating point numbers.
 */

#include <iostream>
#include <fstream>
using namespace std;

int main(){

	//transition table
	int table[10][4] = { {2,3,1,9}, {9,4,1,9}, {9,3,1,9}, {9,9,5,9}, {9,9,5,6}, 
			     {9,9,5,6}, {7,9,8,9}, {9,9,8,9}, {9,9,8,9}, {9,9,9,9} };
	string line;	
	ifstream inputFile;

	inputFile.open("input.txt");	//open file
	if(!inputFile){
		cout << "File does not exist" << endl;
	}

	while(getline(inputFile, line)){	//loop through file and take in a string

		cout << line << ": ";
		int currentState = 0;		//start state

		for(int i = 0; i < line.length(); i++){		//logic for changing states based on current char
			if(line[i] == '+' || line[i] == '-'){
				currentState = table[currentState][0];
			}
			else if(line[i] == '.'){
				currentState = table[currentState][1];
			}
			else if(line[i] >= 48 && line[i] <= 57){
				currentState = table[currentState][2];
			}
			else if(line[i] == 'e' || line[i] == 'E'){
				currentState = table[currentState][3];
			}
			else{
				currentState = 9;	//dead state
			}	
		}
		if(currentState == 1 || currentState == 4 || currentState == 5 || currentState == 8){	//accept states
			cout << "Accept" << endl;
		}
		else{
			cout << "Reject" << endl;
		}
	}
	inputFile.close();
	
	return 0;
}
