#ifndef queue_cpp
#define queue_cpp
//=========================================================
//HW#: 		 HW2 queue
//Your name: Michael Tobin
//Complier:  g++
//File type: queue.cpp
//===========================================================

using namespace std;
#include <iostream>
#include "queue.h"  

// PURPOSE: Constructor 	
// PARAMETER: none	
queue::queue()
{
	front = 0;
	rear = -1;
	count = 0;
}

//-------------------------------------------------------

// PURPOSE: Destructor 
// PARAMETER: none
queue::~queue()
{
	
}

//-------------------------------------------------------

// PURPOSE: Returns true if queue is empty, otherwise false.
// PARAMETER: none
bool queue::isEmpty()
{
	if (count <= 0)
		return true;
	
	else
		return false;
}

//-------------------------------------------------------

// PURPOSE: Returns true if queue is full, otherwise false.
// PARAMETER: none
bool queue::isFull()
{
	if (count == MAX_SIZE)
		return true;
			
	else 
		return false;
}

//-------------------------------------------------------

// PURPOSE: If full, throws an exception Overflow.
//			If not full, enters an element at the rear. 
// PARAMETER: Provide the element (newElem) to be enqueued. 
void queue::enqueue(el_t newElem)
{
	// enqueue an element, rear = (rear+1) % MAX_SIZE must be done first 
	if (isFull())
		throw Overflow();
	
	else
	{
		rear = (rear+1) % MAX_SIZE;
		el[rear] = newElem;
		count++;
	}
}

//-------------------------------------------------------

// PURPOSE: If empty, throws an exception Underflow.
// 			If not empty, dequeues the front element to give it back. 
// PARAMETER: provide a holder (dequeuedElem) for the element dequeued (pass by ref).
void queue::dequeue(el_t& dequeuedElem)
{
	// dequeue an element, front = (front+1) % MAX_SIZE must be done 
	if (isEmpty())
		throw Underflow();
	
	else
	{
		dequeuedElem = el[front];
		front = (front+1) % MAX_SIZE;
		count --;
	}
}

//-------------------------------------------------------

// PURPOSE: If empty, throws an exception Underflow.
// 			If not empty, give back the front element 
//			(but does not dequeue it).
// PARAMETER: Provide a holder for the element (pass by ref).
void queue::frontElem(el_t& theElem)
{
	if (queue::isEmpty())
		throw Underflow();
	
	else
	theElem = el[front];
}

//-------------------------------------------------------

// PURPOSE: Returns the current size to make it 
// 			accessible to the client caller.
// PARAMETER: none
int queue::getSize()
{
	return count;
}

//-------------------------------------------------------

// PURPOSE: Display everything in the queue from front to rear
//  		enclosed in [] if empty, displays [ empty ].
// PARAMETER: none
void queue::displayAll()
{  
	int j = front;
	int c = count;
	if (isEmpty())
		cout << "[ empty ]" << endl;
		
	else
	{
 	 	cout << "[";
  	 	
  	 	while (c>0)
  	 	{
  	 		cout << el[j] << " ";
  	 		j = (j+1)%MAX_SIZE;
  	 		c--;
		}
		
		cout << "]" << endl;     
	}
}


//-------------------------------------------------------

// PURPOSE: If empty, throws an exception Underflow.
//			If queue has just 1 element, does nothing.
//			If queue has more than 1 element, moves
//			the front one to the rear.
// PARAMETER: none
void queue::goToBack()
{ 
	string temp;
	
	if(queue::isEmpty())
		throw Underflow();
		
	else
	dequeue(temp);
	enqueue(temp);
}

#endif
