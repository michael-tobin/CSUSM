//--------------------------------------------
//CS311 Combine 
//Name: Michael Tobin
//Compiler: g++
//--------------------------------------------

using namespace std;
#include <iostream>
#include <vector>

// combines two sorted lists A and B into R.
// displays comparison every time it is done.
// The size of A and B are the same or A is 1 element shorter
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
}


int main()
{  
  vector<int> L1; // input vector 1
  vector<int> L2; // input vector 2
  vector<int> L3; // output vector
  int N;  // number of elements in each of L1 and L2
  int e;  // to enter each element

  cout << "How many elements would you like to enter into each sublist?" << endl;
 	 cin >> N;

    cout << "Please enter elements of List1 in increasing order:"  << endl;
  for (int i = 1; i <=N; i++)
    {
        cout << "element :"; 
			cin >> e; 	
			L1.push_back(e);
    }

    cout << "Please enter elements of List2 in increasing order:"  << endl;
  for (int i = 1; i <=N; i++)
    {
        cout << "element :"; 
			cin >> e; 
		L2.push_back(e);
    }
  
  combine(L1, L2, L3); // calls combine to combine 2 vectors into the 3rd
  
  // prints the output vector
  cout << "The combined list is: ";
  int i=0;
  while (i < (N*2))
  {
  	int temp2 = L3[i];
  	cout << temp2 << ", ";
  	i ++;
  }
  cout << endl;
}

