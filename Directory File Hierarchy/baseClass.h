
//ASSIGNMENT_5

//HAMZA YOĞURTCUOĞLU
//171044086

/*
	BASECLASS HEADERLARI İÇERİR.
	COPY , MOVE , DELETE KOMUTLARININ
	FONKSİYONLARININ HEADERLARINI İÇERİR.

*/

#ifndef	BASE_CLASS
#define	BASE_CLASS

#include<string>
#include<iostream>
#include<fstream>

using namespace std;

class baseClass
{
	public:
		virtual void setName(string name) {copyName = name ;}
		virtual baseClass * linkedDirectory(string tempLine,string previousDirectory,baseClass * rootPointer) {}
		virtual baseClass * exitsOrNot(string previousDirectory){}
		virtual string getName(){return copyName ; }
		virtual baseClass * linkedFile(string tempLine,string previousDirectory,baseClass * rootPointer){}	
		virtual string controlDocumentary(){}	
		virtual	baseClass * controlCurrent(string tempLine){}
		virtual baseClass * linkedNext(string tempLine,string previousDirectory,baseClass * rootPointer){}
		void outputRecursiveControl(string documentaryLine,ofstream & writeFile);
		void outputRecursiveControlNext(string documentaryLine,ofstream & writeFile);	
		void copyDirectoryFiles(string copyDocument,string preTempLine,string tempLine,baseClass * currentDirectory);
		void copyDirectoryFiles2(string copyDocument,string preTempLine,baseClass * currentDirectory);
		baseClass * copyDocument(string copyDocument,string preTempLine);
		baseClass * copyDocument2(string copyDocument,string preTempLine);
		void moveDirectoryFiles(string copyDocument,string preTempLine,string tempLine,baseClass * currentDirectory);
		void moveDirectoryFiles2(string copyDocument,string preTempLine,baseClass * currentDirectory);
		baseClass * moveDocument(string copyDocument,string preTempLine);
		baseClass * moveDocument2(string copyDocument,string preTempLine);
		int deleteControl(string tempLine);
		void deleteFile2(string tempLine);
		void deleteFile(string preTempLine,string tempLine);
		void deleteDirectory(string tempLine);
		baseClass();
		~baseClass();
		baseClass * inFile ;   //DÖKÜMANLARINI BİRBİRİNE BAĞLAYACAK POİNTERLAR
		baseClass * next ; 		//YANINDAKİ DÖKÜMANI GÖSTEREN POİNTER
		baseClass * inNext ; 	//İÇİNDEKİ DÖKÜMNALARINI GÖSTEREN POINTER
		baseClass * outNext ;	//İÇİNDE OLDUĞU KLASORU GÖSTEREN POINTER
		baseClass * preNext ;	//ONCEKI NEXTI GOSTEREN POINTER
	protected:
		string copyName;	

};
	

#endif
