// ================================================
// HW#: HW9 dgraph client
// Name: Michael Tobin
// File type:  dgraph client file
// ================================================

#include <iostream>
#include "dgraph.h"
#include "dgraph.cpp"
#include "slist.cpp"


int main()
{ 
	dgraph graph; // Initialize the graph
    char c = ' '; // Blank char for user input
 
    graph.fillTable(); // Fill the graph from the file
    graph.displayGraph(); // Display the contents of the graph
    
    int degreeFound = -1; // Initialize to a number outside of the graph parameters
    slist listFound; // Initialize a list to hold adjacencies

    while (c !='Z') // While the user still wants to input choices
	{
        try
		{
			cout << "Enter a vertex name or character Z to exit: ";
        		cin >> c;
            
            // If the requested vertex is not in the graph, throw exception
        	if ((graph.findOutDegree(c)) == -1) // If the function returned no out degree
            	throw dgraph::BadVertex(); // Throw the exception
            	
        	else // Vertex is in the graph
   			{
	   			degreeFound = graph.findOutDegree(c); // Find the out degree
				cout << degreeFound << " edges go out to " << endl; // And display it
    	    	
				listFound = graph.findAdjacency(c); // Find the adjacency list
        	
        		if (listFound.isEmpty()) // If the adjacency list is empty
            		cout << "[Empty]" << endl;
        		else
            		listFound.displayAll(); // Otherwise display the list
        	}
        }// End of try
        
        catch(...) // Exception catch
        {
        	cout << "No such vertex exists." << endl;
		}

    }// End of while

    return 0;
    
}
