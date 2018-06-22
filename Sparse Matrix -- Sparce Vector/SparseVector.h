//Assignment_3_HamzaYoğurtcuoğlu_171044086.cpp
//Bu dosya vector headerları içerir.
//Yapılabilen işlemler:
// Assignment
// + , - (binary) , -(unary), << ,read file , dot product

//Makefile komutları
//make --> compiler eder.
//make clean --> .o uzantılı dosyalarını siler
//make run --> dosyayı çalıştırır.

#ifndef SPARSEVECTOR_H
#define SPARSEVECTOR_H
#include<cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
//Vectörün her bir cellinin değer ve hangi satır olduğunu tutan class
class Cell
{
	public:
		Cell(){};
		~Cell(){};
		inline int getColumn()const{return column;}					
		inline void setColumn(int columnT){column = columnT ;}
		inline double getData()const{return data;}
		inline void setData(double dataT){data = dataT ;}
		inline char getColon()const{return colon;}
	private:
		int column;
	    double data ;
	    char colon  = ':';
};
//0 datada yer almayan operator overload içeren ve Cell vektörü içeren class
class SparseVector
{
	public:
		SparseVector(){}
		SparseVector(string textName);
        inline ~SparseVector(){	
        	   if (!eachCordinate)
        			delete eachCordinate;
        }
		SparseVector operator +(SparseVector & a1);
		SparseVector & operator=(const SparseVector & a1);
		SparseVector operator -(SparseVector & a1);	
		SparseVector & operator -();
		friend ostream & operator <<(ostream & outfile, SparseVector & a1);	
		friend double dot(const SparseVector & a1,const SparseVector & a2);
	private : 
		vector <Cell> vectorObject;
		int index = 0; //vektörün sıfırdan farklı kaç elemanı olduğunu tutar	
	    Cell * eachCordinate ;	    
};

ostream & operator <<(ostream & outfile, SparseVector & a1);
double dot(const SparseVector & a1,const SparseVector & a2);
#endif