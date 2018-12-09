#ifndef llist_h
#define llist_h

// =======================================================
// HW#: HW11 llist
// Your name: Michael Tobin
// Compiler:  g++ 
// File type: llist header file 
//=======================================================

#include "elem.h"


// A list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};

//---------------------------------------------------------

class llist
{
protected:
	Node *Front;       // pointer to the front node
  	Node *Rear;        // pointer to the rear node
 	int  Count;        // counter for the number of nodes
  
public:

	// Exception handling classes 
  	class Underflow{};	 // Thrown when the an operation won't work because the list is empty
  	class OutOfRange{};  // thrown when the specified Node is out of range

 	 llist ();     // constructor to create a list object
 	 ~llist();     // destructor to destroy all nodes
  
	// PURPOSE: Checks to see if the list is empty
	// PARAMETER: None
	bool isEmpty();
    
	// PURPOSE: Displays all of the elements within the list
	// PARAMETER: None
	void displayAll();

	// PURPOSE: Adds an item to the front of a list
	// PARAMETER: The item to be added
	void addFront(el_t);
    
	// PURPOSE: Adds an item to the rear of the list
	// PARAMETER: The item to be added
	void addRear(el_t);

	// PURPOSE: Deletes the item at the front of the list
	// PARAMETER: The variable that will receive the deleted item
	void deleteFront(el_t&);
    
	// PURPOSE: Deletes an item from the rear of the list
	// PARAMETER: The variable that will receive the deteleted item
	void deleteRear(el_t&);
    
	// PURPOSE: Deletes the item at position 'I'
	// PARAMETER: The number that correlates with 'I' and the variable that will receive the deleted item
	void deleteIth(int, el_t&);

	// PURPOSE: Adds an item at position 'I'
	// PARAMETER: The number that correlates with 'I' and the item to add
	void insertIth(int, el_t);

  	// PURPOSE: Copy Constructor to allow pass by value and return by value
	// PARAMETER: The list to be copied
  	llist(const llist&);
  	
	// PURPOSE: Overloading of =
	// PARAMETER: The list to be copied
  	llist& operator=(const llist&); 
};

#endif
