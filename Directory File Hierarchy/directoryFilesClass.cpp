
//ASSIGNMENT_5

//HAMZA YOĞURTCUOĞLU
//171044086

/*
--1-)directoryClass
--2-)filesClass
--3-)linkedListClass
--4-)currentDirectoryClass
	Implementationsları içermektedir.
	
*/
#include "directoryFilesClass.h"


linkedListClass::linkedListClass(){

	rootPointer = NULL ; //ROOT ILK OLARAK NULLDIR.
	string tempLine,allLine;
	ifstream takeFile;
	takeFile.open("files.txt"); 
	
		while(std::getline(takeFile,allLine)){	//Öncelikle ilk satır alınır. (commands.txt) içinden 				 	
			int documentNumber = 0;				//bunda bir satırdaki döküman sayısı bulunacaktır.	
			istringstream allLineTemp (allLine);	
			string previousDirectory = "NOPREVIOUS";

			//sırasıyla files.txt satırının döküman sayısı öğrenilir.
			while(std::getline(allLineTemp,tempLine,'/')){ // '/ işaretine göre alınan satırdaki döküman sayısı öğrenilir.'
				documentNumber++;	
			}
			
			int index = 0;									
			istringstream allLineTemp2 (allLine); 
			while(std::getline(allLineTemp2,tempLine,'/')){	//alınan line parse edilir.
				
				//ilk directory root kabul edilir.	
				if (rootPointer == NULL)	//alınan ilk döküman geçici olarak root kabul edilir.
				{
					directoryClass * directory = new directoryClass;
					directory->setName(tempLine);
					rootPointer = directory ;
					
				}
				else if(documentNumber == (index + 1)){	//alınan line sonuncusu her zaman file olacağı için  rootdan başlayarak 
														//file bağlama fonksiyonu çağırılır.

					rootPointer = rootPointer->linkedFile(tempLine,previousDirectory,rootPointer);	//file bağlama fonksiyonu	

				}
				else{
					
					rootPointer	= rootPointer->linkedDirectory(tempLine , previousDirectory,rootPointer);	//linkedlist bağlantısı yapılır (documentry için)			
				}	
				index++;
			
				previousDirectory = tempLine ;	//bir önceki directory tutulur.
			}	
		}
		takeFile.close();
}


//bu fonksiyonda linked list operasyonları gerçekleştirilir.(directory için)
baseClass * directoryClass::linkedDirectory(string tempLine,string previousDirectory,baseClass * rootPointer){

	baseClass * temp ;	//directory swap işlemi için temp bir obje oluşturulur. 
	temp = new baseClass ;
	if (inNext == NULL)
	{								//eğer root tarafından çağırılan fonksiyon inNexti null değilse diğer directory bağlanır.						
		if(tempLine != getName()){
			
			directoryClass * directory = new directoryClass ;
			directory->setName(tempLine);	
			inNext = directory ;		//bir sonraki işaretlenir
			directory->outNext = this ;	//bir önceki bir sonrakine işaretler (-> <- gibi )
		}
	}else if (inNext != NULL)
	{
		if(tempLine != getName()){
			inNext->linkedDirectory (tempLine, previousDirectory , rootPointer);//
		}
	}

	//eğer dosyanın öncesi varsa in directory out directory kontorli yapılır.
	if (inNext != NULL)
	{	
		if(previousDirectory != "NOPREVIOUS"){

			temp = inNext->exitsOrNot(previousDirectory) ;

			if (temp !=NULL)
			{	
				rootPointer = temp;
				
				temp->inNext = this ;	
				
				this->outNext = rootPointer->inNext ;  //inNext -- outNext değişimi yapılır .
			}	
		}	
	}
	
	return rootPointer ;
}

//aranan directory bulunur ve return edilir.
baseClass * directoryClass::exitsOrNot(string previousDirectory){

	if (previousDirectory == directoryName)
	{	
		this->outNext->inNext = NULL; //en sondan gerekli yere alındığı için onu gösterene NULL atanır.
		this->outNext = NULL ;
		return  this  ;
	}
	else if(inNext != NULL){

		return inNext->exitsOrNot(previousDirectory) ;
	}
}

