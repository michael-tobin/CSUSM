//=========================================================
//HW#: HW2 queue
//Your name: Michael Tobin
//Complier:  g++
//File type: client program client2.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include <string>
#include "queue.h"
#include "queue.cpp"

//Purpose of the program: Adds letters to the existing string in 
//						  queue and enqueues them until the queue
//						  is full.
//Algorithm: Dequeue an element and add "A", then "B", then "C", 
//			 enqueueing the result each time until the queue is
//			 full.
int main()
{ 
	queue letters; //Create queue
	string temp1,
		   temp2;
	
	// Initial queueing of A, B, and C
	letters.enqueue("A");
	letters.enqueue("B");
	letters.enqueue("C");
	
	// Iterate through the queue, printing the elements
	for (int i=0; i <3; i++)
	{
		letters.dequeue(temp1);
		cout << temp1 << endl;
		letters.enqueue(temp1);
	}
	
	while (1) // Loops infinitely until exception is thrown
    {
    	try
		{ 
			letters.dequeue(temp1); // Dequeue an element
			temp2 = temp1 + "A"; // Concatenate with "A" 
			letters.enqueue(temp2); // Enqueue the result
			cout << temp2 << endl; // Print the result to screen
		
			temp2 = temp1 + "B"; // Concatenate with "B"
			letters.enqueue(temp2);  // Enqueue the result
			cout << temp2 << endl; // Print the result to screen
		
			temp2 = temp1 + "C"; // Concatenate with "C"
			letters.enqueue(temp2);  // Enqueue the result
			cout << temp2 << endl; // Print the result to screen
		}
		
		//-------------------------------------------------------

     	catch (queue::Underflow)
     	{
     		cout << "ERROR: Queue underflow!" <<endl;
     		exit(1);
	 	}
	 	
	 	//-------------------------------------------------------

	 	catch (queue::Overflow)
	 	{

		 	cout << endl << "==========================="<<endl;
		 	cout << "ERROR: Queue overflow!" << endl;
	 		cout << "===========================" <<endl << endl;
	 		letters.displayAll();
	 		exit(1);
		 }	
    }

}

