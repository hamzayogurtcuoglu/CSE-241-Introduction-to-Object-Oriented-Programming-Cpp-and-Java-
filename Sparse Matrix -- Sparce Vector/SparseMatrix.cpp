
//Assignment_3_HamzaYoğurtcuoğlu_171044086.cpp
//Bu dosya matrix fonksiyonları içerir.
//Yapılabilen işlemler:
// Assignment
// + , - (binary) , -(unary), << ,read file

//Makefile komutları
//make --> compiler eder.
//make clean --> .o uzantılı dosyalarını siler
//make run --> dosyayı çalıştırır.

#include "SparseMatrix.h"

using namespace std;

SparseMatrix::SparseMatrix(string textFile)
{
	string allLine2;

	string tempLine;	

	int firstFileTakeRow;

	ifstream takeFile ;

	takeFile.open(textFile);

	while(std::getline(takeFile,allLine2)){
		
		index = 0 ;

		istringstream allLine1 (allLine2);	//alınan string allLine1 stringine assign edilir
		
		matrixObject.push_back(rowVector); //vector içine vector atılıyor

		eachCordinate = new Cell2 ;	   //herbir row için bir Cell.

		matrixObject[index2].push_back (*eachCordinate) ;	//push_back ediliyor.

		if (std::getline(allLine1,tempLine,' ')){			//alınan satır parse ediliyor
			matrixObject[index2][index].setRow(stoi(tempLine));	//row değeri assign ediliyor.

			while(std::getline(allLine1,tempLine,':')){			//column degeri bulunuyor

				matrixObject[index2][index].setColumn(stoi(tempLine));	//ve assign ediliyor.
				
				if (std::getline(allLine1,tempLine,' '))				//columnun datası bulunup gerekli celle assign ediliyor
					matrixObject[index2][index].setData(stod(tempLine));

				index++;
				
				eachCordinate = new Cell2 ;

				matrixObject[index2].push_back (*eachCordinate) ;
			}
		}
		keepingIndex.push_back(index);
		index2++;
	}
}

ostream & operator <<(ostream & outfile, SparseMatrix & m1)
{
	for (int i = 0; i < m1.index2; ++i)
	{
		for (int j = 0; j < m1.keepingIndex[i]; ++j)
		{
			if (j==0){
			   outfile<<m1.matrixObject[i][j].getRow();
			   outfile<<" ";
			}
			outfile<<m1.matrixObject[i][j].getColumn();
			outfile<<':';
			outfile<<m1.matrixObject[i][j].getData();
			outfile<<" ";
		}
		
		outfile<<endl;	
	}
	return outfile ;
}

//matrisin elemanlarını eksiler
SparseMatrix & SparseMatrix::operator - ()
{
	for (int i = 0; i < index2; ++i){
		for (int j = 0; j < keepingIndex[i]; ++j)		
			matrixObject[i][j].setData( -matrixObject[i][j].getData());
	}
}