//FILE BAĞLAYAN FONKSİYON

baseClass * directoryClass::linkedFile(string tempLine,string previousDirectory,baseClass * rootPointer){

	if (previousDirectory != getName()){
		
		rootPointer	= this->inNext->linkedFile(tempLine,previousDirectory,rootPointer);	//directory of file bulunmaya çalışılır.
	}
	else{ //	directory of file bulunursa 

		if (inNext != NULL)	//içi boş değilse 
		{
			if(inNext->next == NULL){	
				
				filesClass * file ;
				file = new filesClass ;
				file->setName(tempLine);
				inNext->next = file ;
				file->preNext = inNext ;
			}else if (inNext->next != NULL)
			{	
			 	rootPointer = inNext->next->linkedNext(tempLine,previousDirectory,rootPointer);
			}
		}else if (inFile == NULL)
		{	
			filesClass * file ;
			file = new filesClass ;
			file->setName(tempLine);
			inFile = file ;
		}
		else if (inFile != NULL)
		{

			if (inFile->next == NULL )
			{				
				filesClass * file ;
				file = new filesClass ;
				file->setName(tempLine);	
				inFile->next = file ;
				file->preNext = inFile ;	
			}		
			else if (inFile->next != NULL)
			{	 
				 inFile->next->exitsOrNot(tempLine);  	
			}
		}
	}

	return rootPointer ;
}

//dosyaların next bağlantılarını yapar.
baseClass * filesClass::linkedNext(string tempLine,string previousDirectory,baseClass * rootPointer){

	if(next == NULL){	//eğer dökümanların yanı boş ise yeni file açar ve nextini point eder
		filesClass * file ;
		file = new filesClass ;
		file->setName(tempLine);
		next = file ;
		file->preNext = this ;

	}else if (next != NULL ) //eğer NULL değilse tekrar NULL bulana kadar aramaya devam eder.
	{
		return next->linkedNext(tempLine,previousDirectory,rootPointer);
	}
	return rootPointer ;
}

//eğer bir documentrynin altında documentry yerine file olursa ve başkada bir file varsa birbirine bağlar.
baseClass * filesClass::exitsOrNot(string tempLine){

	if (this->next == NULL )
	{
		filesClass * file ;
		file = new filesClass ;
		file->setName(tempLine);
		this->next = file ;
		file->preNext = this ;
	}else if (this->next != NULL)
	{
		this->next->exitsOrNot(tempLine);
	}
}

//sadece rootdaki documentary'ler için yazılım yazan foksiyon daha
//sonraki duruma göre recursive bir şekilde bir ekrana yazdırma fonksiyonu çağırılır.
void linkedListClass::outputTxt(string documentaryLine,ofstream & writeFile){

	writeFile<<rootPointer->getName()<<endl;
	if (rootPointer->inNext != NULL)
	{	
		documentaryLine = rootPointer->getName() ;
		rootPointer->inNext->outputRecursiveControl(documentaryLine,writeFile) ;
	
	}else if (rootPointer->inFile != NULL)
	{
		documentaryLine = rootPointer->getName() ;
		rootPointer->inFile->outputRecursiveControl(documentaryLine,writeFile) ;	
	}

}

