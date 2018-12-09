#ifndef slist_h
#define slist_h

//=================================================
// HW#: HW11 slist
// Name: Michael Tobin
// Compiler: g++
// File type: slist header
//=================================================

#include "llist.h"


class slist: public llist
{
public:
	
	// PURPOSE: Default constructor
	// PARAMETER: None
	slist();   


	// PURPOSE: search through the list to see if any node contains the key
	// PARAMETER: Integer to search for
	int search(el_t);

    // PURPOSE: search through the list to see if any node contains the key
	// PARAMETER: Integer to search for
	el_t search2(el_t);
	
    // PURPOSE: Go to the Ith node and replace the element there with the new element 
	// PARAMETER: Integer to replace with, and location to replace	
    void replace(el_t, int); 
    
    
    // PURPOSE: Checks to see of the two lists look the same 
	// PARAMETER: Pass the list to be compared against the calling list
    bool operator==(const slist&);
};

#endif
