//CS311
//INSTRUCTION:
//Llist class - header file template 
//You must complete the ** parts and then complete llist.cpp
//Don't forget PURPOSE and PARAMETERS 

// =======================================================
// HW#: HW5 llist
// Your name: **
// Compiler:  g++ 
// File type: headher file  llist.h
//=======================================================

// alias el_t : element type definition
typedef int el_t;

//a list node is defined here as a struct Node for now
struct Node
{
  el_t Elem;   // elem is the element stored
  Node *Next;  // next is the pointer to the next node
};
//---------------------------------------------------------

class llist
{
  
 private:
  Node *Front;       // pointer to the front node
  Node *Rear;        // pointer to the rear node
  int  Count;        // counter for the number of nodes
  
 public:

  // Exception handling classes 
  class Underflow{};
  class OutOfRange{};  // thrown when the specified Node is out of range

  llist ();     // constructor to create a list object
  ~llist();     // destructor to destroy all nodes
  
// PURPOSE:
// PARAMETER:
  bool isEmpty();
    
// PURPOSE:
// PARAMETER:
   void displayAll();

// PURPOSE:
// PARAMETER:
   void addFront(el_t);
    
// PURPOSE:
// PARAMETER:
   void addRear(el_t);

// PURPOSE:
// PARAMETER:
   void deleteFront(el_t&);
    
// PURPOSE:
// PARAMETER:
   void deleteRear(el_t&);
    
// PURPOSE:
// PARAMETER:
   void deleteIth(int, el_t&);

// PURPOSE:
// PARAMETER:
   void insertIth(int, el_t);

  //Copy Constructor to allow pass by value and return by value
  llist(const llist&);
  
  //Overloading of = 
  llist& operator=(const llist&); 

};