SparseMatrix SparseMatrix::operator +(SparseMatrix & m1){

	SparseMatrix tempObject;

	int rowIndex = 0 ,rowIndex1 = 0 ;

	//herhangi bir matrixin rowu bitene kadar dönen döngü
	while((index2 != rowIndex)&& (m1.index2 != rowIndex1)){

		int leftObjectIndex = 0 , rightObjectIndex = 0 ;

		tempObject.matrixObject.push_back(rowVector); //vector içine vector atılıyor

		//eğer rowlar eşitse bu o eşitlikteki columnlar toplanır.
		if (matrixObject[rowIndex][leftObjectIndex].getRow() == m1.matrixObject[rowIndex1][rightObjectIndex].getRow()){
			
			//herhangi bir matrixin column bitene kadar dönen döngü
			while((leftObjectIndex != keepingIndex[rowIndex]) && (rightObjectIndex != m1.keepingIndex[rowIndex1])){
				//eğercolumlar aynıysa bu sorguya girer
				if (matrixObject[rowIndex][leftObjectIndex].getColumn() == matrixObject[rowIndex1][rightObjectIndex].getColumn()){
					eachCordinate = new Cell2 ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex][leftObjectIndex].getColumn());
					tempObject.matrixObject[tempObject.index2][0].setRow(matrixObject[rowIndex][0].getRow());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(matrixObject[rowIndex][leftObjectIndex].getData() + m1.matrixObject[rowIndex1][rightObjectIndex].getData());
					tempObject.index++;
					leftObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
					rightObjectIndex++;
				}else if (matrixObject[rowIndex][leftObjectIndex].getColumn() < matrixObject[rowIndex1][rightObjectIndex].getColumn()){
					eachCordinate = new Cell2 ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex][leftObjectIndex].getColumn());
					tempObject.matrixObject[tempObject.index2][0].setRow(matrixObject[rowIndex][0].getRow());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(matrixObject[rowIndex][leftObjectIndex].getData());
					tempObject.index++;
					leftObjectIndex++;				// eğer left column küçükse datalar  geçici objeye atanır...
						
				}else if (matrixObject[rowIndex][leftObjectIndex].getColumn() > matrixObject[rowIndex1][rightObjectIndex].getColumn()){
					eachCordinate = new Cell2 ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(m1.matrixObject[rowIndex1][rightObjectIndex].getColumn());
					tempObject.matrixObject[tempObject.index2][0].setRow(matrixObject[rowIndex][0].getRow());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(m1.matrixObject[rowIndex1][rightObjectIndex].getData());
					tempObject.index++;
					rightObjectIndex++;			// eğer right column varsa data geçici objeye atanır...
				}
			}
			
			if (leftObjectIndex != keepingIndex[rowIndex]){
				while(leftObjectIndex != keepingIndex[rowIndex]){
					eachCordinate = new Cell2 ;							// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(matrixObject[rowIndex][leftObjectIndex].getData());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex][leftObjectIndex].getColumn());
					tempObject.index++;
					leftObjectIndex++;
				}

			}else if (rightObjectIndex != m1.keepingIndex[rowIndex1]){
					eachCordinate = new Cell2 ;							// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(m1.matrixObject[rowIndex1][rightObjectIndex].getData());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(m1.matrixObject[rowIndex1][rightObjectIndex].getColumn());
					tempObject.index++;
					rightObjectIndex++;				
			}			
			tempObject.keepingIndex.push_back(tempObject.index);
			tempObject.index = 0;
			rowIndex++;
			rowIndex1++;
			tempObject.index2++;

		}else if (matrixObject[rowIndex][leftObjectIndex].getRow() < m1.matrixObject[rowIndex1][rightObjectIndex].getRow()){
			while(leftObjectIndex != keepingIndex[rowIndex]){
					eachCordinate = new Cell2 ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex][leftObjectIndex].getColumn());
					tempObject.matrixObject[tempObject.index2][0].setRow(matrixObject[rowIndex][0].getRow());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(matrixObject[rowIndex][leftObjectIndex].getData());
					tempObject.index++;
					leftObjectIndex++;	
			}
			tempObject.keepingIndex.push_back(tempObject.index);
			tempObject.index = 0;
			rowIndex++;
			tempObject.index2++;
		}else if (matrixObject[rowIndex][leftObjectIndex].getRow() > m1.matrixObject[rowIndex1][rightObjectIndex].getRow()){
			while(rightObjectIndex != m1.keepingIndex[rowIndex1]){
					eachCordinate = new Cell2 ;							// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][0].setRow(m1.matrixObject[rowIndex1][0].getRow());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(m1.matrixObject[rowIndex1][rightObjectIndex].getData());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(m1.matrixObject[rowIndex1][rightObjectIndex].getColumn());
					tempObject.index++;
					rightObjectIndex++;	
			}
			tempObject.keepingIndex.push_back(tempObject.index);
			tempObject.index = 0;
			rowIndex1++;
			tempObject.index2++;
		}		
	}	
	//eğer herhangi bir row kalmış ise bu sorgularda tempObjecte assign edilir.
	if (index2 != rowIndex){
		while(index2 != rowIndex){
			tempObject.matrixObject.push_back(rowVector); //vector içine vector atılıyor	
			tempObject.index = 0;	
			int leftObjectIndex = 0 ;
			while(leftObjectIndex != keepingIndex[rowIndex]){
				eachCordinate = new Cell2 ;
				tempObject.matrixObject[tempObject.index2].push_back(*eachCordinate);
				tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex][leftObjectIndex].getColumn());
				tempObject.matrixObject[tempObject.index2][0].setRow(matrixObject[rowIndex][0].getRow());
				tempObject.matrixObject[tempObject.index2][tempObject.index].setData(matrixObject[rowIndex][leftObjectIndex].getData());
				tempObject.index++;
				leftObjectIndex++;	
			}
			tempObject.keepingIndex.push_back(tempObject.index);
			tempObject.index2++; // temp objenin row sayısını artırıldığını belirtiyor.
			rowIndex++;
		}
	}else if (m1.index2 != rowIndex1){
		while(m1.index2 != rowIndex1){
			tempObject.matrixObject.push_back(rowVector); //vector içine vector atılıyor	
			tempObject.index = 0;	
			int rightObjectIndex = 0 ;
			while(rightObjectIndex != m1.keepingIndex[rowIndex1]){
				eachCordinate = new Cell2 ;
				tempObject.matrixObject[tempObject.index2].push_back(*eachCordinate);
				tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex1][rightObjectIndex].getColumn());
				tempObject.matrixObject[tempObject.index2][0].setRow(m1.matrixObject[rowIndex1][0].getRow());
				tempObject.matrixObject[tempObject.index2][tempObject.index].setData(m1.matrixObject[rowIndex1][rightObjectIndex].getData());
				tempObject.index++;
				rightObjectIndex++;	
			}
			tempObject.keepingIndex.push_back(tempObject.index);
			tempObject.index2++; // temp objenin row sayısını artırıldığını belirtiyor.
			rowIndex1++;
		}
	}

	return tempObject;
}

