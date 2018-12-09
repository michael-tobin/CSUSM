#ifndef htable_cpp
#define htable_cpp
// ====================================================
// HW#: HW11 Hash table
// Your name: Michael Tobin
// Compiler:  g++
// File type: Hash implementation file
//=====================================================

using namespace std;
#include <iostream>
#include "htable.h"

htable::htable()
{}

htable::~htable()
{}


// PURPOSE: Hash function that uses % TSIZE simply (mod TSIZE)
// PARAMETER: Key to be hashed
int htable::hash(int key)
{ 
	int slot = key % TSIZE; // key mod array size
	return slot;
}


// PURPOSE: Adds the element to the table and returns slot#
// PARAMETER: Element to be added 
int htable::add(el_t element )
{
	int slot = hash(element.key);  // hash with the key part
	table[slot].addRear(element); // insert the element to the slist at the slot 
}

// 

// PURPOSE: Finds element using the skey and returns the found element itself
// 			or a blank element
// PARAMETER: Search key
el_t htable::find(int skey)
{ 
	el_t E; // a blank element
	int slot = hash(skey); // hash with skey	
	
	el_t selement;  // this is the element to look for in slist
 	selement.key = skey; // initialize it with just the skey
	selement = table[slot].search2(selement); // call slist's search2 with selement which returns the found element 
 	return selement; // return the found element from here
}

// 
// PURPOSE: Displays the entire table with slot #s
// PARAMETER: NONE
void htable::displayTable()
{
  for (int i = 0; i < TSIZE; i++)
    { cout << i << ":" ;   
      table[i].displayAll();
    }
}

#endif
