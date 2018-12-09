//----------------------------------------
//CS311 HW4 quick sort
//Your name: Michael Tobin
//Compiler: g++
//-----------------------------------------

#include<iostream>
using namespace std;

int partition(int a[], int first, int last)
{
	cout << "Partition was called with " << "first " << first << " and last " << last << endl;
	
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


// sorting a section starting at first and ending at last
void quicksort(int a[], int first, int last)
{
  if (first >= last) return;

  cout << "QuickSort: first is " << first << " and last is " << last << endl;

  int pivotIndex = partition(a, first, last);
    
  cout << " ..The pivot element is " << a[pivotIndex] << endl;
    
  // sort the first section in place
  if (first < a[pivotIndex])
  quicksort(a, first, pivotIndex-1);
  
  // sort the second section in place
  if (a[pivotIndex] < last)
  quicksort(a, pivotIndex+1, last);
}


int main()
{
  int x;
  int nums[10];
  cout << "How many elements would you like to enter into the array? (must be less than 10) ";
  cin >> x;
  cout << "Enter elements one per line.." << endl;
  for (int i = 0; i < x; i++)
    { cin >> nums[i]; }

  quicksort(nums, 0, x-1);

  cout << "Sorted array:" << endl;
  for (int i = 0; i < x; i++) // up to the partition
      {cout << nums[i] << " "; }
  cout << endl;
}
