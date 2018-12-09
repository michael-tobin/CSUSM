#ifndef stack_cpp
#define stack_cpp
  
// =======================================================
// HW#: HW10 stack
// Name: Michael Tobin
// Compiler: g++
// File type: stack implementation file 
// =======================================================

using namespace std;  
#include <iostream>
#include "stack.h"

// PURPOSE:  Constructor initializes top to -1 to represent an empty stack
// PARAMETER: none
stack::stack()
{
	top = -1; 
} 

//---------------------------------------------------------------------

// PURPOSE:  Destructor does nothing due to stack being a static array
// PARAMETER: none
stack::~stack() {}

//---------------------------------------------------------------------
  
// PURPOSE:  Checks top and returns true if empty, false otherwise.
// PARAMETER: none
bool stack::isEmpty()
{
	if ( top == -1) 
		return true; 
		
	else return false; 
}
   
//---------------------------------------------------------------------
    
// PURPOSE: Checks top and returns true if full, false otherwise.
// PARAMETER: none
bool stack::isFull()
{
	if (top == MAX-1 ) 
		return true; 
		
	else return false; 
}
  
//---------------------------------------------------------------------
  
// PURPOSE: Calls isFull and if true, throws an exception (Overflow)
//   		Otherwise, adds an element to el after incrementing top.
// PARAMETER: Pass the element (elem) to be pushed 
void stack::push(el_t elem)
{ 
	if (isFull()) 
		throw Overflow();
		
	else 
   	{
		top++; 
		el[top] = elem; 
	}
}
 
//---------------------------------------------------------------------
 
// PURPOSE: calls isEmpty and if true, throws an exception (Underflow)
//  		Otherwise, removes an element from el and gives it back.
// PARAMETER: Provide a holder (elem) for the element popped (pass by ref)
void stack::pop(el_t& elem)
{ 
	if (isEmpty()) 
		throw Underflow();
	
	else 
	{
		elem = el[top]; 
		top--;
	}
}

//---------------------------------------------------------------------
 
// PURPOSE: Calls isEmpty and if true, throws an exception (underflow)
//  		Otherwise, gives back the top element from el.
// PARAMETER: Provide a holder (elem) for the element (pass by ref)
void stack::topElem(el_t& elem)
{ 
	if (isEmpty()) 
		throw Underflow();
	
	else
	{ 
		elem = el[top]	 ;
	}
}
 
//---------------------------------------------------------------------

// PURPOSE: Calls isEmpty and if true, displays [ empty ].
//          Otherwise, diplays the elements vertically.
// PARAMETER: none
void stack::displayAll()
{  
	if (isEmpty()) 
		cout << "[ empty ]" << endl;
		
	else 
   	{
   		cout << "Stack is:" << endl;
   		for (int i = top; i>-1; i--)
    		{ 
			cout << el[i] << endl; 
		}
	}
}
 
//---------------------------------------------------------------------

// PURPOSE: If stack is not empty, clears the stack by popping all 
//          elements to a local variable; Otherwise throws an exception 
//	    - Underflow.
// PARAMETER: none
void stack::clearIt()
{
	el_t temp;  // Local variable
	
	if (isEmpty()) 
		throw Underflow();
	
	else
	{ 
		for (int i=top; i>-1; i--)
  		pop(temp);    
	}
}
 
#endif
