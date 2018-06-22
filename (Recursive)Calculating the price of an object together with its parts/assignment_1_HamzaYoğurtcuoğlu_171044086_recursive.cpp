
//Assignment_1_HamzaYoğurtcuoğlu_171044086.cpp
//06.03.2018 16:43

//Recursion System
//This program which to calculate the total cost of a object.
//In this case your compound object is your object.
//The object has many parts and some of the parts are also compound objects individually.
/*                           Shape of record
				
	example:			 Bicycle--> your main object
						---------------
							/		\	
						   /		 \
				-----------        -----------
				Wheel		        Frame --> compounds
				/						\		
			   /						 \
 -----------------------------		 ------------------------------	
 Rim		Spoke		Hub		 Rearframe		Frontframe --> Subcompounds
						/								\
					   /	 							 \
				--------------------	        ----------------------
				Gear		Axle					Fork	Handle
							/
						   /
				-------------------
				   Nut        Bolt
*/
/*############################################################################*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*----------------------------------------------------------------------------*/
/*------------------------------Includes--------------------------------------*/
/*----------------------------------------------------------------------------*/

#include<iostream>
#include<cstring>
#include<cstdlib>

using namespace std;

#define max_index 100

double loop (const char * coming_string);			//All recursion takes place in this function
void output_object_name(const char * temp_string);	//Displaying next item.//This loop display which item 
bool node_control(const char * temp_string);		//This function controls what this price or a parts of item
void delete_space_char_array(char * temp_string);	//delete space in array

int main(int argc, char const *argv[])
{	
	double cost;								// Cost of Main Object

	char* temp_string ;							//it takes temporary temp_string if it is cost or not then we will scan to struct price or inputname   
	
	temp_string = (char *) malloc(sizeof(char)*max_index); //take a place with malloc up to 100 character

	cout<<"Define the object :"<<endl;					//User decides name of object
	
	cin.getline(temp_string, max_index);			//first index our main name of object

	cost=loop (temp_string);		//This function is keeping cost,decision and all items	

	cout<<"Total cost of ";
														//Total  
	output_object_name(temp_string);				    //cost
														//of
	cout<<" is "<<cost<<endl;							//item.

	free(temp_string);						//get freed dynamically allocated memory

	return 0;
}
//Displaying next item.//This loop display which item 
void output_object_name(const char * temp_string)	
{		
		cout<<temp_string;
}

double loop (const char * coming_string)
{
	cout<<"What is ";								

	output_object_name(coming_string);			

	cout<<"?:"<<endl;

	int decision , number_of_item;		//Decision is 1 or 0 that means price or branch 

	double cost = 0.0 ;					//each leaf has zero cost at the begining

	char * temp_string ;							            

	temp_string = (char *) malloc(sizeof(char)*max_index);  

	cin.getline(temp_string, max_index);		

	decision = node_control (temp_string);		//Decision is 1 or 0 that means price or branch 

	if (decision == 1)			//If decision is 1 cost add the main cost and return cost
	{
		cost = atof(temp_string);
	}

	else if (decision == 0)	  // if user enter a parts of item  return 0 ;
	{				  								
		int	number_character = strlen(temp_string);	
		
		int index = 0;
		
		do
		{			
			int temp_index1 = 0,temp_index2=0;		//getting next part of name index (temp_index1) , getting next part of number (temp_index2)

			char * name_string ;

			name_string = (char *) malloc(sizeof(char)*max_index);	// dynamically allocated memory in order to get next part of name

			char * number_string ;							        

			number_string = (char *) malloc(sizeof(char)*max_index); // dynamically allocated memory in order to get next part of number

			while(temp_string[index]!='*')								//Parser
			{															//Loop
				number_string[temp_index1] = temp_string[index];		//For
																		//temp_string
				index++;												//for getting number_string

				temp_index1++;
			}

			index++;
			number_of_item = atoi (number_string);			//Translate from string to integer

			while(temp_string[index]!='+'&&index<number_character)	//Parser
			{														//Loop
				if (temp_string[index] !=' ')						//For
				{													//temp_string
																	//for getting name_string
					name_string[temp_index2] = temp_string[index];

					temp_index2++;
				}

				index++;
				
				name_string[(temp_index2)]='\0';		//Assign '\0' to last index of dynamic memory
			}	

			index++;
			delete_space_char_array(name_string);		//deleting space in taken place character string
			
   			cost = cost + number_of_item* loop (name_string);		
				
			free(name_string),free(number_string);    //get freed dynamically allocated memory
			

		}	
		while(index<number_character);				//if pointer_strtok points NULL , Loop is finished.
	}
	
	free(temp_string);						//get freed dynamically allocated memory

	return cost;
}

//This function controls what this price or a parts of item
//if user enter a price return 1 ; if user enter a parts of item  return 0 ; 
bool node_control(const char * temp_string)
{		
	for (int i = 0; i < strlen(temp_string); ++i)
	{
		if ((temp_string[i]>=65&&temp_string[i]<=90||temp_string[i]>=97&&temp_string[i]<=122)||(temp_string[i]=='+'||temp_string[i]=='*'))
		{
			return 0;					//If there is either a alphabe ,'+' or '*' return 0; 
		}								//It means there is a alphabe and that is a branch
	}

	return 1 ;							//If no is alphabe return 1; its price
}

//delete space in array
void delete_space_char_array(char * temp_string)
{
	int i = 0;
		
		for (int j = 0; j<strlen(temp_string); ++j)
		{
			if ((temp_string[j]>=65&&temp_string[j]<=90||temp_string[j]>=97&&temp_string[j]<=122))
			{
				temp_string[i] = temp_string[j];							//it scans all character and 
																			//copy just character instead of space
				i++;
			}		
		}

	temp_string[i] = '\0';									//closing array end of array;
} 
/*############################################################################*/
/*           End of Assignment_1_HamzaYoğurtcuoğlu_171044086.cpp              */
/*############################################################################*/
