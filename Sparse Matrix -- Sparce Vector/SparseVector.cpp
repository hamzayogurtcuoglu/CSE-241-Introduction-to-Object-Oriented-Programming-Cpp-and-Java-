//Assignment_3_HamzaYoğurtcuoğlu_171044086.cpp
//Bu dosya vector fonksiyonları içerir.
//Yapılabilen işlemler:
// Assignment
// + , - (binary) , -(unary), << ,read file

//Makefile komutları
//make --> compiler eder.
//make clean --> .o uzantılı dosyalarını siler
//make run --> dosyayı çalıştırır.



#include "SparseVector.h"

using namespace std ;

SparseVector::SparseVector(string textName )
{
	char * strtokPointer ;

	ifstream takeFile ;

	takeFile.open(textName);

	while(!takeFile.eof())
	{	
		char  * allVector ; // her dosyadan çekilen vektör konumu için string oluşturulup silinir.

		allVector = new char (15); // boşluğa kadar olan vektörü karakter cinsinden alıyor.

		eachCordinate = new Cell;	// vektörün her bir elemanını  dynamic bir eleman atanıyor

		vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.

		takeFile>>allVector;			//dosyadan alınan kordinat ve datası				

		if (takeFile.eof()){		//dosya artık sonuna geldiyse döngüden çıkar ve file kapanır.   
			takeFile.close();
			break ;
		}
		strtokPointer=strtok(allVector,":");

		vectorObject[index].setColumn(atoi(strtokPointer));

		strtokPointer=strtok(NULL," ");

		vectorObject[index].setData(atof (strtokPointer)) ;

		index++;

		delete allVector;
	}	
}

ostream & operator <<(ostream & outfile,SparseVector & a1)
{
	for (int i = 0; i < a1.index; ++i)
	{		
			outfile << a1.vectorObject[i].getColumn() ;
			outfile << a1.vectorObject[i].getColon() ;
			outfile << a1.vectorObject[i].getData() ;
			outfile <<" ";
	}
	return outfile ;
}

SparseVector  SparseVector::operator +(SparseVector & a1)
{
	SparseVector tempObject ;
	int leftObjectIndex = 0 , rightObjectIndex = 0 ;

	while(( (leftObjectIndex != index) && (rightObjectIndex != a1.index))) {

		if (vectorObject[leftObjectIndex].getColumn() == a1.vectorObject[rightObjectIndex].getColumn()){
			eachCordinate = new Cell ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
			tempObject.vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.
			tempObject.vectorObject[tempObject.index].setData(vectorObject[leftObjectIndex].getData() + a1.vectorObject[rightObjectIndex].getData());
			tempObject.vectorObject[tempObject.index].setColumn(vectorObject[leftObjectIndex].getColumn());
			tempObject.index++;
			leftObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
			rightObjectIndex++;
		}
		else if (vectorObject[leftObjectIndex].getColumn() < a1.vectorObject[rightObjectIndex].getColumn()){
			eachCordinate = new Cell ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
			tempObject.vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.
			tempObject.vectorObject[tempObject.index].setData(vectorObject[leftObjectIndex].getData()) ;
			tempObject.vectorObject[tempObject.index].setColumn(vectorObject[leftObjectIndex].getColumn()) ;
			tempObject.index++;
			leftObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
		}
		else if (vectorObject[leftObjectIndex].getColumn() > a1.vectorObject[rightObjectIndex].getColumn()){
			eachCordinate = new Cell ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
			tempObject.vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.
			tempObject.vectorObject[tempObject.index].setData(a1.vectorObject[rightObjectIndex].getData()) ;
			tempObject.vectorObject[tempObject.index].setColumn(a1.vectorObject[rightObjectIndex].getColumn());
			tempObject.index++;
			rightObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır.
		}	
	}
	// bu kısım hangi vektörün fazlalığı varsa onu yeni vektöre atar

	if (leftObjectIndex != index){
		while(leftObjectIndex != index){
			eachCordinate = new Cell ;							// vektörün her bir elemanını  dynamic bir eleman atanıyor
			tempObject.vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.
			tempObject.vectorObject[tempObject.index].setData(vectorObject[leftObjectIndex].getData()) ;
			tempObject.vectorObject[tempObject.index].setColumn(vectorObject[leftObjectIndex].getColumn()) ;	
			tempObject.index++;
			leftObjectIndex++;		
		}
	}	
	if (rightObjectIndex != a1.index)
	{	while(rightObjectIndex != a1.index){
			eachCordinate = new Cell ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
			tempObject.vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.
			tempObject.vectorObject[tempObject.index].setData(a1.vectorObject[rightObjectIndex].getData())  ;
			tempObject.vectorObject[tempObject.index].setColumn(a1.vectorObject[rightObjectIndex].getColumn())  ;
			tempObject.index++;
			rightObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
		}
	}     

	return tempObject;
}

