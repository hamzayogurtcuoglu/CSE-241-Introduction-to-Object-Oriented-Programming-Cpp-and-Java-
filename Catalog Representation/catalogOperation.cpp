

//ASSIGNMENT_6

//HAMZA YOĞURTCUOĞLU
//171044086

/*

	Veri Alınan Dosyalar	
		data.txt
		commands.txt
	Verilerin Yazdırıldığı Dosya
		output.txt

*/

#include "catalogOperation.h"

//Bu constructor data.txt alınan veriler vektördeki yere yerleştirilir. 
catalogOperation::catalogOperation(){

	ifstream takeFile;
	takeFile.open("data.txt");
	string tempLine;
	string allLine;
	if(std::getline(takeFile,allLine));

	operationString = allLine;

	if (allLine == "movie")
	{
		while(std::getline(takeFile,allLine)){
		
			movieObject = new catalogMovie ;
			movieS.push_back(*movieObject);
			int stringControl = 0; //yeni bir string tanımlama için yapılır.
									// 0 ise yeni bir string e yazılır ve 0 1 yapılır ve '"' işareti
								  //tekrar gelene kadar açık tutulur.	
			for (int i = 0; i < allLine.length(); ++i)
			{
				if (allLine[i] == '"' || stringControl%2 == 1)
				{	
					if (allLine[i] == '"'){  // movie ise gerekli bölümler stringlerine atanır.
						stringControl++;
					}
					if (movieS[index].getIndexString() == 0){
						movieS[index].setTitle(allLine[i]);
					}
					else if (movieS[index].getIndexString()==1){
						movieS[index].setDirector(allLine[i]);
					}
					else if (movieS[index].getIndexString()==2){
						movieS[index].setYear(allLine[i]);
					}
					else if (movieS[index].getIndexString()==3){
						movieS[index].setGenre(allLine[i]);
					}
					else if (movieS[index].getIndexString()==4){
						movieS[index].setStarring(allLine[i]);
					}
					if (stringControl%2 == 0){
						movieS[index].setIndexString();				
					}
				}	
			}
			index++;		//catalogdaki film sayısı burda hesaplanır.
		}
	}else if (allLine == "music")
	{
		while(std::getline(takeFile,allLine)){
			
			musicObject = new catalogMusic ;
			musicS.push_back(*musicObject);
			int stringControl = 0; //yeni bir string tanımlama için yapılır.
									// 0 ise yeni bir string e yazılır ve 0 1 yapılır ve '"' işareti
								  //tekrar gelene kadar açık tutulur.	
			for (int i = 0; i < allLine.length(); ++i)
			{
				if (allLine[i] == '"' || stringControl%2 == 1)
				{	
					if (allLine[i] == '"'){	//music ise gerekli bölümler stringlerine atanır.
						stringControl++;
					}
					if (musicS[index].getIndexString() == 0){
						musicS[index].setTitle(allLine[i]);
					}
					else if (musicS[index].getIndexString()==1){
						musicS[index].setArtists(allLine[i]);
					}
					else if (musicS[index].getIndexString()==2){
						musicS[index].setYear(allLine[i]);
					}
					else if (musicS[index].getIndexString()==3){
						musicS[index].setGenre(allLine[i]);
					}
					if (stringControl%2 == 0){
						musicS[index].setIndexString();				
					}
				}	
			}
			index++;	//catalogdaki müzik sayısı burda hesaplanır.
		}

	}else if (allLine == "book")
	{
		while(std::getline(takeFile,allLine)){

			bookObject = new catalogBook ;
			bookS.push_back(*bookObject);
			int stringControl = 0; //yeni bir string tanımlama için yapılır.
									// 0 ise yeni bir string e yazılır ve 0 1 yapılır ve '"' işareti
								  //tekrar gelene kadar açık tutulur.	
			for (int i = 0; i < allLine.length(); ++i)
			{
				if (allLine[i] == '"' || stringControl%2 == 1)
				{	
					if (allLine[i] == '"'){	// book ise gerekli bölümler stringlerine atanır.
						stringControl++;
					}
					if (bookS[index].getIndexString() == 0){
						bookS[index].setTitle(allLine[i]);
					}
					else if (bookS[index].getIndexString()==1){
						bookS[index].setAuthors(allLine[i]);
					}
					else if (bookS[index].getIndexString()==2){
						bookS[index].setYear(allLine[i]);
					}
					else if (bookS[index].getIndexString()==3){
						bookS[index].setTags(allLine[i]);
					}
					if (stringControl%2 == 0){
						bookS[index].setIndexString();				
					}
				}	
			}
			index++; 	//catalogdaki kitap sayısı burda hesaplanır.
		}
	}
}

