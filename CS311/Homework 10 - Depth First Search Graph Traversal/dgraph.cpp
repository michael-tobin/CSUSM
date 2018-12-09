#ifndef dgraph_cpp
#define dgraph_cpp

//========================================================
// HW#: HW10 dgraph
// Name: Michael Tobin
// Compiler: g++
// File type: dgraph implementation
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
//	      Initialize countUsed to be 0
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

//---------------------------------------------------------------------

// PURPOSE: Deconstructor
// PARAMETER: NONE	
dgraph::~dgraph()  
{}

//---------------------------------------------------------------------

// PURPOSE: Read from the input file table.txt and fill GTable
// PARAMETER: NONE
void dgraph::fillTable()  
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

//---------------------------------------------------------------------

// PURPOSE: Displays in an easy to read format 
// PARAMETER: NONE
void dgraph::displayGraph()
{
	char tmp;
    
	for (int i = 0; i < this->countUsed; ++i) 
	{
		cout << Gtable[i].vertexName << " " << Gtable[i].outDegree 
		<< "    " << Gtable[i].visit << " ";
        
	        if (!Gtable[i].adjacentOnes.isEmpty())
        		Gtable[i].adjacentOnes.displayAll();
            
	        else
        		cout << "[Empty]" << endl;
	}
}

//---------------------------------------------------------------------

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

//---------------------------------------------------------------------

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

//---------------------------------------------------------------------

// PURPOSE: Marks a given vertex as visited with the given number
// PARAMETER: Visit number V and index I 
void dgraph::visit(int V, char I)
{
	cout << "Visit " << I << " as " << V << endl;
	int index = I-65;
	Gtable[index].visit = V;	
}
	
//---------------------------------------------------------------------
	
// PURPOSE: Checks to see if a given vertex has been marked as visited yet
// PARAMETER: Index I to be checked
bool dgraph::isMarked(char I)
{
	int index = I-65;
	
	if (Gtable[index].visit == 0)
		return false;
	
	else if (Gtable[index].visit > 0)
		return true;
}

#endif





















