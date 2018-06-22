//Assignment_3_HamzaYoğurtcuoğlu_171044086.cpp
//Bu dosya matrix headerları içerir.
//Yapılabilen işlemler:
// Assignment
// + , - (binary) , -(unary), << ,read file

//Makefile komutları
//make --> compiler eder.
//make clean --> .o uzantılı dosyalarını siler
//make run --> dosyayı çalıştırır.

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H
#include <sstream>
#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;
class Cell2
{
	public:
		Cell2(){};
		~Cell2(){};
		inline int getColumn()const{return column ;}					
		inline void setColumn(int columnT){column = columnT ;}
		inline double getData()const{return data ;}
		inline void setData(double dataT){data = dataT ;}
		inline void setRow(int rowT){ row = rowT ;}
		inline int getRow()const{return row ;}
	private:
		int column;
	    double data ;
	    int row ;
};

class SparseMatrix
{
	public:
		SparseMatrix(){}	
		SparseMatrix(string textFile);
		~SparseMatrix(){
			if (!eachCordinate)
        			delete eachCordinate;
		}
		SparseMatrix operator +(SparseMatrix & m1);
		SparseMatrix & operator - ();
		SparseMatrix operator - (SparseMatrix & m1);
		SparseMatrix & operator=(const SparseMatrix & m1);
	friend ostream & operator <<(ostream & outfile, SparseMatrix & m1);
	//	void transpose ();
	private:
		vector<vector<Cell2>>matrixObject ;
		vector<Cell2>rowVector;
		vector<int>keepingIndex  ; //bu vektör matrixsin her rowun , column sayısını tutar
		int index = 0;		//geçici olarak column sayısını tutar(keeping vectorune column sayısına atabilmek için)
		int index2 = 0 ; 	//row sayısını tutar
		Cell2 * eachCordinate ;
};

ostream & operator <<(ostream & outfile, SparseMatrix & m1);

#endif
