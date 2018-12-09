#ifndef llist_cpp
#define llist_cpp

// ====================================================
//HW#: HW5 llist
//Your name: Michael Tobin
//Complier:  g++
//File type: llist.cpp implementation file
//=====================================================

using namespace std;
#include<iostream>
#include"llist.h" 

// PURPOSE: Default constructor
// PARAMETER: None
llist::llist()
{
	cout << "Calling the llist constructor." << endl;
	Front = NULL;
	Rear = NULL;
	Count = 0;	
}

// PURPOSE: Destructor
// PARAMETER: None
llist::~llist() 
{
	cout << "Calling the llist destructor." << endl;
	while (Count>0) // While there are still items in the list
	{
		int A;
		deleteFront(A); // Delete the item
		Count--; // Decrement the counter to account for the item deletion
	}
}

// PURPOSE: Checks to see if the list is empty
// PARAMETER: None
bool llist::isEmpty() 
{
	if (Front==NULL && Rear==NULL &&Count==0) // If all are valid, the list is empty
		return true;
	
	else // Otherwise there is something in the list
		return false;
}

// PURPOSE: Displays all of the elements within the list
// PARAMETER: None
void llist::displayAll() 
{
	if (isEmpty()) // If the list is empty, tell the user
		cout << "[ empty ]" << endl; 
	
	else // Otherwise show what is in the list
	{
		cout << "[ ";
		Node *P; 
		P=Front;
		
		while (P != NULL) // While not a the end of the list
		{
			cout << P->Elem << " "; // Print the current item
			P=P->Next; // Then move to the next one
		}
		P=NULL; // Point P away from the list to avoid destructor issues
		cout << "] " << Count << " elements" << endl;
	}
	cout << endl;
}
  
// PURPOSE: Adds an item to the rear of the list
// PARAMETER: The item to be added
void llist::addRear(el_t NewNum) 
{
	if (Count==0) // If the list is empty
	{
		Rear = new Node; // Point rear to a new node
		Rear->Next=NULL; // Make that node->Next point to null
		Front = Rear; // Front = rear because there is only one item
		Front->Next = NULL; // Same as rear because there is only one item
		Rear->Elem = NewNum; // Store the new element in the list
		Count++; // Increment the count to account for the new item
	}
	
	else if (Count>0) // If the list has some element(s) already
	{
		Rear->Next=new Node; // Add a new node after rear & point rear->next to it
		Rear = Rear->Next; // Move rear to the new node
		Rear->Elem = NewNum; // Store the element in the new node
		Rear->Next=NULL; // Make rear->next point to null
		Count++; // Increment the counter to account for the new item

	}
}

// PURPOSE: Adds an item to the front of a list
// PARAMETER: The item to be added
void llist::addFront(el_t NewNum) 
{
	if (Count==0) // If the list is empty
	{
		Front=new Node; // Point front to a new node
		Rear=Front; // Rear = front because there is only one item
		Rear->Next=NULL; // Make rear-> next point to null
		Front->Elem=NewNum; // Store the element in front
		Count++; // Increment the counter to account for the new item
	}
	
	else  // If the list has some element(s) already
	{
		Node *second; // Make a new pointer
		second = Front; // Point the new pointer at front
		Front = new Node; // Point front to a new node
		Front->Elem = NewNum; // Store the element in front
		Front->Next = second; // Make front->next point to second (previous front node)
		Count++; // Increment the counter to account for the new item
	}
}

// PURPOSE: Deletes the item at the front of the list
// PARAMETER: The variable that will receive the deleted item
void llist::deleteFront(el_t& OldNum) 
{
	cout << "Deleting front." << endl;
	if (Count==0) // If the list is empty, you cannot delete anything
	{
		throw Underflow(); // Throw an exception
	}
	
	else if (Count==1) // If deleting an item will make the list empty
	{
		OldNum = Front->Elem; // Save the element into OldNum
		delete Front; // Delete the node
		Front = NULL; // Point front to null
		Rear = NULL; // Point rear to null
		Count--; // Decrement counter to account for removed item
	}
	
	else
	{
		Node *P; // Create a new node pointer
		P=Front->Next; // Point that pointer to the second node in the list
		OldNum = Front->Elem; // Save the element into OldNum
		delete Front; // Delete front
		Front = P; // Point front to P (old second, now front)
		Count--; // Decrement counter to account for removed item
	}
}

