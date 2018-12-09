#ifndef slist_cpp
#define slist_cpp

// ====================================================
// HW#: HW11 slist
// Name: Michael Tobin
// Complier:  g++
// File type: slist implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"slist.h" 


// PURPOSE: Default constructor
// PARAMETER: None
slist::slist()
{
}


// PURPOSE: Search through the list to see if any node contains the key
// PARAMETER: Integer to search for
int slist::search(el_t searchNum)
{
	int foundPos=1; // Start at the first position
	Node *P;
	P=Front; // Front of the list that called the function
	
	while (P != NULL) // While not the end of the list 
	{
		if (P->Elem.key != searchNum.key) // If the number is not found move to the next element
		{
			P=P->Next; // Move P
			foundPos++; // Account for the move
		}
		
		else if (P->Elem.key == searchNum.key) // If the number is found, report its location
		{
			return foundPos; // Return the location 
		}
		
		else // If the end of the list is reached without finding the number return 0
			return 0;		
	}
}


// PURPOSE: Search through the list to see if any node contains the element
// PARAMETER: Element to search for
el_t slist::search2(el_t searchNum)
{
	Node *P;
	P=Front; // Front of the list that called the function
	
	while (P != NULL) // While not the end of the list 
	{
		if (P->Elem.key != searchNum.key) // If the number is not found move to the next element
		{
			P=P->Next; // Move P
		}
		
		else if (P->Elem == searchNum) // If the number is found, report its location
		{
			return P->Elem; // Return the found element
		}
	}// end of while
	
	// If we've reached here, the element is not in the list
	el_t blank; // Create a blank element
	return blank; // return a blank element
}
	
	
// PURPOSE: Go to the Ith node and replace the element there with the new element 
// PARAMETER: Integer to replace with, and location to replace
void slist::replace(el_t Elem, int i)
{
	
	if ((i > Count) || (i<1)) // If the user is trying to replace a position that does not exist in the list
	{
		throw OutOfRange(); // Throw an exception
	}
	
	
	else // If the user wants to insert somewhere in the middle
	{
		Node *Q; 
		Q=Front; // Point Q to the front of the list 
	
		for (int j=1; j<=i-1; j++) // Move Q to i
		{
			Q=Q->Next; // Move Q
		}
	
		Q->Elem = Elem; // Replace the element at i

	}
}


// PURPOSE: Checks to see of the two lists look the same 
// PARAMETER: Pass the list to be compared against the calling list
bool slist::operator==(const slist& OtherOne)
{
	Node *P;
	Node *Q; 
	P = this->Front; // P is the list that called the function
	Q = OtherOne.Front; // Q is the list that is passed to the function
	

	while (P!=NULL && Q!=NULL) // While there are still elements left in each list
	{
	
		if (P==NULL && Q==NULL) // If the end of the lists are reached at the same time
			return true;
	
		else if (P->Elem == Q->Elem) // Otherwise compare each element and move to the next
		{
		P=P->Next; // Move P and Q
		Q=Q->Next;
		}
		
		else // If the two above cases fail return false
			return false;
	}
	
	if (P==NULL && Q==NULL) // If the lists are empty
                return true;

    else if (this->Count != OtherOne.Count) // If the lists are different sizes they are not equal
                return false;
                
}


#endif
