
//23.04.2018 
//assignment4_Hamza_Yoğurtcuoğlu_171044086.cpp
//INPUT VE OUTPUT CLASSINI ICEREN DOSYA


#ifndef INPUT_OUTPUT_CLASS
#define INPUT_OUTPUT_CLASS

#include "gatesClass.h"
#include<iostream>
#include<string>

using namespace std;

//INPUT CLASSI GATES CLASSINI IHNERIT EDIYOR
class inputClass : public Gates //:public Gates
{
	public:
		inputClass(){};
		void setInputName(string inputNameT);
		bool evaluate(int & former_out);
		void setInputValue(bool inputValueT);
		string getInputValue(){return input;}
	protected:
		string input ; 
		bool inputValue ; 	
};

//OUTPUT CLASSI GATES CLASSINI IHNERIT EDIYOR
class outputClass : public Gates
{
	public:
		outputClass(){};
		void setOutputName(string outputNameT);
		bool evaluate(int & former_out);
		string getOutput();
		void setOutputValue(bool outputValueT){outputValue = outputValueT;}
	protected:
		string output; 
		bool outputValue ;
};

#endif