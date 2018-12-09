//=========================================================
//HW#: HW5 llist
//Your name: Michael Tobin
//Complier:  g++
//File type: client program (tester) HW5client.cpp
//===========================================================

using namespace std;
#include <iostream>
#include <stdlib.h>
#include "llist.cpp"

//PURPOSE: to test copy constructor; 
// adds 6 to the rear of the copiedList and displays the list
//PARAMETER: list passed by value becomes copiedList 
void CopyTest(llist copiedList)
{
	cout << "in copy test" << endl;
	llist copy(copiedList); // Calls the copy constructor to make a copy of the passed list
	cout << "Adding 6 to the copy list" << endl;
	copy.addRear(6); // Adds 6 to differentiate the copy from the original
 
	cout << "copy-> ";
  	copy.displayAll(); // Display the new list 
  	cout << "finished" << endl << endl;
}


void caseOne()
{
	cout << "CASE 1: Basic --------------- " << endl;
	llist L;   // Call default constructor
	int x;     // To hold a removed element

//1 check empty and report the result  
	cout << endl;
  	cout << "Step " << 1 << endl;
  	if (L.isEmpty()) cout << "It is empty" << endl; // If list is empty
  	else cout << "It is not empty" << endl; // If list has elements
  	cout << endl;
  
  
//2 display the list  
  	cout << "Step " << 2 << endl;
  	L.displayAll(); // Display the list's contents


//3 add 4 integers to rear 1,2,3,4    
  	cout << "Step " << 3 << endl;
  	cout << "Adding 1,2,3,4" << endl;
  	L.addRear(1); // Add elements to the list
  	L.addRear(2); 
  	L.addRear(3); 
  	L.addRear(4);
    cout << endl;
    	
    	
//4 display the list  
  	cout << "Step " << 4 << endl;
  	L.displayAll(); // Display the list
    cout << endl;


//5 remove from front twice using x (and display the elements removed)
 	cout << "Step " << 5 << endl;
 	
  	L.deleteFront(x); // Remove the first element
  	cout << x << " was removed from the list." << endl << endl; // Display the removed element
  	
	L.deleteFront(x); // Remove the first element
 	cout << x << " was removed from the list." << endl << endl; // Display the removed element


//6 display the list
	cout << "Step " << 6 << endl;
	L.displayAll(); // Display the list


//7 check empty and report the result 
   cout << "Step " << 7 << endl;
	if (L.isEmpty())
		cout << "It is empty" << endl << endl; // If the list is empty
	
	else 
		cout << "It is not empty" << endl << endl; // If the list has elements


//8 remove from the rear twice using x (display the elements removed)
   cout << "Step " << 8 << endl;
	
	L.deleteRear(x); // Remove the last element
	cout << x << " was removed from the list." << endl << endl; // Display the removed element

	L.deleteRear(x); // Remove the last element
	cout << x << " was removed from the list." << endl << endl; // Display the removed element


//9 check empty again and report the result
  	cout << "Step " << 9 << endl; 
	if (L.isEmpty()) // If the list is empty
		cout << "It is empty" << endl << endl;

	else // If the list has elements
		cout << "It is not empty" << endl << endl;
		
}//end of case 1 

 
void caseTwo()
{ 
	cout << "Case 2: Insert and Delete ------------" << endl;
	llist L2;  // Another list for case 2
	int x;      // To hold the removed element 
	int c = 1;  // Counter for step number

// 1. add to front 4 times (9,8,6,5) 
	cout << endl;
	cout << "Step " << c << endl; c++;
	cout << "L2-> Adding 9,8,6,5 to the front" << endl;
	L2.addFront(9); // Add elements to the list
	L2.addFront(8); 
	L2.addFront(6); 
	L2.addFront(5);
	
    cout << endl;

// 2. display all
	cout << "Step " << c << endl; c++;
	L2.displayAll(); // Display the elements
		
  
// 3. insert the 1st  (element 4) 4 5 6 8 9
	cout << "Step " << c << endl; c++;
	cout << "L2-> Inserting 4 in 1st position" << endl;
	L2.insertIth(1, 4); // Insert 4 into the 1st position
    cout << endl;

  
// 4. insert the 4th  (element 7)  4 5 6 7 8 9
	cout << "Step " << c << endl; c++;
	cout << "L2-> Inserting 7 in 4th position" << endl;
	L2.insertIth(4, 7); // Insert 7 into the 4th position
    cout << endl;

  
// 5. insert the 7th  (element 10) 4 5 6 7 8 9 10
	cout << "Step " << c << endl; c++;
	cout << "L2-> Inserting 10 in 7th position" << endl;
 	L2.insertIth(7, 10); // Insert 10 into the 7th position
    cout << endl;

  
// 6. insert the 9th  (element 12) error (out of range)
	cout << "Step " << c << endl; c++;
	cout << "L2-> Inserting 12 in 9th position" << endl;

	try
	{
		L2.insertIth(9, 12); // Try to insert 12 into the 9th position
	} 
	
	catch (llist::OutOfRange) // Exception handling for OOR
	{
		cout << "ERROR: Out of range." << endl;
	}  
  	cout << endl;
  	
  
// 7. insert the 0th (element 0) error (out of range)
	cout << "Step" << c << endl; c++;
	cout << "L2-> Inserting 0 in 0th position" << endl;

	try // Try to insert 0 at the 0th position
	{
		L2.insertIth(0, 0); 
	} 
	catch (llist::OutOfRange) // Exception handling for OOR
	{
		cout << "ERROR: Out of range." << endl;
	}  // do not exit
	cout << endl;

	  
// 8. displayAll
	cout << "Step " << c << endl; c++;
	L2.displayAll(); // Display the elements of the list

  
// 9. delete Ith I==1 (display  the element removed) 5 6 7 8 9 10
	cout << "Step " << c << endl; c++;
	L2.deleteIth(1, x);  // Remove the element in the first position
	cout << "removed " << x << endl; // Display the removed element
    cout << endl;

  
// 10. delete Ith I==6 (display the element removed) 5 6 7 8 9 
	cout << "Step " << c << endl; c++;
	L2.deleteIth(6, x);  // Remove the element in the 6th position
	cout << "removed " << x << endl; // Display the removed element
    cout << endl;

  
// 11. delete Ith I==3 (display the element removed) 5 6 8 9
	cout << "Step " << c << endl; c++;
	L2.deleteIth(3, x); // Remove the element in the 3rd position
	cout << "removed " << x << endl; // Display the removed element
    cout << endl;

  
// 12. delete Ith I==5 . error (out of range)
	cout << "Step " << c << endl; c++;
	try // Try to remove the element in the 5th position
	{
		L2.deleteIth(5, x); 
	}
	catch(llist::OutOfRange) // Exception handling for OOR
	{
		cout << "ERROR: Out of range." << endl;
	}
    cout << endl;

  
// 13. delete Ith I==0 . error (out of range)
	cout << "Step " << c << endl; c++;
	try 
	{
		L2.deleteIth(0, x); // Try to remove the element in 0th position
	}
	catch(llist::OutOfRange) // Exception handling for OOR
	{
		cout << "ERROR: Out of range." << endl;
	}
    cout << endl;

  
// 14. displayAll
	cout << "Step " << c << endl; c++;
	L2.displayAll(); // Display the elements of the list

  
// 15. delete from rear until empty (display the elements removed)
	cout << "Step " << c << endl; c++;
	cout << "L2-> Emptying" <<endl;
	while (!L2.isEmpty()) // While there are still elements in the list
	{
		L2.deleteRear(x); // Remove the last element
		cout << "removed " << x << endl; // Display the removed element
	}
	cout << endl;

	  
// 16. displayAll  - should be empty now
	cout << "Step " << c << endl; c++;
	L2.displayAll(); // Display the elements of the list
	cout << endl;

  
// 17. insert the 0th  (error out of range)
	cout << "Step " << c << endl;; c++;
	try 
	{
		L2.insertIth(0, 0); // Try to insert 0 into the 0th position
	}
	catch (llist::OutOfRange) // Exception handling for OOR
	{
		cout << "ERROR: Out of range." << endl;
	}
    cout << endl;

  
// 18. delete front  (error underflow)
	cout << "Step " << c << endl; c++;
	try // Try to remove the front element
	{
		L2.deleteFront(x);
	}
	catch (llist::Underflow) // Exception handling for underflow
	{
		cout << "ERROR: Underflow." << endl;
	}
    cout << endl;

  
// 19. delete 2nd I == 2 (error out of range)
	cout << "Step " << c << endl; c++;
	try // Try to remove the 2nd position
	{
		L2.deleteIth(2, x);
	}
	catch (llist::OutOfRange) // Exception handling for OOR
	{
		cout << "ERROR: Out of range." << endl;
	}
    cout << endl;

  
// 20.  delete rear (error underflow)
	cout << "Step " << c << endl; c++;
	try // Try to remove the last element
	{
		L2.deleteRear(x); 
	}

	catch (llist::Underflow) // Exception handling for underflow
	{
		cout << "ERROR: Undeflow." << endl;
	}
	cout << endl;
	
} // end of case 2


