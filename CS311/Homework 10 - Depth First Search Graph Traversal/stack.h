#ifndef stack_h
#define stack_h

// =======================================================
// HW#: HW10 stack
// Name: Michael Tobin
// Compiler: g++
// File type: stack header file 
// =======================================================

//----- Globally setting up the aliases ----------------

const int MAX = 20;   // The MAX number of elements for the stack
                      // MAX is unknown to the client

typedef char el_t;     // el_t is unknown to the client


class stack
{ 
 private: // to be hidden from the client

	el_t el[MAX];       // el is  an array of el_t's
	int top;           // top is index to the top of stack

 public:  // available to the client
  
	class Overflow{};   // Used to handle stack overflows
	class Underflow{};  // Used to handle stack underflows
	
  	//---------------------------------------------------------------------
  	
  	stack();   // Constructor to create a stack array
  	~stack();  // Destructor  to destroy stack array
  	
	//---------------------------------------------------------------------
	
  	// PURPOSE: If not full, enters an element at the top;
  	//          Otherwise throws an exception - Overflow
  	// PARAMETER: Pass the element to be pushed
  	void push(el_t);
  	
  	//---------------------------------------------------------------------
  	
  	// PURPOSE: If not empty, removes and gives back the top element;
  	//          Otherwise throws an exception - Underflow
  	// PARAMETER: Provide variable to receive the popped element (by ref)
  	void pop(el_t&);
  	
  	//---------------------------------------------------------------------
  	
  	// PURPOSE: If not empty, gives the top element without removing it;
  	//          Otherwise, throws an exception - Underflow
  	// PARAMETER: el_t variable "elem" provided for pass by reference.
  	void topElem(el_t&);
  	
  	//---------------------------------------------------------------------
  	
  	// PURPOSE: Checks top and returns true if empty, false otherwise.
  	// PARAMETER: none
  	bool isEmpty();
  	
  	//---------------------------------------------------------------------
  	
  	// PURPOSE: Checks top and returns true if full, false otherwise.
  	// PARAMETER: none
  	bool isFull();
  	
  	//---------------------------------------------------------------------
  	
	// PURPOSE: Calls isEmpty and if true, displays [ empty ].
	//          Otherwise, diplays the elements vertically.
	// PARAMETER: none
  	void displayAll();
  	
  	//---------------------------------------------------------------------
  	
  	// PURPOSE: If stack is not empty, clears the stack by popping all 
	//         elements to a local variable; Otherwise throws an exception 
	//	   - Underflow.
	// PARAMETER: none
  	void clearIt();
};  

#endif
