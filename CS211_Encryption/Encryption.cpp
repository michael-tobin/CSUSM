//*********************************************************************************
// PURPOSE: To encrypt & decrypt a user's data file with either
//			ROT or cryptograph encryption.
//
// INPUT:	User chooses between encrypt & decrypt, ROT & cryptogram. 
//			The user then chooses an input and output file, and in the
//			case of ROT encryption, chooses a ROT value.
//
// OUTPUT:	Outputs a file (name dictated by the user) with the encrypted
//			or decrypted content.
//
// DATE:	06/10/2018
// AUTHOR:	Michael Tobin
//*********************************************************************************


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

//*********************************************************************************
// FUNCTION PROTOTYPES
//*********************************************************************************
void SecurityDriver();
void EncryptRot();
	string GetInputFileForRotEncrypt();
	vector<string> PlaceWordsIntoVectorForRotEncrypt(string RotInputFile);
	vector<string> EncryptTheVectorUsingRot(int RotNum, vector<string> V);
	string GetOutputFileForRotEnc();
	void PlaceEncryptedRotIntoFile(string EROutputfile, vector<string> EncVecForRot); 
	int GetRotNum(); // Used by both EncryptRot and DecryptRot
	
void DecryptRot();
	string GetInputForRotDecrypt();
	vector<string> PlaceWordsIntoVectorForRotDecrypt(string RotDecInputFile);
	vector<string> DecryptTheVectorUsingRot(int RotNum, vector<string> X); 
	string GetOutputFileForRotDecrypt();
	void PlaceDecryptedRotIntoFile(string DROutputfile, vector<string> DecVecForRot); 
	
void EncryptCrypto();
	string ReadCryptoKeyFromFile(); //used by both EncryptCrypto and DecryptCrypto
	string GetInputFileForCryptoEncrypt();
	vector<string> EncryptTheStringWithCrypto (vector<string> PreCryptoEncryptionText, string Key);
	string GetOutputFileForCryptoEncrypt();
	vector<string> CopyInputFileToVector(string CryptoInputFile);
	void PlaceCryptoEncryptIntoFile(string ECOutputfile, vector<string> EncryptTheStringWithCrypto);

void DecryptCrypto();
	string GetInputFileForCryptoDecrypt();
	string GetOutputFileForCryptoDecrypt();
	vector<string> CopyEncryptedFileToVector(string CryptoInputFile);
	vector<string> PreEncryptedText();
	vector<string> DecryptTheStringWithCrypto(vector<string> PreEncryptedText, string Key);
	vector<string> CryptoDecryptedText();
	void PlaceCryptoDecryptIntoFile(string DCOutputfile, vector<string> CryptoDecryptedText);


//*********************************************************************************
// TITLE:	Main function
// PURPOSE: Only serves to call the Security Driver.
// DATE:	06/07/2018
//*********************************************************************************
int main() 
{
	SecurityDriver();
	return 0;	
}


//*********************************************************************************
// TITLE:	SecurityDriver
// PURPOSE: Takes user choice input and calls the corresponding encrypt/decrypt function.
// DATE:	06/07/2018
//*********************************************************************************
void SecurityDriver() 
{
	int choice;
	
	cout << "Select a choice from below" << endl;
	cout << "1. Encrypt with ROT(n)" << endl << "2. Decrypt with ROT(n)" << endl;
	cout << "3. Encrypt with cryptogram" << endl << "4. Decrypt with cryptogram" << endl;
	cout << "10. Quit the program" << endl;
		cin >> choice;	

	if (choice == 1)
		EncryptRot();
	else if (choice == 2)
		DecryptRot();
	else if (choice == 3)
		EncryptCrypto();
	else if (choice == 4)
		DecryptCrypto();
	else if (choice == 10)
		return;
}


//*********************************************************************************
// TITLE:	EncryptRot
// PURPOSE: Calls the necessary functions in order to encrypt the file with ROT.
// DATE:	06/07/2018
//*********************************************************************************
void EncryptRot() 
{
	string RotInputFile = GetInputFileForRotEncrypt();
	int RotNum = GetRotNum(); //uses the same function as the decryption
	string EROutputfile = GetOutputFileForRotEnc();
	vector<string> V = PlaceWordsIntoVectorForRotEncrypt(RotInputFile);
	vector<string> EncVecForRot = EncryptTheVectorUsingRot(RotNum, V);
	PlaceEncryptedRotIntoFile(EROutputfile, EncVecForRot); 
return;
}


