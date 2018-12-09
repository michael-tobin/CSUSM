#ifndef elem_cpp
#define elem_cpp

// ====================================================
//HW#: HW11 el_t 
//Your name: Michael Tobin
//Compiler:  g++
//File type: el_t implementation file
//=====================================================

#include "elem.h"

// PURPOSE: Default constructor
// PARAMETER: NONE
el_t::el_t()
{
  key = 0;
  name = "";
}

// PURPOSE: Initializing constructor
// PARAMETER: Key and name to fill the element
el_t::el_t(int akey, string aname)
{
  key = akey;
  name = aname;
}
  
// PURPOSE: Overload == for search based on the key only
// PARAMETER: Element calling and element being called on
bool el_t::operator==(el_t OtherOne)
{
  if (key == OtherOne.key) 
  	return true; 
	  
	else 
		return false;
}

// PURPOSE: Overload cout
// PARAMETER: El_t element to be diplayed
ostream& operator<<(ostream& os, const el_t& E)  
{  
  os << E.key << "+" << E.name;
  return os;  
}  

#endif