void caseThree()
{
	cout << "Case 3: Copy Constructor and = -------" << endl << endl;
  	llist L1, L2; // Two lists needed
  	int x;        // Local for removed element
  	int counter = 1;  // Counter for step number

	cout << endl;
	
//1. Create a 5 element list with  1,2,3,4,5 (L1)
	cout << "Step " << counter << endl; counter++;
	cout << "L1 -> add 1,2,3,4,5" << endl;
  	L1.addRear(1); // Add elements to the list
  	L1.addRear(2);
  	L1.addRear(3);
  	L1.addRear(4);
  	L1.addRear(5);
  	cout << endl;
  	

//2. Simply pass L1  to a client function called CopyTest to 
  //test your copy constructor.
  	cout << "Step " << counter << endl; counter++;
  	cout << "L1 -> CopyTest" << endl;
 	CopyTest(L1); // Function call for copytest
  	cout << endl;


	cout << "-- After copytest --- " << endl << endl;
 
 
//3. Display L1 (this should still be a 5 element list)
	cout << "Step " << counter << endl; counter++;
	cout << "L1 -> ";
  	L1.displayAll(); // Display the elements of L1

 
	cout << "-- Testing operator overloading ---" << endl;


//4. Do L1 = L1;
	cout << "Step " << counter << endl; counter++;
	cout << "L1 = L1" << endl;
	L1 = L1; // Overloaded =
	cout << endl;

//5. Display L1    (this should still be 1 2 3 4 5)
	cout << "Step " << counter << endl; counter++;
	cout << "L1 -> ";
	L1.displayAll(); // Display the elements of L1
	
	
//6. Create a 4 element list L2 with 7,8,9,10.
	cout << "Step " << counter << endl; counter++;
	cout << "L2 -> add 7,8,9,10" << endl;
	L2.addRear(7); // Add elements to L2
	L2.addRear(8);
	L2.addRear(9);
	L2.addRear(10);
	cout << endl;


//7. Display L2
	cout << "Step " << counter << endl; counter++;
	cout << "L2 -> ";
	L2.displayAll(); // Display the elements of L2


//8. Do L2 = L1;  (L2 becomes 5 elements 1,2,3,4,5)
	cout << "Step " << counter << endl; counter++;
	cout << "L2 = L1" << endl;
	L2 = L1; // Overloaded =
	cout << endl;
	

//9. Display L2.
	cout << "Step " << counter << endl; counter++;
	cout << "L2 -> ";
	L2.displayAll(); // Display the elements of L2
	

//10. Remove a rear node from L1. (This should not affect L2).
	cout << "Step " << counter << endl; counter++;
	cout << "L1 -> ";
	L1.deleteRear(x); // Delete the last item of L1
	cout << endl;
	
	
//11. Display L1.   (L1 is 1,2,3,4)
	cout << "Step " << counter << endl; counter++;
	cout << "L1 -> ";
	L1.displayAll(); // Display the elements of L1
	

//12. Display L1 again. (4 elements just to make sure)
	cout << "Step " << counter << endl; counter++;
	cout << "L1 -> ";
	L1.displayAll(); // Display the elements of L1
	
	
//13. Display L2 again. (still 5 elements 1,2,3,4,5)
	cout << "Step " << counter << endl; counter++;
	cout << "L2 -> ";
	L2.displayAll(); // Display the elements of L2
}

//PURPOSE of the Program: to test llist thoroughly
//Algorithm/Design: 3 test cases are divided into functions
int main()
{
	int selection; // Holds the users input 
  
	do
    {
    	cout << endl << "MENU: These are your options: " << endl << endl;
    	cout << "   (1) Case 1  " << endl;
    	cout << "   (2) Case 2  " << endl;
      	cout << "   (3) Case 3  " << endl;
      	cout << "    Enter ( 0 ) to quit " << endl;
      	cout << "===>";
      
      	cin >> selection;
      
		switch(selection)
		{
			case 1: caseOne(); break;
			case 2: caseTwo(); break;
			case 3: caseThree(); break;
		}
    }
  while(selection !=0);

}// end of main