//*********************************************************************************
// TITLE:	DecryptRot
// PURPOSE: Calls the necessary functions in order to decrypt the file with ROT.
// DATE:	06/08/2018
//*********************************************************************************
void DecryptRot() 
{
	string RotDecInputfile = GetInputForRotDecrypt();
	int RotNum = GetRotNum(); //uses the same function as the encryption
	string DROutputfile = GetOutputFileForRotDecrypt();
	vector<string> X = PlaceWordsIntoVectorForRotDecrypt(RotDecInputfile);
	vector<string> DecVecForRot = DecryptTheVectorUsingRot (RotNum, X);
	PlaceDecryptedRotIntoFile(DROutputfile, DecVecForRot); 
return;
}


//*********************************************************************************
// TITLE:	EncryptCrypto
// PURPOSE:	Calls the necessary functions in order to decryptt the file with a 
//			cryptogram.
// DATE:	06/09/2018
//*********************************************************************************
void EncryptCrypto()
{
	string CryptoInputFile = GetInputFileForCryptoEncrypt();
	string Key = ReadCryptoKeyFromFile();
	string ECOutputfile = GetOutputFileForCryptoEncrypt();
	vector<string> PreCryptoEncryptionText = CopyInputFileToVector(CryptoInputFile);
	vector<string> CryptoEncryptedText = EncryptTheStringWithCrypto (PreCryptoEncryptionText, Key);
	PlaceCryptoEncryptIntoFile(ECOutputfile, CryptoEncryptedText);
return;
}


//*********************************************************************************
// TITLE:	DecryptCrypto
// PURPOSE:	Calls the necessary functions in order to decryptt the file with a 
//			cryptogram. 
// DATE:	06/10/2018
//*********************************************************************************
void DecryptCrypto()
{
	string CryptoInputFile = GetInputFileForCryptoDecrypt();
	string Key = ReadCryptoKeyFromFile();
	string DCOutputfile = GetOutputFileForCryptoDecrypt();
	vector<string> PreEncryptedText = CopyEncryptedFileToVector(CryptoInputFile);
	vector<string> CryptoDecryptedText = DecryptTheStringWithCrypto (PreEncryptedText, Key);
	PlaceCryptoDecryptIntoFile(DCOutputfile, CryptoDecryptedText);
return;
}

//#################################################################################
// ROT ENCRYPTION SECTION
//#################################################################################


//*********************************************************************************
// TITLE:	GetRotNum
// PURPOSE: Asks the user to input a number to use for ROT encrypt/decrypt.
//			This function gets called in both encrypt and decrypt.
// DATE:	06/07/2018
//*********************************************************************************
int GetRotNum()
{
	int RotNum;
	
	cout << "Enter n (1-25) for ROT(n):" << endl;
		cin >> RotNum;
	
	while (RotNum < 1 || RotNum > 25)
		{
		cout << "n must be between 1 and 25, please try again:" << endl;
			cin >> RotNum;
		}	
return RotNum;
}


//*********************************************************************************
// TITLE:	GetInputFileForRotEncrypt
// PURPOSE: Asks the user for a file name, returns that filename
// DATE:	06/07/2018
//*********************************************************************************
string GetInputFileForRotEncrypt() 
{
	string FileName;
	cout << "Enter the name of the file to be encrypted using ROT (without the extension)" << endl;
		cin >> FileName;
	FileName = FileName + ".txt";
		
return FileName;
}


//*********************************************************************************
// TITLE:	PlaceWordsIntoVectorForRotEncrypt
// PURPOSE: Reads the data from the users file into a string vector
// DATE:	06/07/2018
//*********************************************************************************
vector<string> PlaceWordsIntoVectorForRotEncrypt(string RotInputFile) 
{
	vector<string> words;
	ifstream fin;
	string w;
	
	fin.open(RotInputFile.data()); 
	
	if(!fin.is_open())
		cout << "Error opening file for ROT vector." << endl;
		
	while (fin >> w)
		words.push_back(w);
		
	fin.close();
	
return words;
}


