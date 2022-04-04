#include <iostream>
#include <iomanip>
#include "set.h"
#include <tgmath.h>

using namespace std;

set::set() { // set constructor initializes all of the variables
	head = 0;
	current = 0;
	temp = 0;
	size = 0;
}

set::~set() { // set destructor
	while (size != 0) { // delete and free memory from each node in the list
		remove();
	}
    
}

void set::insert(int value) { 
    if (search(value)) { // insert function an integer 'value' is passed into this function from the user keyboard
        cout << "That value already exists in the set" << endl; // if that integer has already been entered by user the progrom will print this error message
    } else {
    	size++; // if the integer isnt already in the linked list, increase the size since we will be adding it
    	
        Node *newNode = new Node; // a new node is created
        newNode->value = value; // set new node's value to the value entered by the user
        if (!head) { 
            head = newNode; // if there is no head node then the new node will be head
            newNode->next = 0; // set the next node to null
            current = head; // point current to head
		} else if (!current->next) { // if there current->next is null or simply were at the tail node
        	current->next = newNode; // set current's next to the new node
        	newNode->next = 0; // set the new node's next to null
        	current = newNode; // set current to the new node
		} else {
        	// in this case we are inserting a node that isn't at the head or at the tail
        	temp = current->next; // set temp to hold current next's value
        	current->next = newNode; // set current's next to the new node
        	newNode->next = temp; // set new node's next to temp (to keep the linking of the nodes after current intact)
        	current = newNode; // set current to the new node
		}
    }
    
}

bool set::search(int value) { // search function an integer 'value' is passed into the function and a boolean is returned
	if (!head) return false; // if there isn't a head node, linked list is empty and return false
	
	temp = head; // set temp to head
	
	while (temp) { // while temp isn't null
        if (temp->value == value) { // if temp's value is equal to the value were searching for...
            current = temp; // set current to temp
            return true; // return true because we found the value
        }
    	temp = temp->next; // continue to traverse the list attempting to find the value
	}
	return false; // if the value is not in the list then return false
	
}

int set::remove() { // the remove function does not have information passed in but will return an integer or false (if the list is empty)
    if (!head) return -1; // if the list is empty return -1
    
    int nodeVal = current->value; // integer to hold the to-be-deleted node's value
    size--; // decrement size since we are deleting a node
    
    if (head == current) { // if the head node and current node are the same
    	temp = head; // set temp to head
    	if (head->next != 0) { // if the next node is not null
    		temp = head->next; // set temp to head's next
    		delete head; // delete head node
    		head = temp; // set head to head's next, or temp
		} else {
			delete head; // if only one node exists in the list then delete it
			head = 0; // set head to null
		}
        current = head; // set current to head
        return nodeVal; // return the value that was removed
    }
    
    temp = head; // set temp to head
    
    while (temp->next != current) { // while temp's next is not equal to current (to make sure it lands on the node BEFORE the one we want to remove)
        temp = temp->next; // traverse the list
    }
    
    if (!current->next) { // if current's next is null (meaning will be removing the tail node)
        temp->next = 0; // set temp's next to null
        delete current; // delete current
        current = head; // set current to head
    } else { // else we are removing a node that isn't the head node, node after head node, or the tail node
        temp->next = current->next; // set temp's next to current's next
        delete current; // delete current
        current = head; // set current to head
    }  
    return nodeVal; // return the deleted node's value
}

ostream& operator << (ostream &output, const set &s1) { // overloaded operator << takes ostream output and a set type
	int linebreak = 0; // linebreak integer used for to determine when to end a line, intialized to 0
	if (!s1.head) { // if the set doesn't have a head node...
    	output << "LinkedList is empty" << endl; // then the linked list is empty
	} else {
		Node *print = new Node; // traversal pointer for printing the list
    	print = s1.head; // set print to head

    	while (print) { // while the node exists
    		linebreak++; // increment the linebreak integer
        	output << print->value;// print the value
        	
        	if (linebreak % 4 == 0) {
        		output << endl; // if the linebreak integer is divisible by 4, end the line. This makes it so there are only 4 values per line
			} else {
				output << setw(10); // else set width to 10
			}
        	print = print->next; // traverse the list until we break out of it by print being null
    	}
    	
	}
    return output; // return the output
    
}


