//--------------------------------------------
//CS311 Merge sort 
//Name: Michael Tobin
//Compiler: g++
//--------------------------------------------
using namespace std;
#include <iostream>
#include <vector>

void display(vector<int> X)
{ 
	cout << "[ ";
  	
	for (int i = 0; i < X.size(); i++)
    	cout << X[i] << " ";
  	
	cout << "]" << endl;
}

void combine( vector<int> A, vector<int> B, vector<int> &R )
{
		int i = 0; // index 
     	int temp; // Temporary variable for holding elements from vectors
     	
     while (!A.empty() && !B.empty())
     {
     	cout << "comparison between " << A[i] << " and " << B[i] << endl;
	
		if (A[i] < B[i]) 
	   	{
	   		temp = A[i]; // copy the element from A
	   		A.erase(A.begin()+0); // Erase the element from A
	   		R.push_back(temp);	 // put the element into R
		}
		
       	else if (A[i] >= B[i])
       	{
	 	  	temp = B[i]; // copy the element from B
			B.erase(B.begin()+0); // Erase the element from B
			R.push_back(temp); // put the element into R
		}
	}
	
	if (B.empty() || A.empty())
	{
		while (B.empty() && !A.empty())
		{
			temp = A[i]; // copy the element from A
			A.erase(A.begin()+0); // Erase the element from A
		   	R.push_back(temp); // put the element into R

		}
	
		while (A.empty() && !B.empty())	
		{
	  	 	temp = B[i]; // copy the element from B
			B.erase(B.begin()+0); // Erase the element from B
		   	R.push_back(temp); // put the element into R
		}
	}
	
	cout << "Combined: " << endl;
	display(R);
}


// sort N into R
void MergeSort(vector<int> N, vector<int>& R)
{ 
	vector<int> L1, L2, L1R, L2R;

  // if there is only one element, already sorted, so done.
	if (N.size() == 1) 
	{
		R.push_back(N[0]); 
		return;
	}

  cout << "Merge sort called on: "; display(N);

  // divide N into L1 and L2
  for (int i = 0; i < N.size()/2; i++)
    L1.push_back(N[i]);
    
  for (int i = N.size()/2; i < N.size(); i++)
    L2.push_back(N[i]);

  cout << "1st half:" << endl;
  display(L1);
  cout << "2nd half:" << endl; 
  display(L2);

  // sort the first half and produce L1R
  MergeSort(L1, L1R); 
  // sort the second half and produce L2R
  MergeSort(L2, L2R); 

  // combine the sorted halves into sorted R
  combine(L1R, L2R, R); 
}

int main()
{
  vector<int> initialArray, 
  			  sortedArray;
  int a;
  
  cout << "Enter the elements one per line." << endl;
  cout << "Enter -1 to stop." << endl;
  cout << "Element:"; cin >> a;
  
  // take input until user inputs -1
  while (a != -1)
    {
      initialArray.push_back(a);
      cout << "Element:"; 
	  	cin >> a;
    }
    
  MergeSort(initialArray, sortedArray);  // produce sortedArray

  cout << "Sorted array:" << endl;
  display(sortedArray);
}
