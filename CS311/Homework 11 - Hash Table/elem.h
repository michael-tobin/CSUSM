#ifndef elem_h
#define elem_h

// ====================================================
//HW#: HW11 el_t 
//Your name: Michael Tobin
//Compiler:  g++
//File type: el_t header file
//=====================================================-

#include <iostream>
#include <string>
using namespace std;

class el_t
{
 private:
	int key;      // key
	string name;  // customer name

 public:

	// PURPOSE: Default constructor
	// PARAMETER: NONE
	el_t();  // to create a blank el_t object
  
  
	// PURPOSE: Initializing constructor
	// PARAMETER: Key and name to fill the element
	el_t(int, string); // to create an initialized el_t object


	// PURPOSE: Overload == for search based on the key only
	// PARAMETER: Element calling and element being called on
	bool operator==(el_t);  // overload == for search
 


	// This is a friend function since the receiver object is not el_t
	// PURPOSE: Overload cout
	// PARAMETER: El_t element to be diplayed
	friend ostream& operator<<(ostream&, const el_t&);  
  
	friend class htable;  // client of this class is htable which needs access to the key part of el_t 
	friend class slist;

};
#endif
