//For Dictionary.cpp
#ifndef Dictionary_cpp
#define Dictionary_cpp

#include<iostream>
#include<string>
#include<vector>
#include <fstream>
using namespace std;

#include "Dictionary.h"

bool Dictionary::failure = false;
bool Dictionary::success = true;


//*********************************************************************************
// TITLE:	Dictionary()
// PURPOSE: Default constructor for Dictionary class
// DATE:	06/21/2018
//*********************************************************************************
Dictionary::Dictionary(): maxWordsInDict(10000), maxWordsPerFile(100) 
{
	totalWordsInDict = 0;	
	for (int i=0; i < 26; i++)
	numOfWordsInFile[i] = 0; 
}
	
	
//*********************************************************************************
// TITLE:	Dictionary(int dictMaxWords, int fileMaxWords)
// PURPOSE: Secondary constructor for Dictionary class
// DATE:	06/21/2018
//*********************************************************************************
Dictionary::Dictionary(int dictMaxWords, int fileMaxWords): maxWordsInDict(dictMaxWords), maxWordsPerFile(fileMaxWords) 
{
	totalWordsInDict = 0;	
	for (int i=0; i < 26; i++)
	numOfWordsInFile[i] = 0; 
}
	
	
//*********************************************************************************
// TITLE:	AddAWord
// PURPOSE: Serves to call other functions in order to add a word to the dictionary
// DATE:	06/21/2018
//*********************************************************************************
bool Dictionary::AddAWord(string word) 
{
	if (!IsValidWord(word)) 
		return failure;
	if (IsWordInDict(word)) 
		return failure;
	
	bool OK = addValidNotExisting(word);
	return OK;
}


//*********************************************************************************
// TITLE:	IsValidWord
// PURPOSE: Checks to see if the current word is valid (not containing numbers/symbols)
// DATE:	06/21/2018
//*********************************************************************************
bool Dictionary::IsValidWord(string& word) 
{
	for (int i=0; i<word.size(); i++)
	{
		word[i] = tolower(word[i]);
		if (word[word.size()-1] == '.')
			word.erase(word.size()-1, 1) ;
		if ((word[i] < 'a') || (word[i] > 'z'))
			return failure;
	}
	return success;	
}


//*********************************************************************************
// TITLE:	IsWordInDict
// PURPOSE: Checks to see if the current word is already in the dictionary
// DATE:	06/21/2018
//*********************************************************************************
bool Dictionary::IsWordInDict(string word) 
{
	char C = word[0];
	C = toupper(C);

	if ((C<'A')||(C>'Z'))
		return failure;

	string filename = "#.txt"; 
	filename[0] = C;

	ifstream fin;
	
	fin.open(filename.data());  
	
	string W;
	while (fin >> W)
		if (word == W)
			return success;
		if (word != W)
			return failure;
}


//*********************************************************************************
// TITLE:	addValidNotExisting
// PURPOSE: Adds the current word to the dictionary
// DATE:	06/21/2018
//*********************************************************************************
bool Dictionary::addValidNotExisting(string word) 
{
	if (totalWordsInDict >= maxWordsInDict)
		return failure;
		
	char A = word[0];
	A = toupper(A);
	int index = A - 'A';
	
	if (numOfWordsInFile[index] >= maxWordsPerFile)
		return failure;
		
	string filename = "#.txt";
	filename[0]	 = A;
	ofstream fout;
	
	fout.open(filename.data(), ios::app);
	
	fout << word << " ";
	
	numOfWordsInFile[index]++;
	totalWordsInDict++;
}


//*********************************************************************************
// TITLE:	DeleteAword
// PURPOSE: Serves to call other functions in order to remove a word from the dictionary.
// DATE:	06/23/2018
//*********************************************************************************
bool Dictionary::DeleteAWord(string word) 
{
	if (!IsValidWord(word)) 
		return failure;
		
	if (!IsWordInDict(word)) 
		return failure;
		
	bool Deleted = RemoveValidExisting(word);
}


//*********************************************************************************
// TITLE:	RemoveValidExisting
// PURPOSE: Removes the current word from the dictionary
// DATE:	06/23/2018
//*********************************************************************************
bool Dictionary::RemoveValidExisting(string word) 
{
	char B = word[0];
	B = toupper(B);
	int index = B - 'A';
	ifstream fin;
	ofstream fout;
	string filename = "#.txt";
	filename[0]	 = B;
	vector<string> temp;
	string W;
	
	fin.open(filename.data());
	while (fin >> W)
		temp.push_back(W);

	for (int i=0; i<temp.size();i++)
		{
			if (temp[i] == word)
				temp.erase(temp.begin()+i);
		}
	fin.close();
	
	fout.open(filename.data());
	for (int i=0; i<temp.size();i++)
	{
		fout << temp[i] << " ";
	}
	
	numOfWordsInFile[index]--;
	totalWordsInDict--;
	return success;
}


