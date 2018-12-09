//--------------------------------------------
// CS311 Binary Search
// Your name: Michael Tobin
// Compiler: g++
// --------------------------------------------

#include <iostream>
using namespace std;

// x is the key that we are looking for in array L; first and last are slot numbers
int binarySearch(int L[], int x, int first, int last) 
{
  int middle = (first + last)/2; // Recalculates middle at each recursive call
  
	cout << "comparing against an element in slot " << middle << endl;
	
	if (first <= last) // If first and last have not crossed each other, the search is not complete
	{
		if (x == L[middle]) // If x == L[middle], then x has been found at middle
 			return middle;
 	
 		else if (x < L[middle]) // If x < L[middle], then move to the left half
 			last = middle - 1;
 	
 		else if (x > L[middle]) // If x > L[middle], then move to the right half
 			first = middle +1;
 		
		 return binarySearch(L, x, first, last); // Recursive call
	}
	
	else if (first > last) // If first > last, then they have crossed and x is not in the array
		return -1;
}



int main()
{ 
	int A[10]; // Array of 10 elements
	int e;  // Key to look for

	// fixed elements for A
	A[0] = 1; 
	A[1] = 3; 
  	A[2] = 5; 
  	A[3] = 7; 
  	A[4] = 9; 
  	A[5] = 11; 
  	A[6] = 13;
  	A[7] = 15; 
  	A[8] = 17; 
  	A[9] = 19;

	
  	cout << "What do you want to look for? ";
  	cin >> e;
  	
  	int respos = binarySearch(A, e, 0, 9); // Initial calling of binarySearch

  	if (respos == -1) // binarySearch will return -1 if the search is completed without finding the key
		cout << "Element not found" << endl; 
		
  	else // If respos is not -1, then the returned int is the position in the array
		cout << "Found it in position " << respos+1 << endl; 
  
	return 0;
}
