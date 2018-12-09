// =======================================================
// HW#: HW1P1 stack application
// Name: Michael Tobin
// Compiler:  g++
// File type: client program client1.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "stack.h"
#include "stack.cpp"

// Purpose of the program: Take from user, and process a postfix expression
// Algorithm: **
int main()
{
  stack postfixstack;  // Integer stack
  string expression;   // User entered expression
  
  cout << "Type a postfix expression: " ;
  cin >> expression;
  
  int i = 0;  // Character position within expression
  char item;  // One char out of the expression
  
  int box1;  // Receive things from pop
  int box2;  // Receive things from pop
  
  while (expression[i] != '\0')
    {
		try
		{
			item = expression[i];  // Current char
		
			if ((item != '+') && (item != '-') && (item != '*'))
			{
				int x = int(item)-48; // Convert char with ASCII math
				
				if (x >= 0 && x <= 9)	// If it is a number (isdigit), push to the stack
	 				postfixstack.push(x); 
	 				
	 			else throw "Invalid character";
	 		}
	 		
	 		else if (item == '+' || item == '-' || item == '*')
	 		{
		 		int temp;
	 	
		 		postfixstack.pop(box1); // Pop two operands from the stack
	 			postfixstack.pop(box2);
	 	
	 			switch (item) // Perform operation on operands
	 			{
		 			case '+': temp = box2 + box1;
		 			break;
	 				case '-': temp = box2 - box1;
	 				break;
	 				case '*': temp = box2 * box1;
	 				break;
	 			}
			
				postfixstack.push(temp); // Push result to the stack
	 		}
	 	
	 		else
	 		throw "Invalid character"; // If the user inputs something other than an integer or operator
	 		
		} // this closes the try
       
		catch (stack::Overflow) 
		{
			cout << "The expression was too long" << endl; // If the user inputs too many operands
		}
    
		catch (stack::Underflow)
		{
			cout << "Too few operands/numbers" << endl; // If the user has too many operators/ too few operands
		}
     
	 	catch (const char* errormsg ) // for invalid item case
		{
			cout << "Invalid item entered" << endl;
			exit(1);
		}

		i++; // Returns to the start of the while loop after incrementing i
    } // end of while
  

	postfixstack.pop(box1); // Pop from the stack
	
	if (postfixstack.isEmpty()) // If the stack is empty, then the value popped is the result from the postfix expression
		cout << "The answer is " << box1 << endl;
	
	else 
		cout << "The expression entered is incomplete!" << endl; // Otherwise, if there are still values in the stack, then we are missing an operator
}