//*********************************************************************************
// TITLE:	EncryptTheVectorUsingRot
// PURPOSE: Does the encryption on the string vector, and returns in in another 
//			string vector.
// DATE:	06/07/2018
//*********************************************************************************
vector<string> EncryptTheVectorUsingRot(int RotNum, vector<string> V) 
{
	vector<string> EncWordsRot;
	string EncWord;
	
	for (int j=0; j < V.size(); j++)
	{
		EncWord = V[j]; 

		for(int i=0; i < EncWord.size(); i++)
		{
			EncWord[i] = tolower(EncWord[i]);
			
			if ((EncWord[i] < 'a') || (EncWord[i] > 'z'))
				continue;
				
			int k = (int)EncWord[i] + RotNum;	
			if(k > 'z')
				k = k - 26;
			EncWord[i] = (char)k;
		}
		EncWordsRot.push_back(EncWord);
	}
return EncWordsRot;
}


//*********************************************************************************
// TITLE:	GetOutputFileForRotEnc
// PURPOSE: Asks the user for their desired output file name, returns that filename.
// DATE:	06/07/2018
//*********************************************************************************
string GetOutputFileForRotEnc() 
{
	string filename;
	cout << "Provide the output file for Encryption using ROT (without file extension)" << endl;
		cin >> filename;
	filename= filename + ".txt";
return filename;
}


//*********************************************************************************
// TITLE:	PlaceEncryptedRotIntoFile
// PURPOSE: Opens/creates the output file and copies the data to it from the string
//			vector.
// DATE:	06/07/2018
//*********************************************************************************
void PlaceEncryptedRotIntoFile(string EROutputfile, vector<string> EncVecForRot) 
{

	ofstream fileout;
	
	fileout.open(EROutputfile.data(), ios::out);
	
	if(!fileout.is_open())
		cout << "Error opening file." << endl;
	
	for (int i = 0; i < EncVecForRot.size(); i++)
		{
			fileout << EncVecForRot[i] << " ";
		}
	fileout << endl;
	fileout.close();
return;
}


//#################################################################################
// ROT DECRYPTION SECTION
//#################################################################################


//*********************************************************************************
// TITLE:	GetInputForRotDecrypt
// PURPOSE: Asks the user for an input filename for decryption, returns that name.
// DATE:	06/08/2018
//*********************************************************************************
string GetInputForRotDecrypt() 
{
	string FileName;
	cout << "Enter the name of the file to be decrypted using ROT (without the extension):" << endl;
		cin >> FileName;
	FileName = FileName + ".txt";
		
return FileName;
}


//*********************************************************************************
// TITLE:	PlaceWordsIntoVectorForRotDecrypt
// PURPOSE: Reads the data from the users file into a string vector
// DATE:	06/08/2018
//*********************************************************************************
vector<string> PlaceWordsIntoVectorForRotDecrypt(string RotDecInputFile) 
{
	vector<string> words;
	ifstream fin;
	string w;
	
	fin.open(RotDecInputFile.data()); 

	while (fin >> w)
		words.push_back(w);
		
	fin.close();
return words;
}


//*********************************************************************************
// TITLE:	DecryptTheVectorUsingRot
// PURPOSE: Does the decryption on the string vector, and returns in in another 
//			string vector.
// DATE:	06/08/2018
//*********************************************************************************
vector<string> DecryptTheVectorUsingRot(int RotNum, vector<string> X) 
{
	vector<string> DecWordsRot;
	string DecWord;
	
	for (int j=0; j < X.size(); j++)
	{
		DecWord = X[j]; 
		
		for(int i=0; i < DecWord.size(); i++)
		{
			DecWord[i] = tolower(DecWord[i]);
			
			if ((DecWord[i] <'a') || (DecWord[i] > 'z'))
				continue;
			
			int k = (int)DecWord[i] - RotNum;	
			if(k < 'a')
				k = k + 26;
			DecWord[i] = (char)k;
		}
		DecWordsRot.push_back(DecWord);
	}
return DecWordsRot;
}


