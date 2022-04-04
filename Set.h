// *************************
//  CLASS PROVIDED:  Set
// *************************
//
// CONSTRUCTOR:  Set()
//  - DESCRIPTION:  initializes all variables in set
//  - PRECONDITIONS:  N/A
//  - POSTCONDITIONS:  initializes head, current, temp, and size to zero
//
// DESTRUCTOR:  ~Set()
//  - DESCRIPTION:  frees allocated memory before removing an object
//  - PRECONDITIONS:  program ends or object is deleted
//  - POSTCONDITIONS:  memory is freed before object is deleted
//
// CONSTANT MEMBER FUNCTIONS FOR THE SET CLASS
//   void insert(int value)
//       - DESCRIPTION:  inserts a value into the linked list
//       - PRECONDITION:  N/A
//       - POSTCONDITION:  value is added to linked list, current points to the new node, size of list is increased OR value is not inserted because it already exists in the set
//
//   bool search(int value)
//       - DESCRIPTION:  function searches the list for the integer value the user inputs
//       - PRECONDITIONS:  N/A
//       - POSTCONDITIONS:  if the value is found, true is returned, if the value is not found, false is returned
//
//   int remove()
//       - DESCRIPTION:  remove's the current node from the list if the list is not empty and displays it to the user
//       - PRECONDITIONS:  N/A
//       - POSTCONDITIONS:  if the linked list is empty, false is returned, otherwise, the value being pointed to is removed from the list and size is decreased
//                          and the removed value is displayed to the user
//
//   friend ostream& operator << (ostream&, const set&)
//       - DESCRIPTION:  overload the output operator, <<
//       - PRECONDITIONS:  N/A
//       - POSTCONDITIONS:  allows linked list to be printed to screen; will print "linked list is empty" if it is empty

#ifndef SET_H
#define SET_H

using namespace std;

// Create a Node struct with the integer variable 'value' and Node pointer 'next'
struct Node {
    int value;
    Node *next;
};

// create class set with private data Node pointers, 'head', 'current', and 'temp'. 
// private data also includes integer variable 'size'.
class set {
	private:
		Node *head;
		Node *current;
		Node *temp;
        int size;
		
	public:
		set(); // class set constructor prototype
        ~set(); // class set destructor prototype
		void insert(int value); // insert function prototype
		bool search(int value); // search function prototype
		int remove(); // remove function prototype
        friend ostream& operator << (ostream&, const set&); //overloaded operator << proptotype
};


#endif
