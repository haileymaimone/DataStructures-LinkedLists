//  PROGRAM 1:  Data Structures - CSC-328                                 //
//   Hailey Maimone                                                       //
//                                                                        //
//  PROGRAM SYNOPSIS:                                                     //
//			This program demonstrates a singly linked list set class.     //
//          It allows the user to create a linked list set                //
//			by choosing option 1 and inserting integers into a list.      //
//		    It also allows the user to search for an integer              //
//			in the list, delete a node from the list,                     //
//			display the current list, or quit.                            //
//                                                                        //
////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <string>
#include <sstream>
#include "set.h"

// GLOBAL MAIN FUNCTIONS
//   bool isInt(string s)
//       - DESCRIPTION:  check's to see if a string is an integer
//       - PRECONDITION:  a string to pass into the function
//       - POSTCONDITION:  returns true if the string contained an integer, returns false if it didn't
//
//   int getInt(string s)
//       - DESCRIPTION:  returns an integer to the user if the string contained one
//       - PRECONDITIONS:  a string to pass into the function
//       - POSTCONDITIONS:  if the string contains an integer then it is converted to an int and returned the user, otherwise false is returned

bool isInt(string s) { // function to check if a a string is an integer
	int num; // variable to hold the integer if it is contained in the string
	if (sscanf(s.c_str(), "%d", &num) == 1) { // if the string is an integer (when 1 is returned)
		return true; // then return true
	} else {
		return false; // else return false
	}
}

int getInt(string s) { // function to return an integer value if the passed in string was an integer
	stringstream num; // placeholder for converting the string to integer
	int val; // integer for the final value
	
	if (isInt(s)) { // if the string is an integer
		num << s; // passed into stringstream variable
		num >> val; // pass into integer variable
		return val; // return the integer value
	}
	return false; // if it doesn't contain an integer, return false
}

int main() {
	set LinkedList; // create set object named LinkedList
	
	string temp; // string placeholder variable
	bool running = true; // boolean variable for running the main menu
	int choice; // integer variable for the menu options
	string sval; // string variable for the value to search or insert
	int lval; // integer variable for the value to search or insert
	int rmv; // integer variable to hold the return value of the remove function
	
	while (running) { // this program will continue to run until the boolian variable 'running' is false
		cout << "-------------------------------------------------------------------------" << endl;
		cout << "Please choose an option from the menu below:" << endl; // once the program is running the user is presented with a neatly displayed list of options
		cout << "1. Insert" << endl;									// the user can either insert, search, remove or display the integers entered.
		cout << "2. Search" << endl;									// the user can also choose to exit the program
		cout << "3. Remove current node" << endl;
		cout << "4. Display list" << endl;
		cout << "5. Quit" << endl;
		cout << "-------------------------------------------------------------------------" << endl;
		
		cin >> temp; // prompt the user for a choice and save it in the temp string
		choice = getInt(temp); // check if the string is an integer
		cin.clear(); // clear buffer
		cin.ignore(10000, '\n');
		
		switch (choice) { // case statement for all of the options on the input menu
			case 1: // case 1: insert a value
				cout << "Please enter integer value you'd like to insert: ";
				cin >> sval; // prompt the user for an integer to insert
				lval = getInt(sval); // check to make sure it's an integer
				if (lval != false) { // if it is...
					cin.clear(); // clear the buffer
					cin.ignore(10000, '\n');
					cout << endl;
					LinkedList.insert(lval); // the value is stored in the linked list
				} else {
					cout << "" << endl;
					cout << "value must be an integer!" << endl; // if they didn't enter an integer
				}
				break;
			case 2: // case 2: search for a value
				cout << "Please enter integer value you'd like to search for: ";
				cin >> sval; // prompt the user for a value to search for
				lval = getInt(sval); // check to make sure it's an integer
				if (lval != false) { // if it is...
					cin.clear(); // clear the buffer
					cin.ignore(10000, '\n');
					cout << endl;
					if (LinkedList.search(lval)) { // if the value is found in the list
						cout << "Found value: " << lval << endl;
					} else {
						cout << "Value not found" << endl; // if the value is not contained in the list
					}
				} else {
					cout << "" << endl;
					cout << "value must be an integer!" << endl; // if the value to search for isn't an integer
				}
				break;
			case 3: // case 3: remove a node
				rmv = LinkedList.remove(); // save the return value of the remove function
				if (rmv != -1) { // if the function doesn't return false
					cout << "Removed node with value: " << rmv << endl; // remove the node and display it's value
				} else {
					cout << "List is empty" << endl; // else the list is empty
				}
				break;
			case 4:
				cout << "-------------------------------------------------------------------------" << endl;
				cout << LinkedList << endl; // print the linked list
				cout << "-------------------------------------------------------------------------" << endl;
				break;
			case 5:
				cout << "" << endl; // quit the program
				cout << "Exiting, goodbye." << endl;
				running = false;
				break;
			default:
				cout << "" << endl; // if the option is not an integer in the menu options range
				cout << "Your selection must be an integer between 1 and 5!" << endl;
		}
				
	}
    
	return 0;
}
