	
//23.04.2018 
//assignment4_Hamza_Yoğurtcuoğlu_171044086.cpp
//INPUT VE OUTPUT CLASSINI ICEREN DOSYA

#include "inputOutputClass.h"


void inputClass::setInputName(string inputNameT){

	input=inputNameT ; 
}

void outputClass::setOutputName(string outputNameT){

	output=outputNameT ; 
}

void inputClass::setInputValue(bool inputValueT){

	inputValue = inputValueT ;
}

string outputClass::getOutput(){

	return output;

}

//RECURSIVE BASLANGICI
bool outputClass::evaluate(int & former_out){
	return this->firstInput->evaluate(former_out);
}
//RECURSIVE BITISI
bool inputClass::evaluate(int & former_out){

	return inputValue;

}