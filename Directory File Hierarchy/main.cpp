

// 171044086 _HAMZA _YOĞURTCUOĞLU   18:30 11.05.2018 
	
/*
	
	DİKKAT commands.txt dosyasındaki formatta test ediniz. 
	Örnek : 
			copy directory0/directory1/directory2/file1 /directory0/directory1
			cd directory0/directory1
			move directory1/directory2/BenimDosyam /directory1
			cd directory0/directory1/directory2
			cd ..
			cd /
			delete directory0/directory1/directory2/BenimDosyam 
	COMPILER (MAKEFILE) :
			make   (dosyaları derler)	
			make clean  (obje kodları siler)
			make run (exe dosyasını çalıştırır) ---- veya ./exe	
*/				

/*	
	Dosya dizini oluşturan program.
 	Komutlar :  delete 
				move
				copy
				cd
				cd ..
				cd /
*/
#include<iostream>
#include "baseClass.h"
#include "directoryFilesClass.h"
using namespace std;


int main()
{	
	linkedListClass * linkedListObject; 		//bağlantıları tüm bağlantıları tutan obje
	linkedListObject = new linkedListClass ;	//files.txt bu obje içinde okunur ve linkedlist bağlantıları burada yapılır
	
	currentDirectoryClass * currentDirectoryObject ;	//commands.txt bu obje içinde okunur ve gerekli işlemler orada yapılır
	currentDirectoryObject = new currentDirectoryClass(linkedListObject) ;

	string documentaryLine ; //bu string sayesinde uç uca eklenir ve dokümanlar ekrana yazdırılır
	ofstream writeFile;
	writeFile.open("output.txt"); 
	linkedListObject->outputTxt(documentaryLine,writeFile);	//output.txt dosyasına yazma işlemi gerçekleşir.

	return 0;
}