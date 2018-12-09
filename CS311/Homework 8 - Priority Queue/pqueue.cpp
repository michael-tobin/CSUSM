// =================================================
// HW8 Priority Printer Queue 
// YOUR NAME: Michael Tobin
// File Type: implementation pqueue.cpp
// =================================================

#include "pqueue.h"

// PURPOSE: constructor
// PARAMETER: None
pqueue::pqueue()
{  
	count = 0;  // no jobs yet
}


// PURPOSE: Destructor does nothing
// PARAMETER: None
pqueue::~pqueue() 
{ 

}


// PURPOSE: To add a job to a right place in the Pqueue
// PARAMETER: j is the job priority number
void pqueue::insertjob(int j)
{
	cout << "Adding: " << j << endl;

		int i = count; 
		Q[i] = j; // Stores in the empty space after the last element
		trickleup(); // moves the job to the right place
		count++;
}


// PURPOSE: To print a job and reheapify the Pqueue
// PARAMETER: None
void pqueue::printjob()
{
	cout << "Printing: " << Q[0] <<endl;
	reheapify(); // Calls reheapify
}


// PURPOSE: To display all jobs
// PARAMETER: None
void pqueue::displayAll()
{ 
	cout << "Jobs: ";
	
	for (int i=0; i<count; i++) //While there are still elements
	{
		cout << Q[i] << " ";
	}
	
	cout << endl;
	// loop to display jobs from slot 0 to slot count-1 horizontally
} 

// Utility functions follow: ------------------


// PURPOSE: To make the very last job trickle up to the right location
// PARAMETER: None
void pqueue::trickleup()
{ 
	//Start at the end and work towards root
	for (int x = count-1; x>=0; x--)
	{
		int y = getParent(x); // Y is the parent of x
		if (Q[x] < Q[y]) // if x is less than its parent, swqp them
		{
			int z = Q[y];
			Q[y] = Q[x];
			Q[x] = z;
			x--;
		}
		
		else // otherwise return
			return;
	}
}


// PURPOSE: Find the location of the parent 
// PARAMETER: The child location is given.  Need to call even.
int pqueue::getParent(int child)
{ 
	bool iseven = even(child); // true=even, false=odd
	int parent;
	
	if (iseven==true) 
		parent = child /2; // Works backwards to parent
		
	else if (iseven==false)
		parent = (child-1)/2; // Works backwards to parent
		
	return parent;
}


// PURPOSE: Is location i even? Important in finding its parent location
// PARAMETER: Position that you want to check
bool pqueue::even(int i)
{
	if ((i % 2) ==  0) // If the position is divisible by 2, it is even
  		return true; 
	else // If not its odd
		return false; 
}


// PURPOSE: To reheapify the Pqueue after printing
// PARAMETER: None
void pqueue::reheapify()
{ 
	int temp;
	
	Q[0] = Q[count-1];  // move the last job to the front
	count--; // Remove the last element from count
	int x = 0; // start x at the beginning

	while (x<count) // While we havent reached the end of the list
	{
		int small = getSmallerchild(x); // Get the position of the smaller child
		
		if (Q[small] < Q[x]) // If the smaller child is smaller than the parent, swap them
		{
			int temp = Q[x];
			Q[x] = Q[small];
			Q[small] = temp;
		}
		x++; //increment x each time
	}
}


// PURPOSE: To find the location of the smaller child
//			where children at locations 2*i+1 and 2*i+2
// PARAMETER: Parent position
int pqueue::getSmallerchild(int i)
{
	int x = (i*2)+1; // x is one child
	int y = (i*2)+2; // y is the other
	

	if (x<=count && y<=count) // If theyre both in the list
	{
		if (Q[x] < Q[y]) // x is the smallest
			return x;
	
		else if (Q[x] > Q[y]) // y is the smallest
			return y;
	}
	
	else if (x<=count && y>count) // x is in the list, but y has runover
		return x;
	
	else if (x>count && y<=count) // y is in the list but x has runover
		return y;
	
	else // both have runover 
		return -1;
	//  return the location of the smaller child 
}