//commands.txt den alınan komutlara göre 
currentDirectoryClass::currentDirectoryClass(linkedListClass * linkedListObject){

	string tempLine,allLine;
	ifstream takeFile;
	takeFile.open("commands.txt"); 

	currentDirectory = linkedListObject->rootPointer; //ilk olarak current adres root olur .

	while(std::getline(takeFile,allLine)){

		istringstream allLineTemp (allLine);
		
		if(std::getline(allLineTemp,tempLine,' ')){
						
			if (tempLine == "cd")
			{
				int index = 0;
				while(std::getline(allLineTemp,tempLine,'/')){	
					index++;	
				}
				
				istringstream allLineTemp2 (allLine);
				if (std::getline(allLineTemp2,tempLine,' '));
				
				int tempIndex = 0;
				while(std::getline(allLineTemp2,tempLine,'/')){
					tempIndex++;
					if (tempIndex == index)
					{
							if (tempLine == "")	//eğer '/' işareti kullanılmışsa roota döner currentDirectory
							{
								currentDirectory = linkedListObject->rootPointer ;
							}
							else if(tempLine == ".."){	//  '..' kullanılmışsa bir önceki directory döner .

								currentDirectory = currentDirectory->outNext ;
							}
							else if(linkedListObject->rootPointer->getName()==tempLine)
							{
								currentDirectory = linkedListObject->rootPointer ;

							}else{	//currentDirectory seçilen directory bulunur ve currentDirectorye point etmesi için atanır.

								currentDirectory = linkedListObject->rootPointer->controlCurrent(tempLine);	
							}
					}	
				}

			}else if (tempLine == "copy")//copy komutu olduğu anlaşılır.
			{
				int j= 0;
				string preTempLine ;
				string copyDocument ;
				int index = 0;
				while(std::getline(allLineTemp,tempLine,'/')){	
					
					
					index++;	
					int characterNumber = tempLine.length();
					if(tempLine[characterNumber-1] == ' ' ){						 //eğer " " bulunursa yani /0 bundan sonraki directorye bundan önceki 
						
						for (int i = 0; i <tempLine.length()-1; ++i)
						{
							copyDocument = copyDocument + tempLine[i];				// kısım kopyalanır.
						}
						j++;
					}else{
						if (j == 0)
							{
								preTempLine = tempLine ;		//dosyanın hangi directoryde olduğu ve içindeki dosya mı veya file mi
							}									//ona göre copy işlemi yapılır . 
					}	
				}
				
				currentDirectory->copyDirectoryFiles(copyDocument,preTempLine,tempLine,currentDirectory); //neyin nereye kopyalanacağı öğrenilir.
																						//kopyalama foksiyonuna gönderilir.
			}
			else if (tempLine == "delete" )//delete komutu olduğu anlaşılır.
			{	
				int controlFileDirectory ;
				int j= 0;
				string preTempLine ;
				int index = 0;
				while(std::getline(allLineTemp,tempLine,'/')){	
					index++;					
				}
				int tempIndex = 0;
				istringstream allLineTemp2(allLine);
				std::getline(allLineTemp2,tempLine,' ');
				while(std::getline(allLineTemp2,tempLine,'/')){

					if (tempIndex == index-2)
					{
						preTempLine = tempLine ;	
					}
					tempIndex++;

				}	
				
				controlFileDirectory = currentDirectory->deleteControl(tempLine);//hangi tür silineceği belirlenir.
				
				if (controlFileDirectory == 0)
				{														
					currentDirectory->deleteFile(preTempLine,tempLine);	//file silineceği anlaşılır.														
				
				}else{

					currentDirectory->deleteDirectory(tempLine);	//directory silineceği anlaşılır.
				}				

			}else if (tempLine == "move")//move komutu olduğu anlaşılır.
			{
				int j= 0;
				string preTempLine ;
				string copyDocument ;
				int index = 0;
				while(std::getline(allLineTemp,tempLine,'/')){	
					
					
					index++;	
					int characterNumber = tempLine.length();
					if(tempLine[characterNumber-1] == ' ' ){						 //eğer " " bulunursa yani /0 bundan sonraki directorye bundan önceki 
						
						for (int i = 0; i <tempLine.length()-1; ++i)
						{
							copyDocument = copyDocument + tempLine[i];				// kısım kopyalanır.
						}
						j++;
					}else{
						if (j == 0)
							{
								preTempLine = tempLine ;
							}			
					}	
				}
			
				currentDirectory->moveDirectoryFiles(copyDocument,preTempLine,tempLine,currentDirectory); //move edilecek kısım 
			}																						//currenttan itibaren takibi yapılır		
		}																							// ve istenilen yere move edilir.
	}	
}

//current controlü yapılır.
baseClass * directoryClass::controlCurrent(string tempLine){

	if (tempLine == this->getName())
	{
		return this ;
		
	}else if (this->inNext != NULL)
	{
		return (this->inNext->controlCurrent(tempLine));
	}
}


