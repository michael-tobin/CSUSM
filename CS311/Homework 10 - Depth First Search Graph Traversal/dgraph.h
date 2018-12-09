#ifndef dgraph_h
#define dgraph_h

// =======================================================
// HW#: HW10 dgraph
// Name: Michael Tobin
// Compiler: g++
// File type: dgraph header file
// ==================================================

#include <iostream>
#include "slist.h"
using namespace std;

//-----  globally setting up an alias ---------------------
const int SIZE = 20;    // for the size of the graph table
                        // The graph can have at most SIZE vertices

// this will be in each GTable slot
struct Gvertex
{
	char vertexName;      // The vertex Name
	int outDegree;	      // The Out degree
	slist adjacentOnes;   // The adjacent vertices in an slist
	int visit;            // The visit number
};


class dgraph
{
private:
	Gvertex Gtable[SIZE];  // An array table of Gvertex's representing a dgraph
	int countUsed; // How many slots of the Gtable are actually used

public:
	// PURPOSE: Thrown when the vertex is not in the graph
	// PARAMETER: NONE
	class BadVertex {};  
 
	//---------------------------------------------------------------------
 
 	// PURPOSE: Default constructor
	// PARAMETER: Initialize vertexName (blank) and visit numbers (0)
	//            Initialize countUsed to be 0
	dgraph();    
           
 	//---------------------------------------------------------------------
          
	// PURPOSE: Deconstructor
	// PARAMETER: NONE
	~dgraph();   

	//---------------------------------------------------------------------

	// PURPOSE: Read from the input file table.txt and fill GTable
	// PARAMETER: NONE
	void fillTable();  

	//---------------------------------------------------------------------

	// PURPOSE: Displays in an easy to read format 
	// PARAMETER: NONE
	void displayGraph(); 
	
	//---------------------------------------------------------------------
	
	// PURPOSE: Returns the out degree of a given vertex - may throw BadVertex
	// PARAMETER: V is the vertex to find out degree for
	int findOutDegree(char);  
		
	//---------------------------------------------------------------------
	
	// PURPOSE: Returns the adjacency list of a given vertex - may throw BadVertexx
	// PARAMETER: V is the vertex to find adjacency for
	slist findAdjacency(char);  
	
	//---------------------------------------------------------------------

	// PURPOSE: Marks a given vertex as visited with the given number
	// PARAMETER: Visit number and vertex
	void visit(int, char);
	
	//---------------------------------------------------------------------
	
	// PURPOSE: Checks to see if a given vertex has been marked as visited yet
	// PARAMETER: Vertex to be checked
	bool isMarked(char);

};

#endif