// PURPOSE: Deletes an item from the rear of the list
// PARAMETER: The variable that will receive the deteleted item
void llist::deleteRear(el_t& OldNum) 
{
	cout << "Deleting rear." << endl;
	
	if (Count==0) // If the list is empty
	{
		throw Underflow(); // Throw an exception
	}
	
	else if (Count==1) // If this will make the list empty
	{
		OldNum = Rear->Elem; // Save the element into OldNum
		delete Rear; // Delete the node
		Rear = NULL; // Point rear to null
		Front = NULL; // Point front to null
		Count--; // Decrement counter to account for removed item
	}
	
	else // If there are >1 elements
	{
		Node *P; // Create a new node pointer
		P = Front; // Point it to front
		
		while (P->Next->Next != NULL) // Move P to the node before rear
		{
			P = P->Next;
		}
		
		OldNum = Rear->Elem; // Save the element into OldNum
		delete Rear; // Delete rear
		Rear = P; // Point rear to p (previously the node before rear)
		Rear->Next = NULL; // Point rear->next to null
		Count--; // Decrement counter to account for removed item
	}
}

// PURPOSE: Deletes the item at position 'I'
// PARAMETER: The number that correlates with 'I' and the variable that will receive the deleted item
void llist::deleteIth(int I, el_t& OldNum) 
{
	cout << "Deleting item in position " << I << endl;
	
	if ((I > Count) || (I<1)) // If the user is trying to delete a non existant node
	{
		throw OutOfRange(); // Throw an exception
	}
	
	else if (I==1) // If position is 1 (first element) 
	{
		deleteFront(OldNum); // Call deletefront
	}
	
	else if (I==Count) // If position is the last element
	{
		deleteRear(OldNum); // Call deleterear
	}
	
	else // Otherwise
	{
		Node *Q; // Create 2 node pointers
		Node *P;
		Q=Front; // Point Q to front
		
		for (int j=1; j<=I-2; j++) // Move Q to the item before I
		{
			Q=Q->Next;
		}
		
		P=Q->Next; // Point P to the I item (at Q->next)
		Q->Next = Q->Next->Next; // Point Q->next to the item after I
		OldNum=P->Elem; // Save the element into OldNum
		delete P; // delete I'th item
		Count--; // Decrement counter to account for removed item
	}
}

// PURPOSE: Adds an item at position 'I'
// PARAMETER: The number that correlates with 'I' and the item to add
void llist::insertIth(int I, el_t newNum) 
{
	if ((I > Count+1) || (I<1)) // If the user is trying to skip an item or put one before the list
	{
		throw OutOfRange(); // Throw an exception
	}
	
	else if (I==1) // If the user wants to insert at position 1
		addFront(newNum); // Call addfront

	else if (I==Count+1) // If the user wants to insert at the last position
		addRear(newNum); // Call addrear
		
	else // If the user wants to insert somewhere in the middle
	{
		Node *Q; // Create 2 node pointers
		Node *P;
		Q=Front; // Point Q to the front of the list 
		
		for (int j=1; j<=I-2; j++) // Move Q to I-1
		{
			Q=Q->Next; // I-1
		}
		
		P=Q->Next; // I'th item
		Q->Next = new Node; // Insert new node into I'th position
		Q=Q->Next; // Q is the new element now
		Q->Next=P; // Links into the rest of the list
		Q->Elem=newNum; // Stores the passed value
		Count++; // Increment the counter to account for the new item
	}	
}

// PURPOSE: Copy Constructor to allow pass by value and return by value
// PARAMETER: The list to be copied
llist::llist(const llist& Original) 
{
    // This->'s data members need to be initialized here first
    Front = NULL; // Point this->'s Front to null 
	Rear = NULL;  // Point this->'s rear to null
	Count = 0; // Make this->'s count 0
	
    //  this-> object has to be built up by allocating new cells
    //  and copying the values from Original into each cell as we did with 
    //  operator= above. To do this,
    
    Node* P;  // local pointer for Original
    P = Original.Front; //Point P to the original list
        
	while (P != NULL)  // While not at the end of original list 
    {
        this->addRear(P->Elem);    //P's element is added to this->
        P = P->Next;               // Go to the next node in Original   
    } 
}
	                
// PURPOSE: Overloading of =
// PARAMETER: The list to be copied
llist& llist::operator=(const llist& OtherOne) 
{
	// To do this, compare the pointers to the objects .
     
	if (&OtherOne != this)  // Check to see if this-> & OtherOne are the same
    {
		while (! this->isEmpty()) // While there are items in this->
        {
        	int A; // Variable to receive the deleted item
        	this->deleteRear(A); // Delete from rear until empty
		}
                    
        Node* P;  // local pointer for OtherOne
        P = OtherOne.Front; // Point P to the front of the list to be copied
        
        while (P != NULL)  // a loop which repeats until you reach the end of OtherOne. 
		{
        	this->addRear(P->Elem); //P's element is added to this->
        	P = P->Next; // Go to the next node in OtherOne   
        } 
	}
	                
	return *this;    // return the result unconditionally.  Note that the result is returned by reference
}

#endif
