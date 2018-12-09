#ifndef queue_h
#define queue_h
// =====================================================
// HW#: 	  HW2 queue
// Your name: Michael Tobin
// Compiler:  g++ compiler
// File type: queue header file 
//=====================================================

using namespace std;
#include<string>

//----- Globally setting up the aliases ----------------

typedef string el_t;  // el_t is an alias for the data type
					  // el_t is unknown to the client  

const int MAX_SIZE = 50;  // this is the max number of elements
						  // MAX is unknown to the client
						  
//-------------------------------------------------------

class queue  
{
	private:
	el_t el[MAX_SIZE]; // an array called el.
                   	   // Elements will be found between front and rear but
                       // front may be behind rear since the queue wraps around
	int  count;        // how many elements do we have right now?
 	int  front;        // where the front element of the queue is.
 	int  rear;         // where the rear element of the queue is.

	public:    

	class Underflow {}; // Handles underflow exceptions
	class Overflow {};; // Handles overflow exceptions
   
	//-------------------------------------------------------

	queue();   // constructor to create an object 
	~queue();  //destructor to destroy an object
   
	//-------------------------------------------------------

	// PURPOSE: Returns true if queue is empty, otherwise false.
	// PARAMETER: none
	bool isEmpty();
   
	//-------------------------------------------------------

	// PURPOSE: Returns true if queue is full, otherwise false.
	// PARAMETER: none
	bool isFull();
   
	//-------------------------------------------------------

	// PURPOSE: If full, throws an exception Overflow.
	//			If not full, enters an element at the rear. 
	// PARAMETER: Provide the element (newElem) to be enqueued. 
	void enqueue(el_t);
   
	//-------------------------------------------------------

	// PURPOSE: If empty, throws an exception Underflow.
	// 			If not empty, dequeues the front element to give it back. 
	// PRAMETER: provide a holder (dequeuedElem) for the element dequeued (pass by ref)
	void dequeue(el_t&);
   
	//-------------------------------------------------------

	// PURPOSE: If empty, throws an exception Underflow.
	// 			If not empty, give back the front element 
	//			(but does not dequeue it).
	// PARAMETER: Provide a holder for the element (pass by ref).
	void frontElem(el_t&);
   
	//-------------------------------------------------------

	// PURPOSE: Returns the current size to make it 
	// 			accessible to the client caller.
	// PARAMETER: none
	int getSize();
   
	//-------------------------------------------------------

	// PURPOSE: Display everything in the queue from front to rear
	//  		enclosed in [] if empty, displays [ empty ].
	// PARAMETER: none
	void displayAll();
   
	//-------------------------------------------------------

	// PURPOSE: If empty, throws an exception Underflow.
	//			If queue has just 1 element, does nothing.
	//			If queue has more than 1 element, moves
	//			the front one to the rear.
	// PARAMETER: none
	void goToBack();
};           

#endif
