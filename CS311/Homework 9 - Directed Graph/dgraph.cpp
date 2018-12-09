#ifndef dgraph_cpp
#define dgraph_cpp

//CS311 dgraph.cpp
// INSTRUCTION:
//  Complete all the functions you listed in dgraph.h
//  Comment the file completely using How to Comment file.
//  Use HW9-help.docx to finish the functions.
//-------------------------------------------------------

//======================================================
// HW#: HW9 dgraph
// Name: Michael Tobin
// File Type: dgraph implementation
//========================================================

using namespace std;
#include <iostream>
#include <fstream>
#include <string>
#include "dgraph.h"
#include "llist.cpp"
#include "slist.cpp"

// PURPOSE: Default constructor
// PARAMETER: Initialize vertexName (blank) and visit numbers (0)
//			  Initialize countUsed to be 0
dgraph::dgraph()    
{
	this->countUsed = 0;
    
	for (int i = 0; i < SIZE; ++i) 
	{            
        this->Gtable[i].vertexName = ' ';
        this->Gtable[i].outDegree = 0;
        this->Gtable[i].visit = 0;
    }
}


// PURPOSE: Deconstructor
// PARAMETER: NONE	
dgraph::~dgraph()   // do we have to delete all nodes of slists in table??
// Question: If we do not do this, will the llist destructor be called automatically??? Try it.
{
	
}


// PURPOSE: Read from the input file table.txt and fill GTable
// PARAMETER: NONE
void dgraph::fillTable()  // make sure to read from table.txt file
{
    ifstream fin("table.txt", ios::in);
    char x;
 
    while (fin >> Gtable[countUsed].vertexName) 
	{
        fin >> Gtable[countUsed].outDegree;
        
        for (int i = 0; i < Gtable[countUsed].outDegree; ++i) 
		{
            fin >> x;
            Gtable[countUsed].adjacentOnes.addRear(x);
        }
    
        countUsed++;
    }
}


// PURPOSE: Displays in an easy to read format 
// PARAMETER: NONE
void dgraph::displayGraph() // make sure to display
// in a really nice format -- all columns
{
	char tmp;
    
	for (int i = 0; i < this->countUsed; ++i) 
	{
        cout << Gtable[i].vertexName << " " << Gtable[i].outDegree 
		<< " " << Gtable[i].visit << " ";
        
        if (!Gtable[i].adjacentOnes.isEmpty())
            Gtable[i].adjacentOnes.displayAll();
            
        else
        	cout << "[Empty]" << endl;
	}
}

// PURPOSE: Returns the out degree of a given vertex 
// PARAMETER: V is the vertex to find out degree for
int dgraph::findOutDegree(char V)
{
	int index = V-65;
	
    if (Gtable[index].vertexName == V)
        return Gtable[index].outDegree;
    else
		return -1;
}


// PURPOSE: Returns the adjacency list of a given vertex 
// PARAMETER: V is the vertex to find adjacency for
slist dgraph::findAdjacency(char V)// throws exception
{
	int index = V-65;
	
    if (Gtable[index].vertexName == V)
        return Gtable[index].adjacentOnes;
    else
        return slist(); 
}

#endif





















