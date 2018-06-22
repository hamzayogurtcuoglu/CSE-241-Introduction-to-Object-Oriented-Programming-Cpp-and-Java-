
//23.04.2018 
//assignment4_Hamza_Yoğurtcuoğlu_171044086.cpp
//GATES BASE CLASS 
//OR , AND , NOT , FLIPFLOP, DECODER CLASSLARINI ICEREN DOSYA

#include "gatesClass.h"

Gates::Gates(){

	firstInput = NULL;
	secondInput = NULL;
}

bool orGates::evaluate(int & former_out){

	return ((this->firstInput->evaluate(former_out))||(this->secondInput->evaluate(former_out)));
}

bool andGates::evaluate(int & former_out){

	bool i = this->firstInput->evaluate(former_out);	
	bool j = this->secondInput->evaluate(former_out);
	return (i&&j);

}

bool notGates::evaluate(int & former_out){

	return !(this->firstInput->evaluate(former_out));
}

//FlipFlop doğruluk tablosuna göre işlem yapann evaluate fonksiyonu
bool flipFlopGates::evaluate(int & former_out){

    bool result;
    bool i = this->firstInput->evaluate(former_out);

    if (former_out==0&&i==0)
    {	
    	result = 0;
    	tempIndexx++;
    	if (tempIndexx == 8 )
    	{
    		former_out = result ;
    	}
    	return result;
    }
    else if ((former_out==1&&i==0)||(former_out==0&&i==1))
    {
    	result = 1 ;
    	
    	tempIndexx++;
    	if (tempIndexx == 10 )
    	{
    		former_out = result ;
    	}							//former_out bir static değişken
    	return result;
    }else if (i==1&&former_out==1)
    {
    	result=0;
    	tempIndexx++;
    	if (tempIndexx == 100 )
    	{
    		former_out = result ;
    	}
    	return result;
    }
}

bool decoderGates::evaluate(int & former_out){

	bool j = this->firstInput->evaluate(former_out);

	bool i = this->secondInput->evaluate(former_out);

	if (decoderIndex>3)
		decoderIndex=0;

	if ((i==0&&j==0)&&(decoderIndex==0))
	{
		decoderIndex++;
		return 1;	
	}
	else if ((i==1&&j==0)&&(decoderIndex==2))
	{
		decoderIndex++;
		return 1;
	}
	else if ((i==0&&j==1)&&(decoderIndex==1))
	{
		decoderIndex++;
		return 1 ;
	}
	else if ((i==1&&j==1)&&(decoderIndex==3))
	{
		decoderIndex = 0;
		
		return 1 ;
	}else{	

		decoderIndex++;
			
		return 0 ;
	}

}

//BURDAKİ BÜTÜN SET FONKSİYONLARI DOSYADAN ALINAN KAPILARIN 
//INPUT VE OUTPUTLARINI OBJELERİN DEĞİŞKENLERİNE ASSIGN EDER.


void orGates::setName(string inputOutput,int index){

	if (index == 0)
		output = inputOutput;
	else if (index == 1)
		inputFirst = inputOutput ;
	else if (index == 2)
		inputSecond = inputOutput ;

}

void andGates::setName(string inputOutput,int index){

	if (index == 0)
		output = inputOutput;
	else if (index == 1)
		inputFirst = inputOutput ;
	else if (index == 2)
		inputSecond = inputOutput ;

}

void notGates::setName(string inputOutput,int index){

	if (index == 0)
		output = inputOutput;
	else if (index == 1)
		inputFirst = inputOutput ;
}

void flipFlopGates::setName(string inputOutput,int index){

	if (index == 0)
		output = inputOutput;
	else if (index == 1)
		inputFirst = inputOutput ;
}

void decoderGates::setName(string inputOutput,int index){

	if (index == 0)
		output = inputOutput;
	else if (index == 1)
		output2 = inputOutput ;
	else if (index == 2)
		output3 = inputOutput ;
	else if (index == 3)
		output4 = inputOutput ;
	else if (index == 4)
		inputFirst = inputOutput ;
	else if (index == 5)
		inputSecond = inputOutput ;
}
