

//ASSIGNMENT_5

//HAMZA YOĞURTCUOĞLU
//171044086

/*
--1-)directoryClass
--2-)filesClass
--3-)linkedListClass
--4-)currentDirectoryClass
	headerları içermektedir.
	
*/


#ifndef DIRECTORY_FILE_HEADER
#define DIRECTORY_FILE_HEADER
#include <iostream>
#include<sstream>
#include<string>
#include<fstream>
#include "baseClass.h"

using namespace std;

class directoryClass : public baseClass
{
	public:
	string getName(){return directoryName ;}
	void setName(string name){directoryName = name ;}
	string controlDocumentary(){return thisIsType;}
	baseClass * exitsOrNot(string previousDirectory);
	baseClass * linkedDirectory(string tempLine , string previousDirectory,baseClass * rootPointer);
	baseClass * linkedFile(string tempLine , string previousDirectory,baseClass * rootPointer);
	baseClass * controlCurrent(string tempLine);
	private:
		string directoryName;
		string thisIsType = "DIRECTORY" ; 	//directory klasörünün tür belirteci
};

class filesClass : public baseClass 
{
	public:
	string controlDocumentary(){return thisIsType;}
	string getName(){return fileName ;}
	baseClass * exitsOrNot(string previousDirectory);
	void setName(string name){fileName = name ;}
	baseClass * linkedNext(string tempLine,string previousDirectory,baseClass * rootPointer);
	private:
		string fileName ;
		string thisIsType = "FILE";		//files classının tür belirteci
};

class linkedListClass : public baseClass
{
	public:
		linkedListClass();
		~linkedListClass(){delete rootPointer ;}
		baseClass * rootPointer ; //ana root en baş root olarak atanır (linkedlist oluştururken en başı root seçilir) 
		void outputTxt(string documentaryLine,ofstream & writeFile);

};

class currentDirectoryClass : public baseClass
{
	public:
		currentDirectoryClass(linkedListClass * linkedListObject); //
		~currentDirectoryClass(){delete currentDirectory;}
	private :
		baseClass * currentDirectory;	//kullanıcının bulunduğu directoryi gösteren pointer	
};										//ilk currentdirectory rootdirectorydir.		

#endif