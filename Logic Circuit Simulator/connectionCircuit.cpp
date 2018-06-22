


//23.04.2018 
//assignment4_Hamza_Yoğurtcuoğlu_171044086.cpp

//GATE BAĞLANTILARI BU FONKSİYONDA YAPILIR.

#include "connectionCircuit.h"

void connectionCircuit(Gates * gatesArray[],outputClass output [],inputClass input [], int gateNumber,int outputNumber,int inputNumber,string ignoreString,int index){

if (ignoreString == "NOGATE"){
	for (int i = 0; i < inputNumber; ++i){
		for (int j = 0; j <gateNumber ; ++j){
			if (gatesArray[j]->getInputFirst() == input[i].getInputValue()){
				gatesArray[j]->firstInput = &input[i];
		
				if (gatesArray[j]->getOutput() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[j]->getOutput(),j);
				}
				 if (gatesArray[j]->getOutput2() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[j]->getOutput2(),j);
				}
				if (gatesArray[j]->getOutput3() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[j]->getOutput3(),j);
				}
				if (gatesArray[j]->getOutput4() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[j]->getOutput4(),j);
				}
			}
			else if (gatesArray[j]->getInputSecond() == input[i].getInputValue()){
				gatesArray[j]->secondInput = &input[i];
				if (gatesArray[j]->getOutput() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[j]->getOutput(),j);
				}
				else if (gatesArray[j]->getOutput2() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[j]->getOutput2(),j);
					
				}
				else if (gatesArray[j]->getOutput3() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[j]->getOutput3(),j);
					
				}
				else if (gatesArray[j]->getOutput4() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[j]->getOutput4(),j);
				}
			else{
				for (int m = 0;  m< outputNumber; ++m)
				{
					if (output[m].getOutput() == input[i].getInputValue())
					{
						output[m].firstInput = &input[i];
					}
				}

			}			
			}
		}
	}	
}else{

	for (int k = 0; k < gateNumber; ++k)
	{
		if (gatesArray[k]->getInputFirst() == ignoreString)
		{
			gatesArray[k]->firstInput = gatesArray[index];
		
				if (gatesArray[k]->getOutput() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[k]->getOutput(),k);
				}
				 if (gatesArray[k]->getOutput2() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[k]->getOutput2(),k);
				}
				if (gatesArray[k]->getOutput3() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[k]->getOutput3(),k);
				}
				if (gatesArray[k]->getOutput4() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[k]->getOutput4(),k);
				}
			
		}else if (gatesArray[k]->getInputSecond() == ignoreString){
				gatesArray[k]->secondInput = gatesArray[index];
				if (gatesArray[k]->getOutput() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[k]->getOutput(),k);
				}
				else if (gatesArray[k]->getOutput2() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[k]->getOutput2(),k);
					
				}
				else if (gatesArray[k]->getOutput3() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[k]->getOutput3(),k);
					
				}
				else if (gatesArray[k]->getOutput4() !="\0")
				{
					connectionCircuit(gatesArray,output,input , gateNumber,outputNumber,inputNumber,gatesArray[k]->getOutput4(),k);
		        }
	    }else{
	    	
	    	for (int z= 0;  z< outputNumber; ++z)
				{
					if (output[z].getOutput() == ignoreString)
					{
						output[z].firstInput = gatesArray[index];
					}
				}
	    }
}
}
}