//For Class Dictionary
#ifndef Dictionary_h
#define Dictionary_h

#include<iostream>
#include<string>
#include<vector>
#include <fstream>
using namespace std;

//*********************************************************************************
// TITLE:	Class Dictionary
// PURPOSE: Defines the Dictionary class in terms of size limits and function prototypes
// DATE:	06/21/2018
//*********************************************************************************
class Dictionary
{
	private:
		const int maxWordsInDict;
		const int maxWordsPerFile;
		int	totalWordsInDict;
		int	numOfWordsInFile[26];
		static	bool failure;
		static	bool success;
	
	public:
		Dictionary(); 
		Dictionary(int dictMaxWords, int fileMaxWords); 
		bool AddAWord(string word); 
		bool IsValidWord(string& word); 
		bool IsWordInDict(string word); 
		bool addValidNotExisting(string word); 
		bool DeleteAWord(string word);
		bool RemoveValidExisting(string word);
		bool SearchForWord(string word);
		bool PrintAFileInDict(string filename);
		bool SpellChecking(string fileName);
		bool InsertFileWordsIntoDict(string filename); 
		string GetTransactionFile(); 
		void ProcessTransactionFile(); 	
};

#endif
