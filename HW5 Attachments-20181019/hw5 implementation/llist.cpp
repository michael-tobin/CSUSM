//CS311
//INSTRUCTION:
//Must use the provided HW5_help.doc to create llist.cpp
//It helps to first create if-then-else structure to fill in later.
//- Make sure PURPOSE and PARAMETER comments are given in detail
//- Make sure all if-then-else are commented describing which case it is
//- Make sure all local variables are described fully with their purposes
//EMACS HINT:
//  You can copy from a Word document to emacs (contrl-right click)
//  control-K cuts and control-Y pastes
//  Esc x replace-str does string replacements
//  Esc > goes to the end of the file; Esc < to the beginning
//  Tab on each line will indent perfectly for C++

// ====================================================
//HW#: HW5 llist
//Your name: **
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

llist::llist()
{
	cout << "Calling the llist constructor." << endl;
	Front = NULL;
	Rear = NULL;
	Count = 0;
}

llist::~llist() 
{
	cout << "Calling the llsist destructor." << endl;
	//**;
}

// PURPOSE:
// PARAMETER:
bool llist::isEmpty() 
{
	if (Front==NULL && Rear==NULL && Count==0)
		return true;
	
	else
		return false;
}

// PURPOSE:
// PARAMETER:
void llist::displayAll() 
{ 
	if (llist.isEmpty())
		cout << "[empty]" << endl;
	
	else 
		cout << "[";
		for (int i=0; i < llist.Rear; i++)
			cout << " " << llist.addFront[i] << " ";
		cout << "]" << endl;
}
  
// PURPOSE:
// PARAMETER:
void llist::addRear(el_t NewNum) 
{ 
 // from class notes
}

// PURPOSE:
// PARAMETER:
void llist::addFront(el_t NewNum) 
{ 
 // from class notes
}

// PURPOSE:
// PARAMETER:
void llist::deleteFront(el_t& OldNum) 
{ 
 // if the List is empty, throw an exception.
 // from class notes?
}

// PURPOSE:
// PARAMETER:
void llist::deleteRear(el_t& OldNum) 
{ 
 // from class notes?
}

// PURPOSE:
// PARAMETER:
void llist::deleteIth(int I, el_t& OldNum) 
{ 

}

// PURPOSE:
// PARAMETER:
void llist::insertIth(int I, el_t newNum) 
{ 

}

// PURPOSE:
// PARAMETER:
llist::llist(const llist& Original) 
{ 

}

// PURPOSE:
// PARAMETER:
llist& llist::operator=(const llist& OtherOne) 
{ 

}