//*********************************************************************************
// TITLE:	GetOutputFileForRotDecrypt
// PURPOSE: Asks the user for their desired output file name, returns that filename.
// DATE:	06/08/2018
//*********************************************************************************
string GetOutputFileForRotDecrypt() //done
{
	string filename;
	cout << "Provide the output filename for decryption using ROT (without file extension)" << endl;
		cin >> filename;
	filename = filename + ".txt";
return filename;
}


//*********************************************************************************
// TITLE:	PlaceDecryptedRotIntoFile
// PURPOSE: Opens/creates the output file and copies the data to it from the string
//			vector.
// DATE:	06/08/2018
//*********************************************************************************
void PlaceDecryptedRotIntoFile (string DROutputfile, vector<string> DecVecForRot) 
{
	ofstream fileout;
	
	fileout.open(DROutputfile.data(), ios::out);
	
	if(!fileout.is_open())
		cout << "Error opening file." << endl;
	
	for (int i = 0; i < DecVecForRot.size(); i++)
		{
			fileout << DecVecForRot[i] << " ";
		}
	fileout << endl;
	fileout.close();
return;
}


//#################################################################################
// CRYPTOGRAM ENCRYPTION SECTION
//#################################################################################


//*********************************************************************************
// TITLE:	GetInputFileForCryptoEncrypt
// PURPOSE: Asks the user for an input filename for encryption, returns that name.
// DATE:	06/09/2018
//*********************************************************************************
string GetInputFileForCryptoEncrypt() 
{
	string FileName;
	cout << "Enter the name of the file to be encrypted using cryptogram (without the extension)" << endl;
		cin >> FileName;
	FileName = FileName + ".txt";
		
return FileName;
}


//*********************************************************************************
// TITLE:	ReadCryptoKeyFromFile
// PURPOSE: Reads the cryptogram from cryptogram.txt and stores it in a string.
// DATE:	06/09/2018
//*********************************************************************************
string ReadCryptoKeyFromFile()
{
	ifstream fin;
	string Key;

	fin.open("cryptogram.txt");
	
	if(!fin.is_open())
		cout << "Error opening file." << endl;

	for(int j=0; j<26; j++)
    	{
      	fin>>Key;
    	}
	fin.close();
return Key;
}


//*********************************************************************************
// TITLE:	CopyInputFileToVector
// PURPOSE: Copies the data from the original file to the vector, returns the vector.
// DATE:	06/11/2018
//*********************************************************************************
vector<string> CopyInputFileToVector(string CryptoInputFile)
{
	vector<string> words;
	ifstream fin;
	string w;
	
	fin.open(CryptoInputFile.data()); // .data() because file name is a variable

	if(!fin.is_open())
		cout << "Error opening file." << endl;
		
	while (fin >> w)
		words.push_back(w);
		
	fin.close();
	return words;
}


//*********************************************************************************
// TITLE:	EncryptTheStringWithCrypto
// PURPOSE: Applies the encryption to the data as it is read from the file.
// DATE:	06/09/2018
//*********************************************************************************
vector<string> EncryptTheStringWithCrypto (vector<string> PreCryptoEncryptionText, string Key) 
{
	string temp;
	vector<string>Encryptvecusingcrypto;

	for (int i=0; i < PreCryptoEncryptionText.size(); i++)
	{
	    temp = PreCryptoEncryptionText[i];
    
	    for(int i=0; i < temp.size(); i++)
    		{
			temp[i] = tolower(temp[i]);
			}
			
		for(int k=0; k<temp.size();k++)
   		{
      	int ch;
      	ch=temp[k];
      	if((ch>='a') && (ch<='z'))
        	{
          	int index = ch - 'a';
          	temp[k] = Key[index];
        	}
   		}
    Encryptvecusingcrypto.push_back(temp);
	}
return Encryptvecusingcrypto; 
}


