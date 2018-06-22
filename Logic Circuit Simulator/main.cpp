
//23.04.2018 
//assignment4_Hamza_Yoğurtcuoğlu_171044086.cpp
//İçerik::
/*
  DOSYADAN ALDIĞI DEVREYİ 
  TEKRAR DOSYADAN ALINAN BOOLEAN INPUTLARA GORE CIKTI VEREN PROGRAM		
  GATE BAĞALANTILARINI SAYESINDE HER OUTPUT ICIN , EVALUATE ILE BASLAYIP
  RECURSIVE BIR SEKILDE ILERLEYEN PROGRAM
*/
//Terminalde "make" komutuyla dosyaları derler
//Terminalde "make run" komutuyla dosyayı çalıştırır
//Terminalde "make clean" komutuyla .o uzantılı dosyaları temizler.

#include<fstream>
#include <sstream>
#include "gatesClass.h"			//gate classı ve diğer kapıların tutulduğu dosya (AND,OR,)
#include "inputOutputClass.h"	//input ve output class tutulan file
#include "connectionCircuit.h"//bu headerda gateslerin bağlantısı yapılır

using namespace std;



int main(int argc, char const *argv[])
{
		int former_out = 0;
		string allLine,tempLine ;
		ifstream takeFile ;
		takeFile.open("circuit.txt");
		int gateNumber = 0 , outputNumber = 0 , inputNumber = 0 ; 
		while(std::getline(takeFile,allLine)){				//bu döngüde input output ve gate sayısı öğreniliyor 
			istringstream allLineTemp (allLine);
			if(std::getline(allLineTemp,tempLine,' ')){
				if (tempLine == "INPUT"){
					while(std::getline(allLineTemp,tempLine,' ')){//input sayısı öğrenilir
						inputNumber++;
					}
				}	
				else if (tempLine == "OUTPUT"){
					while(std::getline(allLineTemp,tempLine,' ')){//output sayısın öğrenilir
						outputNumber++;
					}
				}	
			}
			gateNumber++;
		}
		gateNumber = gateNumber - 2 ; //INPUT ve OUTPUT dosyada olduğu için gate sayısından 2 çıkarılır
		takeFile.close();

		ifstream inputFile;

		inputFile.open("input.txt");	//input dosyasından ilk inputlar alınıyor.
		string allInputLine,tempInputLine;

	while(std::getline(inputFile,allInputLine)){
		takeFile.open("circuit.txt");	
		int gateIndex = 0 ; 		

		inputClass * input = new inputClass[inputNumber];//input sayısına göre dynamic allocation yapılıyor.
		outputClass * output = new outputClass[outputNumber];
		Gates ** gatesArray = new Gates * [gateNumber];
	

		while(std::getline(takeFile,allLine)){

			istringstream allLineTemp (allLine);
			//input sayısına göre 
			if(std::getline(allLineTemp,tempLine,' ')){	//ilk keyword belirlenir
				if (tempLine == "INPUT"){				//input , output veya gatelere göre isimleri objelerine atanır.	
					int index = 0;
					while(std::getline(allLineTemp,tempLine,' ')){	
							input[index].setInputName(tempLine);
							index++;
					}	
				}		
				else if (tempLine == "OUTPUT"){		//output harfleri burda fileden alınır.
					int index = 0;
					while(std::getline(allLineTemp,tempLine,' ')){	
							output[index].setOutputName(tempLine);
							index++;
					}	
				} 
				else if (tempLine == "OR"){
					int index = 0 ; //dosyadan okurken alınan output ve inputları belirlememiz için gerekli index
					Gates * orGate  = new orGates;
					gatesArray[gateIndex] = orGate; //objenin adresini tutuluyor
					while(std::getline(allLineTemp,tempLine,' ')){	
							gatesArray[gateIndex]->setName(tempLine,index);
							index++;
					}	
					gateIndex++;
				}
				else if (tempLine == "AND"){
					int index = 0 ; //dosyadan okurken alınan output ve inputları belirlememiz için gerekli index
					Gates * andGate = new andGates;
					gatesArray[gateIndex] = andGate; //objenin adresini tutuluyor
					while(std::getline(allLineTemp,tempLine,' ')){	
							gatesArray[gateIndex]->setName(tempLine,index);
							index++;
					}	
					gateIndex++;
				}
				else if (tempLine == "NOT"){
					int index = 0 ; //dosyadan okurken alınan output ve inputları belirlememiz için gerekli index
					Gates * notGate = new notGates;
					gatesArray[gateIndex] = notGate; //objenin adresini tutuluyor
					while(std::getline(allLineTemp,tempLine,' ')){	
							gatesArray[gateIndex]->setName(tempLine,index);
							index++;
					}	
					gateIndex++;
				}
				else if (tempLine == "FLIPFLOP"){
					int index = 0 ; //dosyadan okurken alınan output ve inputları belirlememiz için gerekli index
					Gates * flipFlopGate = new flipFlopGates;
					gatesArray[gateIndex] = flipFlopGate; //objenin adresini tutuluyor
					while(std::getline(allLineTemp,tempLine,' ')){	
							gatesArray[gateIndex]->setName(tempLine,index);
							index++;
					}	
					gateIndex++;
				}
				else if (tempLine == "DECODER"){
					int index = 0 ; //dosyadan okurken alınan output ve inputları belirlememiz için gerekli index
					Gates * decoderGate = new decoderGates ;
					gatesArray[gateIndex] = decoderGate; //objenin adresini tutuluyor
					while(std::getline(allLineTemp,tempLine,' ')){	
							gatesArray[gateIndex]->setName(tempLine,index);
							index++;
					}	
					gateIndex++;
				}
			}
		}
		takeFile.close();
	
		int ignore=-1;
		string ignoreString = "NOGATE";		//döngü içinde bir kapının herhangi bir girişi herhangi bir kapının outputu değilse "NOGATE" dir.
		connectionCircuit(gatesArray,output,input,gateNumber,outputNumber,inputNumber,ignoreString,ignore);
		//bu fonksiyon içerisinde recursive bir şekilde gatelerin outputların ve inputların bağlantıları yapılır.
			int tempInputIndex = 0 ;
			istringstream allInputLineTemp (allInputLine);
			while(std::getline(allInputLineTemp,tempInputLine,' ')){
				input[tempInputIndex].setInputValue(stoi(tempInputLine));
				tempInputIndex++;
			}
			//input.txt dosyasından alınan inputlara ve bağlantılara göre ekrana bastırılan output değerleri
			for (int i = 0; i < outputNumber; ++i)
			{
				bool a=output[i].evaluate(former_out);
				cout<<a<<" ";
			}
			cout<<endl;
    delete [] input ;
    delete [] output ;
    for (int a = 0; a < gateNumber; ++a){		//her bir destructor yapması gereken burda yapılır.
    	delete  gatesArray[a];
    }
    delete [] gatesArray;

    }
	return 0;
}
