
//23.04.2018 
//assignment4_Hamza_Yoğurtcuoğlu_171044086.cpp
//GATES BASE CLASS 
//OR , AND , NOT , FLIPFLOP, DECODER CLASSLARINI ICEREN DOSYA

#ifndef GATESHEADER
#define GATESHEADER

#include<iostream>
#include<string>

using namespace std;

class Gates
{
	public:
		Gates();
		~Gates(){}
		virtual bool evaluate(int & former_out){} 
		virtual void setName(string inputOutput,int index){}
		virtual string getInputFirst(){}
		virtual	string getOutput(){}
		virtual string getOutput2(){ return output2;}
		virtual string getOutput3(){ return output3;}
		virtual string getOutput4(){ return output4;}	
		virtual string getInputSecond(){}
		virtual void setOutputValue(bool outputValueT){}
		Gates* firstInput ;
		Gates* secondInput ;
		string output2,output3,output4;
	protected:	
		int decoderIndex = 0;
};

//OR KAPISININ CLASSI GATES CLASSI INHERIT EDER
class orGates : public Gates
{
	public:
		orGates(){}
		~orGates(){}
		bool evaluate(int & former_out );	
		void setName(string inputOutput,int index);
		string getInputFirst(){return inputFirst;}
		string getInputSecond(){return inputSecond;}
		string getOutput(){return output;}
		string getOutput2(){}
		string getOutput3(){}
		string getOutput4(){}
	protected:
		string inputFirst; 	
		string inputSecond;
		string output;
};

//AND KAPISININ CLASSI GATES CLASSI INHERIT EDER
class andGates : public Gates
{
	public:
		andGates(){}
		~andGates(){}
		bool evaluate(int & former_out);
		void setName(string inputOutput,int index);
		string getInputFirst(){return inputFirst;}
		string getInputSecond(){return inputSecond;}
		string getOutput(){return output;}
		Gates * outputPointer;
	protected:
		string inputFirst; 	
		string inputSecond;
		string output;
};

//NOT KAPISININ CLASSI GATES CLASSI INHERIT EDER
class notGates : public Gates
{
	public:
		notGates(){}
		~notGates(){}
		bool evaluate(int & former_out);
		void setName(string inputOutput,int index);
		string getInputFirst(){return inputFirst;}
		string getInputSecond(){return inputSecond;}
		string getOutput(){return output;}
	protected:
		string inputFirst; 	
		string inputSecond;
		string output;
};

//FLIPFLOP CLASSI GATES CLASSI INHERIT EDER
class flipFlopGates : public Gates
{
	public:
		flipFlopGates(){}
		~flipFlopGates(){}
		bool evaluate(int & former_out);
		void setName(string inputOutput,int index);
		string getInputFirst(){return inputFirst;}
		string getInputSecond(){return inputSecond;}
		inline string getOutput() {return output;}
	protected:
		int tempIndexx = 0;
		string inputFirst; 	
		string inputSecond;
		string output;	
		
};

			
//DECODER KAPISININ CLASSI GATES CLASSI INHERIT EDER
class decoderGates : public Gates
{
	public:
		decoderGates(){}
		~decoderGates(){}
		bool evaluate(int & former_out);
		void setName(string inputOutput,int index);
		string getInputFirst(){return inputFirst;}
		string getInputSecond(){return inputSecond;}
		inline string getOutput(){return output;}
		inline string getOutput2(){ return output2;}
		inline string getOutput3(){ return output3;}
		inline string getOutput4(){ return output4;}
	protected:
		string output;
		string inputFirst; 	
		string inputSecond;	
};


#endif

