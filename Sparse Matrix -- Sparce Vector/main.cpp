//Assignment_3_HamzaYoğurtcuoğlu_171044086.cpp


//Bu dosya matrix için 
//Yapılabilen işlemler:
// Assignment
// + , - (binary) , -(unary), << ,read file

//Bu dosya vector dosya vector için
//Yapılabilen işlemler:
// Assignment
// + , - (binary) , -(unary), << ,read file , dot product

//Makefile komutları
//make --> compiler eder.
//make clean --> .o uzantılı dosyalarını siler
//make run --> dosyayı çalıştırır.

#include "SparseMatrix.h"
#include "SparseVector.h"

using namespace std ;


int main(int argc, char const *argv[])
{
	ofstream outfile;
	
	outfile.open("output.txt", ios::out | ios::trunc );
	
	//Creating a SparseVector from file
	
	SparseVector a1 ("a1.txt");
	
	SparseVector a2 ("a2.txt");

	outfile<<"a1"<<endl<<a1<<endl;
	
	outfile<<"a2"<<endl<<a2<<endl;

	//Binary operations and assignment
	
	 a1 = a1 + a2 + a1 ;
	
	outfile<<"a1"<<endl<<a1<<endl;
	
	 a1 = a1 - a2;
	
	outfile<<"a1"<<endl<<a1<<endl;
	outfile<<"a2"<<endl<<a2<<endl;

	-a2;
	
	outfile<<"a2"<<endl<<a2<<endl;

	//Dot product
	outfile<<dot(a1,a1)<<endl;

	//Dot product
	outfile<<dot(a1,a2)<<endl;  


	//Creating SparseMatrix from file
	
	SparseMatrix m1("m1.txt");
	
	SparseMatrix m2("m2.txt");
	
	outfile<<"m1"<<endl<<m1<<endl;
	
	outfile<<"m2"<<endl<<m2<<endl;

	m1 = m1 - m2 -m2;

	outfile<<"m1"<<endl<<m1<<endl;

	m1 = m1 + m2 ;

	outfile<<"m1"<<endl<<m1<<endl;

	-m1;
	
	outfile<<"m2"<<endl<<m2<<endl;
	
	outfile<<"m1"<<endl<<m1<<endl;

	return 0;
}
