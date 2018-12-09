//----------------------------------------
//CS311 HW4 partition
//Your name: Michael Tobin
//Compiler: g++
//-----------------------------------------

#include<iostream>
using namespace std;

// This function partitions the array a into two sections
// for elements smaller than pivot and larger than pivot.
// first is the index of first element in the section to be partitioned.
// last is the index of last element in the section to be partitioned
// The function returns the index of pivot.
int partition(int a[], int first, int last)
{
	int i = first +1; 
  	int j = last;
  
	swap (a[first], a[(first+last)/2]); // move pivot to the beginning
  	int pivot = a[first]; // assign the first element as pivot
  	while (i <= j)
  	{
    	while (a[i] < pivot) // Move i to the right until it is more than pivot or passes j
        	i++;
        	
		while (pivot < a[j]) // Move j to the left until it is less than pivot or passes i
        	j--;
     	
		if (i < j) // if i and j pass each other, swap them
        	swap(a[i++], a[j--]);
    	
		else 
        	i++;  
	}
  
	swap (a[j], a[first]); // Swap j with the first position
  
  return (i-2);
}


int main()
{
	int x;  // number of elements
	int nums[10]; // array of 10 elements max
    
	cout << "How many elements would you like to enter into the array? (must be less than 10): ";
		cin >> x;
  	cout << "Enter the elements one per line" << endl;
  
  	for (int i = 0; i < x; i++)
    { 
		cin >> nums[i]; // loop to intake array elements
	}


  	int pivot_index = partition(nums, 0, x-1); // call for the partition function

  	cout << "The array was partitioned" << endl;
  
  	// display up to the pivot without endl
  	for (int i = 0; i < pivot_index; i++)
    {
    	cout << nums[i] << " ";
 	}
  
  	// display the pivot
  	cout << "| " << nums[pivot_index] << " | " ;
    
  	// display from the pivot without endl
  	for (int i = pivot_index+1; i < x; i++)
    	cout << nums[i] << " ";

  	cout << endl;
}