//Unique entries catalogdaki kitap , film veya müzikleri bulur .
// Duplicate veya Missing Field olduğunu anlaşılır.
void catalogOperation::uniqueEntries(ofstream & writeFile){


	if (operationString == "movie")
	{
		writeFile<<"Catalog Read: "<<operationString<<endl;
		for (int i = 0; i < index; ++i)
		{ 	for (int j = i+1; j < index; ++j)
			{
				try{

					if(((movieS[i].getExceptionControl()==0)&&((movieS[i].getTitle() == movieS[j].getTitle())&&(movieS[j].getExceptionControl()==0)))
						&&(movieS[j].getIndexString()==5)){
						throw j; //missing duplicate controlu yapılır ve orada hata varsa throw edilir. 
					}

				}
				catch(int exceptionFound){

					setUniqueMember();	//Unique Entries sayısı artırılıyor.
					movieS[exceptionFound].setExceptionControl();
					writeFile<<"Exception: duplicate entry"<<endl;
					writeFile<<movieS[exceptionFound].getTitle()<<" "<<movieS[exceptionFound].getDirector()<<" "<<movieS[exceptionFound].getYear()
					<<" "<<movieS[exceptionFound].getGenre()<<" "<<movieS[exceptionFound].getStarring()<<endl;
				}	// hatalı olan exception objesi output.txt yazdırılır.
			}
		}
		for (int i = 0; i < index; ++i)
		{
			try{
				
				if((movieS[i].getIndexString()!=5)&& (movieS[i].getExceptionControl() == 0))
					throw i;
			}
			catch(int exceptionFound){
				setUniqueMember();	//Unique Entries sayısı artırılıyor.
				movieS[exceptionFound].setExceptionControl();
				writeFile<<"Exception: missing field"<<endl;
				writeFile<<movieS[exceptionFound].getTitle()<<" "<<movieS[exceptionFound].getDirector()<<" "<<movieS[exceptionFound].getYear()
				<<" "<<movieS[exceptionFound].getGenre()<<" "<<movieS[exceptionFound].getStarring()<<endl;
			}	// hatalı olan exception objesi output.txt yazdırılır.
		}
		writeFile<<getUniqueMember()<<" unique entries"<<endl;

	}else if (operationString == "music")
	{
		writeFile<<"Catalog Read: "<<operationString<<endl;
		for (int i = 0; i < index; ++i)
		{ 	for (int j = i+1; j < index; ++j)
			{
				try{

					if(((musicS[i].getExceptionControl()==0)&&((musicS[i].getTitle() == musicS[j].getTitle())&&(musicS[j].getExceptionControl()==0)))&&
						(musicS[j].getIndexString()==4)){ 
						throw j;			//missing duplicate controlu yapılır ve orada hata varsa throw edilir.
					}

				}
				catch(int exceptionFound){
					
					setUniqueMember();	//Unique Entries sayısı artırılıyor.
					musicS[exceptionFound].setExceptionControl();
					writeFile<<"Exception: duplicate entry"<<endl;
					writeFile<<musicS[exceptionFound].getTitle()<<" "<<musicS[exceptionFound].getArtists()<<" "<<musicS[exceptionFound].getYear()
					<<" "<<musicS[exceptionFound].getGenre()<<endl; // hatalı olan exception objesi output.txt yazdırılır.
				}
			}
		}
		for (int i = 0; i < index; ++i)
		{
			try{
				
				if((musicS[i].getIndexString()!=4)&& (musicS[i].getExceptionControl() == 0))
					throw i;
			}
			catch(int exceptionFound){
				setUniqueMember();	//Unique Entries sayısı artırılıyor.
					musicS[exceptionFound].setExceptionControl();
					writeFile<<"Exception: missing field"<<endl;
					writeFile<<musicS[exceptionFound].getTitle()<<" "<<musicS[exceptionFound].getArtists()<<" "<<musicS[exceptionFound].getYear()
					<<" "<<musicS[exceptionFound].getGenre()<<endl; // hatalı olan exception objesi output.txt yazdırılır.
			}
		}
		writeFile<<getUniqueMember()<<" unique entries"<<endl;

	}else if (operationString == "book")
	{
		writeFile<<"Catalog Read: "<<operationString<<endl;
		for (int i = 0; i < index; ++i)
		{ 	for (int j = i+1; j < index; ++j)
			{
				try{
					
					if(((bookS[i].getExceptionControl()==0)&&((bookS[i].getTitle() == bookS[j].getTitle())&&(bookS[j].getExceptionControl()==0)))
						&&(bookS[j].getIndexString()==4)){	//missing duplicate controlu yapılır ve orada hata varsa throw edilir.
						throw j;
					}
				
				}
				catch(int exceptionFound){

					setUniqueMember();	//Unique Entries sayısı artırılıyor.
					bookS[exceptionFound].setExceptionControl();
					writeFile<<"Exception: duplicate entry"<<endl;
					writeFile<<bookS[exceptionFound].getTitle()<<" "<<bookS[exceptionFound].getAuthors()<<" "<<bookS[exceptionFound].getYear()
					<<" "<<bookS[exceptionFound].getTags()<<endl;
				}	// hatalı olan exception objesi output.txt yazdırılır.
			}
		}		
		for (int i = 0; i < index; ++i)
		{
			try{
				
				if((bookS[i].getIndexString()!=4)&& (bookS[i].getExceptionControl() == 0))
					throw i;
			}
			catch(int exceptionFound){
					
					setUniqueMember();	//Unique Entries sayısı artırılıyor.
					bookS[exceptionFound].setExceptionControl();
					writeFile<<"Exception: missing field"<<endl;
					writeFile<<bookS[exceptionFound].getTitle()<<" "<<bookS[exceptionFound].getAuthors()<<" "<<bookS[exceptionFound].getYear()
					<<" "<<bookS[exceptionFound].getTags()<<endl;
			}	// hatalı olan exception objesi output.txt yazdırılır.
		}
		
		writeFile<<getUniqueMember()<<" unique entries"<<endl;
	}
}

catalogOperation::~catalogOperation(){

	if (movieObject != NULL)
		delete movieObject;
	else if (musicObject != NULL)
		delete musicObject;
	else if (bookObject != NULL)
		delete bookObject;

}