//*********************************************************************************
// TITLE:	GetOutputFileForCryptoEncrypt
// PURPOSE: Asks the user for an output filename for encryption, returns that name.
// DATE:	06/09/2018
//*********************************************************************************
string GetOutputFileForCryptoEncrypt() 
{
	string filename;
	cout << "Provide the output file for Encryption using cryptogram (without file extension)" << endl;
		cin >> filename;
	filename = filename + ".txt";
return filename;
}


//*********************************************************************************
// TITLE:	PlaceCryptoEncryptIntoFile
// PURPOSE: Opens/creates the output file and copies the data to it from the string
//			vector.
// DATE:	06/09/2018
//*********************************************************************************
void PlaceCryptoEncryptIntoFile(string ECOutputfile, vector<string> CryptoEncryptedText) // not writing file
{
	ofstream fileout;
	
	fileout.open(ECOutputfile.data());
	
	if(!fileout.is_open())
		cout << "Error opening file." << endl;

    for(int i = 0; i < CryptoEncryptedText.size(); i++)
    	fileout << CryptoEncryptedText[i] << " ";
    	fileout << endl;
	fileout.close();
return;
}


//#################################################################################
// CRYPTOGRAM DECRYPTION SECTION
//#################################################################################


//*********************************************************************************
// TITLE:	GetInputFileForCryptoDecrypt
// PURPOSE: Asks the user for an input filename for decryption, returns that name.
// DATE:	06/10/2018
//*********************************************************************************
string GetInputFileForCryptoDecrypt() 
{
	string FileName;
	cout << "Enter the name of the file to be decrypted using cryptogram (without the extension)" << endl;
		cin >> FileName;
	FileName = FileName + ".txt";
		
return FileName;
}

//*********************************************************************************
// TITLE:	CopyEncryptedFileToVector
// PURPOSE: Copies data from encrypted source file to the vector, returns the vector.
// DATE:	06/11/2018
//*********************************************************************************
vector<string> CopyEncryptedFileToVector(string CryptoInputFile)
{
	vector<string> words;
	ifstream fin;
	string w;
	
	fin.open(CryptoInputFile.data()); // .data() because file name is a variable

	if(!fin.is_open())
		cout << "Error opening file." << endl;
		
	while (fin >> w)
		words.push_back(w);
		
	fin.close();
	
return words;
}
//*********************************************************************************
// TITLE:	DecryptTheStringWithCrypto
// PURPOSE: Applies the decryption to the data as it is read from the file.
// DATE:	06/10/2018
//*********************************************************************************
vector<string> DecryptTheStringWithCrypto (vector<string> PreEncryptedText, string Key) 
{
	string word;
	vector<string> Encryptvecusingcrypto;
	
	for (int i=0; i < PreEncryptedText.size(); i++)
	{
		word = PreEncryptedText[i];
		for (int j=0; j < word.size(); j++)
		{
			if ((word[j] < 'a') || (word[j] > 'z'))
			continue;
			
			string pattern = ".";
			pattern[0] = word[j];
			int index = Key.find(pattern, 0);
			word[j] = 'a' + index;
		}
		Encryptvecusingcrypto.push_back(word);
	}
	return Encryptvecusingcrypto;
}


//*********************************************************************************
// TITLE:	GetOutputFileForCryptoDecrypt
// PURPOSE: Asks the user for an output filename for encryption, returns that name.
// DATE:	06/10/2018
//*********************************************************************************
string GetOutputFileForCryptoDecrypt() 
{
	string filename;
	cout << "Provide the output file for decryption using cryptogram (without file extension)" << endl;
	cin >> filename;
	filename = filename + ".txt";
	return filename;
}


//*********************************************************************************
// TITLE:	PlaceCryptoDecryptIntoFile
// PURPOSE: Opens/creates the output file and copies the data to it from the string
//			vector.
// DATE:	06/10/2018
//*********************************************************************************
void PlaceCryptoDecryptIntoFile(string DCOutputfile, vector<string> CryptoDecryptedText) 
{
	ofstream fileout;
	
	fileout.open(DCOutputfile.data());
	
	if(!fileout.is_open())
		cout << "error creating file" << endl;
	
    for(int i=0;i< CryptoDecryptedText.size();i++)
      {
  		fileout<< CryptoDecryptedText[i] << " ";
      }
    fileout << endl;
	fileout.close();
}
