// ================================================
// HW#: HW10 dgraph traversal client
// Name: Michael Tobin
// Compiler: g++
// File type: dgraph traversal client file
// ================================================

#include <iostream>
#include "dgraph.h"
#include "dgraph.cpp"
#include "slist.cpp"
#include "stack.cpp"

int main()
{ 
	dgraph graph; // Initialize the graph
    char c = ' '; // Blank char for user input
    int degreeFound = -1; // Initialize to a number outside of the graph parameters
    slist listFound; // Initialize a list to hold adjacencies
    stack stack; // Stack to hold chars from adjacency list
    int x = 1; // Counter for visit numbers
    
    graph.fillTable(); // Fill the graph from the file
    graph.displayGraph(); // Display the contents of the graph
    
   
    stack.push('A'); // Add 'A' to the stack
	try
	{
    	while (!stack.isEmpty())
    	{   
    		begin:	// Label for later goto
     		stack.pop(c); // Pop the top vertex from the stack
     		cout << "-------------------" << endl;
     		cout << "Removed " << c << " from stack" << endl; // Display the popped vertex
     	
			if (graph.isMarked(c)) // If the popped vertex has already been visited
			{
				cout << c << " had been visited already - go one vertex up to take another path." << endl;
				stack.displayAll(); // Display the stack
				goto begin; // Jump to the beginning of the while loop
							// NOTE: The condition of my else if statement is not working, hence the goto
			}// end of if
		
			else if (!graph.isMarked(c)); // If the vertex has not been visited yet
     		{
			 	graph.visit(x, c); // Mark the vertex as visited, using the value in x
    	 		x++; // Increment x for the next vertex
     			listFound = graph.findAdjacency(c); //copy the adjacency list
     		
     			if (!listFound.isEmpty()) // If the list has elements
     			{
     				cout << "... pushing [ ";
   					while (!listFound.isEmpty()) // Loop until the list is empty
   	 				{
	    				char temp;
						listFound.deleteRear(temp); // Remove the element
						cout << temp << " "; // Display the element
    					stack.push(temp); // Push the element to the stack
					}
					cout << "]" << endl;
				}
			
				else if (listFound.isEmpty()) // If the adjecency list was empty
				{
					cout << "Deadend reached - go one vertex up to take another path." << endl;
				}
			
				stack.displayAll(); // Display the stack
     		}// end of else if
		

		}// End of while
	}// end of try

catch (...)
{	
	cout << "-----------------------" << endl << "Out Visit Adj" << endl << "-----------------------" << endl;
	    graph.displayGraph(); // Display the contents of the graph
}// End of catch

    return 0;
}
