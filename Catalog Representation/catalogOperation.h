
//ASSIGNMENT_6

//HAMZA YOĞURTCUOĞLU
//171044086

/*

	Veri Alınan Dosyalar	
		data.txt
		commands.txt
	Verilerin Yazdırıldığı Dosya
		output.txt

*/

#ifndef CATALOGOPERATION
#define CATALOGOPERATION
#include "catalogType.h"
#include<string>
#include<vector>	//Veriler vectorlerde tutuldu.
#include<iostream>
#include<fstream>
#include<sstream>
#include<set>	//sort işlemi için set template kullanıldı.

using namespace std;

class catalogOperation
{
	public:
		catalogOperation();	//Bu constructor data.txt alınan veriler vektördeki yere yerleştirilir. 
		~catalogOperation();
		void uniqueEntries(ofstream & writeFile);	//unique dökümanlar bulunur exception olarak yazılır.
		void sortSearch(ofstream & writeFile);
		int getUniqueMember(){return uniqueMember;}	
		void setUniqueMember(){uniqueMember++;}
		int getSearchControl(){return searchControl;}
		void setSearchControl(){searchControl++;}
		void resetSearchControl(){searchControl = 0;}
	private:
		int searchControl = 0 ; //eğer herhangi bir search yapacak işlem çıkmazsa
		string operationString ;
		int index = 0; // catalog içinde var olan kitap , film veya müzik sayısını tutar.
		vector<catalogMusic >musicS ;
		vector<catalogMovie >movieS;
		vector<catalogBook >bookS;
		catalogMovie * movieObject ;
		catalogMusic * musicObject;
		catalogBook * bookObject;	
		int uniqueMember = 0;		//unique entries sayısı tutulur.

};

#endif