//Sağ matrisi sol matrise assign eder.
SparseMatrix & SparseMatrix::operator=(const SparseMatrix & m1)
{
	int leftObjectRow = 0 , rightObjectRow = 0 ;	//dongu için gerekli row templeri
	int tempRow = index2 ;
	int tempIndex;
	index2 = m1.index2 ;
	while(rightObjectRow != m1.index2){
		//eğer aassign edilecek objenin row u küçükse ona vector push edilir.
		if (tempRow <= leftObjectRow){
			this->matrixObject.push_back(rowVector);
			this->keepingIndex.push_back(m1.keepingIndex[rightObjectRow]);
			tempIndex = 0;
			eachCordinate = new Cell2 ;
			matrixObject[leftObjectRow].push_back(*eachCordinate);
		}
		//küçük değilse sadece atama işlemleri yapılır.
		else{ 
				
			tempIndex = keepingIndex[leftObjectRow];
			this->keepingIndex[leftObjectRow] = m1.keepingIndex[rightObjectRow] ;
		}
		int leftObjectIndex = 0 , rightObjectIndex = 0 ;
		this->matrixObject[leftObjectRow][leftObjectIndex].setRow(m1.matrixObject[rightObjectRow][rightObjectIndex].getRow());
		//bu assign edilecen rowun  bir  column uzunluğuna kadar döngü devam eder 
		while(rightObjectIndex != m1.keepingIndex[rightObjectRow]){
			if (tempIndex == 0){
				eachCordinate = new Cell2 ;
				matrixObject[leftObjectRow].push_back(*eachCordinate);
			}
			else if (tempIndex<=leftObjectIndex){
				eachCordinate = new Cell2 ;
				matrixObject[leftObjectRow].push_back(*eachCordinate);
			}
			matrixObject[leftObjectRow][leftObjectIndex].setData(m1.matrixObject[rightObjectRow][rightObjectIndex].getData());
			matrixObject[leftObjectRow][leftObjectIndex].setColumn(m1.matrixObject[rightObjectRow][rightObjectIndex].getColumn());
			leftObjectIndex++;
			rightObjectIndex++;
		}
		rightObjectRow++;
		leftObjectRow++;
	}	
	return *this ;
}
SparseMatrix SparseMatrix::operator -(SparseMatrix & m1){
	
	SparseMatrix tempObject;
	int rowIndex = 0 ,rowIndex1 = 0 ;
	//herhangi bir matrixin rowu bitene kadar dönen döngü
	while((index2 != rowIndex)&& (m1.index2 != rowIndex1)){
		int leftObjectIndex = 0 , rightObjectIndex = 0 ;

		tempObject.matrixObject.push_back(rowVector); //vector içine vector atılıyor

		//eğer rowlar eşitse bu o eşitlikteki columnlar toplanır.
		if (matrixObject[rowIndex][leftObjectIndex].getRow() == m1.matrixObject[rowIndex1][rightObjectIndex].getRow()){
			
			//herhangi bir matrixin column bitene kadar dönen döngü
			while((leftObjectIndex != keepingIndex[rowIndex]) && (rightObjectIndex != m1.keepingIndex[rowIndex1])){
				//eğercolumlar aynıysa bu sorguya girer
				if (matrixObject[rowIndex][leftObjectIndex].getColumn() == matrixObject[rowIndex1][rightObjectIndex].getColumn()){
					//eğer columnlar eşit yani sonuç sıfırsa aşağıdaki işlemler gerçekleşir 
					if (0 != (matrixObject[rowIndex][leftObjectIndex].getData() - m1.matrixObject[rowIndex1][rightObjectIndex].getData())){
						eachCordinate = new Cell2 ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
						tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
						tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex][leftObjectIndex].getColumn());
						tempObject.matrixObject[tempObject.index2][0].setRow(matrixObject[rowIndex][0].getRow());
						tempObject.matrixObject[tempObject.index2][tempObject.index].setData(matrixObject[rowIndex][leftObjectIndex].getData() - m1.matrixObject[rowIndex1][rightObjectIndex].getData());
						tempObject.index++;
					}
					leftObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
					rightObjectIndex++;
				}else if (matrixObject[rowIndex][leftObjectIndex].getColumn() < matrixObject[rowIndex1][rightObjectIndex].getColumn()){
					eachCordinate = new Cell2 ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex][leftObjectIndex].getColumn());
					tempObject.matrixObject[tempObject.index2][0].setRow(matrixObject[rowIndex][0].getRow());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(matrixObject[rowIndex][leftObjectIndex].getData());
					tempObject.index++;
					leftObjectIndex++;				// eğer left column küçükse datalar  geçici objeye atanır...
						
				}else if (matrixObject[rowIndex][leftObjectIndex].getColumn() > matrixObject[rowIndex1][rightObjectIndex].getColumn()){
					eachCordinate = new Cell2 ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(m1.matrixObject[rowIndex1][rightObjectIndex].getColumn());
					tempObject.matrixObject[tempObject.index2][0].setRow(matrixObject[rowIndex][0].getRow());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(-m1.matrixObject[rowIndex1][rightObjectIndex].getData());
					tempObject.index++;
					rightObjectIndex++;			// eğer right column varsa data geçici objeye atanır...
				}
			}
			
			if (leftObjectIndex != keepingIndex[rowIndex]){
				while(leftObjectIndex != keepingIndex[rowIndex]){
					eachCordinate = new Cell2 ;							// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(matrixObject[rowIndex][leftObjectIndex].getData());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex][leftObjectIndex].getColumn());
					tempObject.index++;
					leftObjectIndex++;
				}

			}else if (rightObjectIndex != m1.keepingIndex[rowIndex1]){
					eachCordinate = new Cell2 ;							// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(-m1.matrixObject[rowIndex1][rightObjectIndex].getData());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(m1.matrixObject[rowIndex1][rightObjectIndex].getColumn());
					tempObject.index++;
					rightObjectIndex++;				
			}			
			if (tempObject.index == 0){
				tempObject.matrixObject.pop_back();	//eğer 0 row varsa o pop_back yapılır direk.
				rowIndex++;
				rowIndex1++;
			}else{
				tempObject.keepingIndex.push_back(tempObject.index);
				tempObject.index = 0;
				rowIndex++;
				rowIndex1++;
				tempObject.index2++;
			}
			
		}else if (matrixObject[rowIndex][leftObjectIndex].getRow() < m1.matrixObject[rowIndex1][rightObjectIndex].getRow()){
			while(leftObjectIndex != keepingIndex[rowIndex]){
					eachCordinate = new Cell2 ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex][leftObjectIndex].getColumn());
					tempObject.matrixObject[tempObject.index2][0].setRow(matrixObject[rowIndex][0].getRow());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(matrixObject[rowIndex][leftObjectIndex].getData());
					tempObject.index++;
					leftObjectIndex++;	
			}
			tempObject.keepingIndex.push_back(tempObject.index);
			tempObject.index = 0;
			rowIndex++;
			tempObject.index2++;
		}else if (matrixObject[rowIndex][leftObjectIndex].getRow() > m1.matrixObject[rowIndex1][rightObjectIndex].getRow()){
			while(rightObjectIndex != m1.keepingIndex[rowIndex1]){
					eachCordinate = new Cell2 ;							// vektörün her bir elemanını  dynamic bir eleman atanıyor
					tempObject.matrixObject[tempObject.index2].push_back (*eachCordinate) ;	//push_back ediliyor.
					tempObject.matrixObject[tempObject.index2][0].setRow(m1.matrixObject[rowIndex1][0].getRow());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setData(-m1.matrixObject[rowIndex1][rightObjectIndex].getData());
					tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(m1.matrixObject[rowIndex1][rightObjectIndex].getColumn());
					tempObject.index++;
					rightObjectIndex++;	
			}
			tempObject.keepingIndex.push_back(tempObject.index);
			tempObject.index = 0;
			rowIndex1++;
			tempObject.index2++;
		}		
	}	
	//eğer herhangi bir row kalmış ise bu sorgularda tempObjecte assign edilir.
	if (index2 != rowIndex){
		while(index2 != rowIndex){
			tempObject.matrixObject.push_back(rowVector); //vector içine vector atılıyor	
			tempObject.index = 0;	
			int leftObjectIndex = 0 ;
			while(leftObjectIndex != keepingIndex[rowIndex]){
				eachCordinate = new Cell2 ;
				tempObject.matrixObject[tempObject.index2].push_back(*eachCordinate);
				tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex][leftObjectIndex].getColumn());
				tempObject.matrixObject[tempObject.index2][0].setRow(matrixObject[rowIndex][0].getRow());
				tempObject.matrixObject[tempObject.index2][tempObject.index].setData(matrixObject[rowIndex][leftObjectIndex].getData());
				tempObject.index++;
				leftObjectIndex++;	
			}
			tempObject.keepingIndex.push_back(tempObject.index);
			tempObject.index2++; // temp objenin row sayısını artırıldığını belirtiyor.
			rowIndex++;
		}
	}else if (m1.index2 != rowIndex1){
		while(m1.index2 != rowIndex1){
			tempObject.matrixObject.push_back(rowVector); //vector içine vector atılıyor	
			tempObject.index = 0;	
			int rightObjectIndex = 0 ;
			while(rightObjectIndex != m1.keepingIndex[rowIndex1]){
				eachCordinate = new Cell2 ;
				tempObject.matrixObject[tempObject.index2].push_back(*eachCordinate);
				tempObject.matrixObject[tempObject.index2][tempObject.index].setColumn(matrixObject[rowIndex1][rightObjectIndex].getColumn());
				tempObject.matrixObject[tempObject.index2][0].setRow(m1.matrixObject[rowIndex1][0].getRow());
				tempObject.matrixObject[tempObject.index2][tempObject.index].setData(-m1.matrixObject[rowIndex1][rightObjectIndex].getData());
				tempObject.index++;
				rightObjectIndex++;	
			}
			tempObject.keepingIndex.push_back(tempObject.index);
			tempObject.index2++; // temp objenin row sayısını artırıldığını belirtiyor.
			rowIndex1++;
		}
	}

	return tempObject;
}