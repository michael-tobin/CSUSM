// =========================================================
//HW#: BST
//Your name: Michael Tobin
//Complier:  g++
//File type: implementation file 
//================================================================

using namespace std;
#include <iostream>
#include "binstree.h"

// Constructor initializes Root
BST::BST()
{
	Root = NULL;   // This is an empty tree
}


// Destructor must completely destroy the tree
BST::~BST()
{
	dtraverse(Root); // traverse to delete all vertices in post order
	Root = NULL;    
}


// PURPOSE: Does Post Order traversal of the tree and deletes each vertex
// PARAMETER: Pointer to the vertex to be deleted
void BST::dtraverse(Vertex *V)  // recursive post order traversal
{   
	if (V != NULL) // While the tree still has nodes
    {
		dtraverse(V->Left);         // destroy left sub tree of V
		dtraverse(V->Right);        // destroy right sub tree of V
    	delete V;                   // delete V
    }
}


// PURPOSE: Show vertices in IN order traversal from the Root
// PARAMETER: NONE
void BST::Display()
{
	cout << "Elements in the IN order: " << endl;
	INorderTraversal(Root);  // Start in-order traversal from the root
}


// PURPOSE: Does IN order traversal from V recursively
// PARAMETER: V is te pointer to the vertex to visit right now
void BST::INorderTraversal(Vertex *V)
{
	if (V != NULL) //If there are still nodes left in the tree
    {
    	INorderTraversal(V->Left); // Go left recursively
    	cout << V->Elem << endl; // Print V
    	INorderTraversal(V->Right); // Go right recursively
    }
}


// PURPOSE: Searches for an element in PRE-order traversal
// PARAMETER: Element to search for
bool BST::Search(elem_t K)
{
	PREorderSearch(Root, K);  // Start pre-order traversal from the root
}


// PURPOSE: Does PREorder search from V recursively
// PARAMETER: V is the pointer to the vertex to be visited now
//        	  K is what we are looking for
bool BST::PREorderSearch(Vertex *V, elem_t K)
{
	if (V != NULL) // If the tree still has nodes
    {
    	if (K == V->Elem)  // If the key matches the element at V
			return true; // Found the element in V
        
		else if (K < V->Elem) // If the key is less than the element at V
			PREorderSearch(V->Left, K); // Traverse left sub-tree of V recursively
	    
		else // The key is greater than the element at V
			PREorderSearch(V->Right, K); // traverse right sub-tree of V recursively
    }
    
    else // If the key is not found
		return false;
}


// ------ The following are for adding and deleting vertices -----


// PURPOSE: Adds a vertex to the binary search tree for a new element 
// PARAMETER: the new element E
// ALGORITHM: We will do this iteratively (not recursively)
// 			  to demonstrate the algorithm that is in the notes
//    		  - smaller than the current -> go to the left
//   		  - bigger than the current  -> go to the right
//   		  - cannot go any further    -> add it there
void BST::InsertVertex(elem_t E)
{
// Set up a new vertex first
	Vertex *N;         // N will point to the new vertex to be inserted
	N = new Vertex;    // A new vertex is created
	N->Up = NULL;      // No parent for now
	N->Left  = NULL;   // Make sure it does not
	N->Right = NULL;   // Point to anything
	N->Elem  = E;      // Put element E into it
//	N->Height = 0;
//	N->Balance = 0;

	cout << "Trying to insert " << E << endl;

	// Special case: we have a brand new empty tree
	if (Root == NULL)  
    {
    	Root = N;      // the new vertex is added as the root
    	cout << "...adding " << E << " as the root" << endl; 
    }// end of the special case

	// If the tree is not empty
	else  
    {
    	Vertex *V;       // V will point to the current vertex
        Vertex *Parent;  // Parent will point to V's parent
        V = Root;        // Start with the root as V

		// Go down the tree until you cannot go any further        
		while (V != NULL)
		{
			if (N->Elem == V->Elem) // If the element already exists
    	    {	 
				cout << "...error: the element already exists" << endl;
				return;  
			}
	    
			else if (N->Elem < V->Elem)  // If the element is smaller than V's element
			{  
				cout << "...going to the left" << endl; 
				Parent = V;
				V=V->Left;	
			}
		
		    else // If the element is larger than V's element
			{  
				cout << "...going to the right" << endl;
				Parent=V;
				V=V->Right;
			}
		}//end of while
                
    	if (N->Elem < Parent->Elem)  // If N's element is smaller than Parent's element
    	{   
			cout << "...adding " << E << " as the left child of " << Parent->Elem << endl;
			Parent->Left = N; // Point Parent left to N
			N->Up = Parent; // Point N up to Parent
		}
        
		else // If N's element is larger than Parent's element
    	{
    		cout << "...adding " << E << " as the right child of " << Parent->Elem << endl;	
    		Parent->Right = N; // Point Parent right to N
    		N->Up = Parent; // Point N up to Parent
		}
    }// end of normal case
}// end of InsertVertex