//*********************************************************************************
// TITLE:	SearchForWord
// PURPOSE: Serves to call other functions to determine if the word is in the dictionary.
// DATE:	06/25/2018
//*********************************************************************************
bool Dictionary::SearchForWord(string word) 
{
	cout << "Searching for word: " << word << endl;
	cout << "-------------------------------" << endl;
	
	if (!IsValidWord(word)) 
	{
		cout << word << " is not a valid word."<< endl << endl << endl;
		return failure;
	}
		
	if (!IsWordInDict(word)) 
	{
		cout << word << " was not found during search." << endl << endl << endl;
		return failure;
	}
	
	if(IsWordInDict(word))	
	{
		char file = toupper(word[0]);
		cout << word << " was found in file: " << file << ".txt" << endl << endl << endl;
		return success;
	}
	
}


//*********************************************************************************
// TITLE:	PrintAFileInDict
// PURPOSE: Prints the selected dictionary file to the screen
// DATE:	06/22/2018
//*********************************************************************************
bool Dictionary::PrintAFileInDict(string filename) 
{
	ifstream fin;
	int count = 0;
	string temp;
	
	fin.open(filename.data());
	
	if(!fin.is_open())
	{
		cout << "Error opening " << filename << endl;
		return failure;
	}
	cout << "Printing file: " << filename << endl;
	cout << "-------------------------------" << endl;
	
	while (!fin.eof())
	for (int i=0; i< 5; i++)
	{
		fin >> temp;
		if (!fin)
		{
			cout << endl << endl;
			return success;
		}
		cout << temp << " ";

		if (count < 5)
			count++; 
		if (count >= 5)
		{
			cout << endl;
			count = 0;
		}
	}
		return success;
}


//*********************************************************************************
// TITLE:	SpellChecking
// PURPOSE: Checks a word against the dictionary to see if it matches
// DATE:	06/24/2018
//*********************************************************************************
bool Dictionary::SpellChecking(string filename)
{
	fstream fin;
	string word;
	
	fin.open(filename.data());
	
	cout << "Spell checking: " << filename << endl;
	cout << "-------------------------------" << endl;
	
	if(!fin.is_open())
	{
		cout << "Error opening " << filename << endl;
		return failure;
	}
	
	while (!fin.eof())
	{
		fin >> word;
		
		if (!IsValidWord(word)) 
			cout <<"ERROR: " << word << " is not a valid word." << endl << endl;
				
		if (!IsWordInDict(word)) 
			cout << "ERROR: " << word << " was not found" << endl << endl;
	}
	cout << endl;
	return success;
}


//*********************************************************************************
// TITLE:	InsertFileWordsIntoDict
// PURPOSE: Reads from user's file and calls AddAWord to put it into the dictionary
// DATE:	06/22/2018
//*********************************************************************************
bool Dictionary::InsertFileWordsIntoDict(string filename) 
{
	ifstream fin;
	string word;
	
	fin.open(filename.data());
	
	if(!fin.is_open())
	{
		cout << "Error opening " << filename << endl;
		return failure;
	}
	
	while(!fin.eof())
	{
		fin >> word;
		AddAWord(word);
	}
	return success;	
}


//*********************************************************************************
// TITLE:	GetTransactionFile
// PURPOSE: Gets the transaction file's name from the user.
// DATE:	06/21/2018
//*********************************************************************************
string Dictionary::GetTransactionFile() 
{
	string filename;

	cout << "Enter a transaction file name (without file extension): ";
		cin >> filename;
	filename = filename + ".txt";
	cout << endl << endl;
	return filename;
}


//*********************************************************************************
// TITLE:	ProcessTransactionFile
// PURPOSE: Goes through the transaction file, performs operations based in its contents
// DATE:	06/21/2018
//*********************************************************************************
void Dictionary::ProcessTransactionFile()  
{
	string filename = GetTransactionFile();
	fstream fin;
	string command, item;

		
	fin.open(filename.data());
	
	if(!fin.is_open())
		cout << "Error opening transaction file." << endl;
	
	while (!fin.eof())
	{
		fin >> command >> item;
		
		if (!fin)
		{
			break;
		}
		if (command == "AddW")
			AddAWord(item);
		if (command == "InsertF")
			InsertFileWordsIntoDict(item);
		if (command == "PrintF")
			PrintAFileInDict(item);
		if (command == "DeleteW")
			DeleteAWord(item);
		if (command == "SearchW")
			SearchForWord(item);
		if (command == "SpellCheck")
			SpellChecking(item);			
	}
}

#endif
