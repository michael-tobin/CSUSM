// ====================================================
// HW#: HW11 Hashing client
// Your name: Michael Tobin
// Compiler:  g++
// File type: Hashing client
//=====================================================


using namespace std;
#include "htable.h"

#include "htable.cpp"
#include "elem.cpp"
#include "slist.cpp"
#include "llist.cpp"


int main()
{ 
	int key; // To hold user input
	string name; // To hold user input
	htable table1; // Table to hold everything
	
	cout << "Enter elements as key and name, enter -1 and any letter to exit:" << endl;
	cin >> key >> name;
	
	while (key != -1) // While the user still wants to enter elements
	{
		el_t input(key, name); // Create an element with the users input
		table1.add(input); // Add the new element to the table
		cin >> key >> name; // Take the next input
	}
	
	table1.displayTable(); // Display the table
	
	int skey; // To hold the user's search key input
	el_t found; // Element to hold found element
	el_t blank; // Blank element for case of not found
	cout << "Enter a key to search for or -1 to exit: ";
	cin >> skey; // Get search key from user
	
	while (skey != -1) // While the user still wants to search
	{
		found = table1.find(skey); // search for element, store returned element in found
		
		if (found == blank) // If the returned element is blank
			cout << skey << " not found." << endl;
			
		else // The returned element has some value
			cout << "Found " << skey << ": " << found << endl;
		
		cout << "Enter another key or -1: ";
		cin >> skey; // Get the next input
	}
	
	return 0;
}
