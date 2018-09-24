//*********************************************************************************
// PURPOSE: To create and use a dictionary to check other files.
//
// INPUT: User inputs the name of their transaction file when prompted.
//
// OUTPUT: Creates a dictionary from user defined file, then checks other user
//		   defined files and words against that dictionary. Outputs results to 
//		   screen.
//
// DATE:	06/25/2018
// AUTHOR:	Michael Tobin
// EMAIL:	tobin012@cougars.csusm.edu
//*********************************************************************************

#include<iostream>
#include<string>
#include<vector>
#include <fstream>
using namespace std;

#include "Dictionary.cpp"


//*********************************************************************************
// TITLE:	Main function
// PURPOSE: Serves as the main driver of the program.
// DATE:	06/21/2018
//*********************************************************************************
int main()
{
	Dictionary  DictForCS211;
	DictForCS211.ProcessTransactionFile();
	return 0;
}