// PURPOSE: Deletes a vertex that has E as its element.
// PARAMETER: Element E to be removed
// ALGORITHM: First find the vertex then call Remove
void BST::DeleteVertex(elem_t E)
{
	cout << "Trying to delete " << E << endl;
  
	Vertex *V;              // The current vertex
	Vertex *Parent;			// Pointer for Parent of V

	// case 1: Lonely Root  
	if ((E == Root->Elem) && (Root->Left == NULL) && (Root->Right == NULL))
    { 
		cout << "...deleting the lonely root" << endl;
		delete Root; // Delete the vertex
    	Root = NULL; // Point root to null
    	return; 
	}  // only the Root was there and deleted it
  
	// case 2:  Root has only one subtree

	// If Root holds the key to be deleted
	if ((E == Root->Elem) && ((Root->Left == NULL) && (Root->Right != NULL)) || ((Root->Left != NULL) && (Root->Right == NULL))) 
	{
		// If it has only the left subtree
		if ((Root->Left != NULL) && (Root->Right == NULL))
    	{  
    		V = Root->Left; // Point V to the left node
    		delete Root; // Delete the root
    		Root = V; // Point root to V (previously left node)
    		Root->Up = NULL; // Point root up to null
    	}
    	
    	// If it has only the right subtree
    	else if ((Root->Left == NULL) && (Root->Right != NULL))
    	{ 
    		V = Root->Right; // Point V to the right node
    		delete Root; // Delete root
    		Root = V; // Point Root to V (previously right node)
    		Root->Up = NULL; // Point root up to null
		}
	}// end of deleting the root with one subtree
  
	// Otherwise deleting something else
	else
	{
		V = Root;  // start with the root to look for E
  
 		// going down the tree looking for E
		while (V != NULL)
		{ 
    		if ( E == V->Elem)   // Found it
				{  
					cout << "...removing " << V->Elem << endl;
					Parent = V->Up; // Set parent as the node prior to V
					remove(V, Parent); // Call remove
			  		return; 
				}
      
    		else if (E < V->Elem) // If E is less than V's element
	  		{	  
				cout << "...going to the left" << endl;
				Parent = V; // Shift parent down to V
				V=V->Left; // Shift V down to the left
		  	}
	
			else
	  		{  
				cout << "...going to the right" << endl;
				Parent = V; // Shift Parent down to V
				V=V->Right; // Shift V down to the right
		  	}
    	}// end of while
	}
  
	// reached NULL  -- did not find it
	if (V==NULL)
	cout << "Did not find the key in the tree." << endl; 
}// end of DeleteVertex


// PURPOSE: Removes vertex pointed to by V
// PARAMETER: V and its parent  pointer P
// ALGORITHM: Case 1: it is a leaf, delete it
// 			  Case 2: it has just one child, bypass it
// 			  Case 3: it has two children, replace it with the max of the left subtree
void BST::remove(Vertex *V, Vertex *P)
{
	Vertex *Child; // Pointer for use later in the function
	
// If V is a leaf (case 1)
	if ((V->Left == NULL) && (V->Right == NULL))
	{
		cout << "removing a leaf" << endl;
		
		// If V is a left child of P
		if (V->Elem < P->Elem) 
		{
	  		delete V; // Delete the leaf
	  		P->Left = NULL; // Point Parent left to null
		}
	
		// If V is a right child of P
		else if (V->Elem > P->Elem) 
	  	{ 
	  		delete V; // Delete the leaf
	  		P->Right = NULL; // Point Parent right to null
	  	}
    }//end of leaf case
    
// If V has just the left child (case 2A)
	else if ((V->Left != NULL) && (V->Right == NULL))
	{
		cout << "removing a vertex with just the left child" << endl;

		// If V is a left child of P
		if(V->Elem < P->Elem)
	  	{
	  		Child = V->Left; // Point child to the left child of V
	  		Child->Up = P; // Point child up to Parent
	  		P->Left = Child; // Make child a left child of Parent
	  		delete V; // Delete V
		}
	
		// If V is a right child of P
		else if(V->Elem > P->Elem)
		{
	  		Child = V->Left; // Point child to the left child of V
	  		Child->Up = P; // Point child up to Parent
	  		P->Right = Child; // Make child a right child of Parent
	  		delete V; // Delete V
		}
	}// end of V with left child       
 
// If V has just the right child (case 2B)
	else if ((V->Left == NULL) && (V->Right != NULL))
	{
		cout << "removing a vertex with just the right child" << endl;
		
		// If V is a left child of P
		if(V->Elem < P->Elem)
		{
	  		Child = V->Right; // Point child to the right child of V
	  		Child->Up = P; // Point child up to Parent
	  		P->Left = Child; // Make child a left child of Parent
	  		delete V; // Delete V
		}
	
		// If V is a right child of P
		else if(V->Elem > P->Elem)
		{
	  		Child = V->Right; // Point child to the right child of V
	  		Child->Up = P; // Point child up to Parent
	  		P->Right = Child; // Make child a right child of Parent
	  		delete V; // Delete V
		}
	}//end of V with right child
      
// V has two children (case 3)
	else 
	{ 
		cout << "removing an internal vertex with children" << endl;
		cout << "..find the MAX of its left sub-tree" << endl;
		elem_t Melem; 
		
		// find MAX element in the left sub-tree of V
    	Melem = findMax(V); // Call findmax
    	cout << "..replacing " << V->Elem << " with " << Melem << endl;
    	V->Elem = Melem; // Replace V's element with Melem
    }//end of V with two children  
}// end of remove


// PURPOSE: Finds the Maximum element in the left sub-tree of V
// 			and also deletes that vertex
elem_t BST::findMax(Vertex *V)
{
	Vertex *Parent = V; // Make parent point to V
	V = V->Left; // Move V to its left child
	
	if (V->Right != NULL) // If there is a right child
	{
		Parent = V; // Move Parent to V
		V = V->Right; // Move V to the right child
	}
	
	// reached NULL Right  -- V now has the MAX element
	elem_t X = V->Elem; // Copy V's element to X
	cout << "...Max is " << X << endl;
	remove(V, Parent); // Remove the MAX vertex 
	return X; // Return the MAX element
}// end of FindMax