SparseVector & SparseVector::operator =(const SparseVector & a1)
{	
	int leftObjectIndex = 0 , rightObjectIndex = 0 ;
	int temp =index;
	this->index = a1.index ;
	

	while(rightObjectIndex != a1.index){
			if (temp<=leftObjectIndex){
				eachCordinate = new Cell ;			// yer allocation edilir.
				this->vectorObject.push_back(*eachCordinate);	
			}
			this->vectorObject[leftObjectIndex].setData(a1.vectorObject[rightObjectIndex].getData());
			this->vectorObject[leftObjectIndex].setColumn(a1.vectorObject[rightObjectIndex].getColumn()) ;
			leftObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
			rightObjectIndex++;
	}	
	return *this ;
}

SparseVector  SparseVector::operator -(SparseVector & a1)
{	
	double tempData ; //0 çıkan data tutulmaz allocation arrayda. (sparse vector)
	SparseVector tempObject ;
	int leftObjectIndex = 0 , rightObjectIndex = 0 ;

	while(( leftObjectIndex != index && rightObjectIndex != a1.index)&&(tempObject.index<=index||tempObject.index<=a1.index)){

		if (vectorObject[leftObjectIndex].getColumn() == a1.vectorObject[rightObjectIndex].getColumn()){
			
			tempData=vectorObject[leftObjectIndex].getData() - a1.vectorObject[rightObjectIndex].getData() ;
			if (tempData != 0){
				eachCordinate = new Cell ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
				tempObject.vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.
				tempObject.vectorObject[tempObject.index].setData(tempData) ; 
				tempObject.vectorObject[tempObject.index].setColumn(vectorObject[leftObjectIndex].getColumn()) ;
				tempObject.index++;
				leftObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
				rightObjectIndex++;
			}else{
				leftObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
				rightObjectIndex++;
			}
		
		}
		else if (vectorObject[leftObjectIndex].getColumn() < a1.vectorObject[rightObjectIndex].getColumn()){
			eachCordinate = new Cell ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
			tempObject.vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.
			tempObject.vectorObject[tempObject.index].setData(vectorObject[leftObjectIndex].getData()) ;
			tempObject.vectorObject[tempObject.index].setColumn(vectorObject[leftObjectIndex].getColumn())  ;
			tempObject.index++;
			leftObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
		}
		else if (vectorObject[leftObjectIndex].getColumn() > a1.vectorObject[rightObjectIndex].getColumn()){
			eachCordinate = new Cell ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
			tempObject.vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.
			tempObject.vectorObject[tempObject.index].setData( -a1.vectorObject[rightObjectIndex].getData()) ;
			tempObject.vectorObject[tempObject.index].setColumn( a1.vectorObject[rightObjectIndex].getColumn())  ;
			tempObject.index++;
			rightObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
		}	
	}

	// bu kısım hangi vektörün fazlalığı varsa onu yeni vektöre atar
	if (leftObjectIndex != index){
		while(leftObjectIndex != index){
			eachCordinate = new Cell ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
			tempObject.vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.
			tempObject.vectorObject[tempObject.index].setData(vectorObject[leftObjectIndex].getData())  ;
			tempObject.vectorObject[tempObject.index].setColumn(vectorObject[leftObjectIndex].getColumn()) ;
			tempObject.index++;
			leftObjectIndex++;		
		}
	}	
	else if (rightObjectIndex != a1.index)
	{	while(rightObjectIndex != a1.index){

			eachCordinate = new Cell ;	// vektörün her bir elemanını  dynamic bir eleman atanıyor
			tempObject.vectorObject.push_back (*eachCordinate) ;	//push_back ediliyor.
			tempObject.vectorObject[tempObject.index].setData( -a1.vectorObject[rightObjectIndex].getData()) ;
			tempObject.vectorObject[tempObject.index].setData( a1.vectorObject[rightObjectIndex].getColumn())  ;
			tempObject.index++;
			rightObjectIndex++;				// eğer eşit column varsa datalar toplanır ve geçici objeye atanır...
		}
	}
	return tempObject;
}

SparseVector & SparseVector::operator -()
{
	for (int i = 0; i < index; ++i)
		vectorObject[i].setData(- vectorObject[i].getData())  ;
	return *this;

}
//gelen vektörlerin uzunluklarına göre iki döngüye oluşturuldu.
double dot(const SparseVector & a1,const SparseVector & a2)
{
	double dotProduct = 0.0 ;
	int tempIndex = 0 ;

	if ((a1.index<=a2.index)){	
		while((a1.index<=a2.index)&&(tempIndex != a1.index )){	

			for (int i = 0; i < a2.index; ++i){
				if (a1.vectorObject[tempIndex].getColumn() == a2.vectorObject[i].getColumn()){
			
					dotProduct +=  a1.vectorObject[tempIndex].getData() * a2.vectorObject[i].getData() ;
					tempIndex++;
					break;
				}
				if (i==(a2.index-1))
					tempIndex++;
			}
		}
	}	
	else if ((a1.index>=a2.index)){	
		while((a1.index>=a2.index)&&(tempIndex != a2.index)){	

			for (int i = 0; i < a1.index; ++i){
				if (a2.vectorObject[tempIndex].getColumn() == a1.vectorObject[i].getColumn()){
			
					dotProduct +=  a2.vectorObject[tempIndex].getData() * a1.vectorObject[i].getData() ;
					tempIndex++;	
					break;
				}	
				if(i==(a1.index-1))
					tempIndex++;
			}
		}	
	}
	return dotProduct ;
}

