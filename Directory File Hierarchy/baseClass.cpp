
//ASSIGNMENT_5

//HAMZA YOĞURTCUOĞLU
//171044086

/*
	BASECLASS HEADERLARI İÇERİR.
	COPY , MOVE , DELETE KOMUTLARININ
	FONKSİYONLARININ IMPLEMENTATIONLARI İÇERİR.
	DESTRUCTOR VE CONSRUCTURE ICERIR.

*/

#include "baseClass.h"

baseClass::baseClass()
{
	next = NULL;
	inNext = NULL;
	outNext = NULL ;
	inFile = NULL ;
}

//Bir anlatındaki dosyayı ve onun altında directort mi var file mı var control edilir .
//Ona görede içinde next doküman var mı onun kontrolüde yapılır.
void baseClass::outputRecursiveControl(string documentaryLine,ofstream & writeFile){ 

	documentaryLine = documentaryLine + "/"; 

	writeFile<<documentaryLine<<getName()<<endl;

	if (this->next != NULL)
	{
		this->next->outputRecursiveControlNext(documentaryLine,writeFile) ;		
	}

	if (this->inNext != NULL)
	{
		documentaryLine = documentaryLine + getName() ;	
		this->inNext->outputRecursiveControl(documentaryLine,writeFile);
	}else if (this->inFile != NULL)
	{
		documentaryLine = documentaryLine + getName() ;	
		this->inFile->outputRecursiveControl(documentaryLine,writeFile);
	}

}	

//recursive bir şekilde bir sonraki nextleri kontrol eder.
void baseClass::outputRecursiveControlNext(string documentaryLine,ofstream & writeFile){

	writeFile<<documentaryLine<<getName()<<endl;

	if (this->next != NULL)
	{
		this->next->outputRecursiveControlNext(documentaryLine,writeFile);		
	}	

}

//kopyalanacak dökümanı bulur ve kopyalanacak yere kopyalanır.
void baseClass::copyDirectoryFiles(string copyDocument,string preTempLine,string tempLine,baseClass * currentDirectory){

	if (getName() == tempLine) 	//kopyalanacak yer belirlenir.
	{
		if (this->inNext!=NULL)
		{
			this->inNext->copyDirectoryFiles2(copyDocument,preTempLine,currentDirectory);
			
		}
	}else{
		if (this->inNext != NULL){
			this->inNext->copyDirectoryFiles(copyDocument,preTempLine,tempLine,currentDirectory);			
		}

	}
}


//kopyalanacak yerin next kısmı boş olana kadar aranır.
void baseClass::copyDirectoryFiles2(string copyDocument,string preTempLine,baseClass * currentDirectory){

	if (this->next !=NULL ){
		this->next->copyDirectoryFiles2(copyDocument,preTempLine,currentDirectory);	

	}else{
		baseClass * a;
		a = new baseClass ;
		a = currentDirectory->copyDocument(copyDocument,preTempLine) ; 
		baseClass * b ;
		b = new baseClass ;
		b->setName(a->getName());
		this->next = b ;
		b->preNext = this ;
	}
}

//kopyalanacak objenin hangi documentda olduğu tespit edileceği döngü
baseClass * baseClass::copyDocument(string copyDocument,string preTempLine){

	if (preTempLine == getName())
	{
		if (inNext != NULL)
		{
			return this->inNext->copyDocument2(copyDocument,preTempLine);
		}else if(inFile  != NULL){
			return	this->inFile->copyDocument2(copyDocument,preTempLine);
		}

	}else{

		if (this->inNext != NULL)
		{
			return this->inNext->copyDocument(copyDocument,preTempLine);		
		}	
	}

}

//kopyalanacak dökümanı son olarak burada bulur.
baseClass *  baseClass::copyDocument2(string copyDocument,string preTempLine)
{
	if (getName() == copyDocument)
	{
		return this ;
		
	}else{
		if (this->next == NULL)
		{
			return this->next->copyDocument2(copyDocument,preTempLine);
		}
	}	

}

//------

//taşınacak dökümanı bulur ve kopyalanacak yere kopyalanır.
void baseClass::moveDirectoryFiles(string copyDocument,string preTempLine,string tempLine,baseClass * currentDirectory){

	if (getName() == tempLine) 	//kopyalanacak yer belirlenir.
	{
		if (this->inNext!=NULL)
		{
			this->inNext->moveDirectoryFiles2(copyDocument,preTempLine,currentDirectory);
			
		}
	}else{
		if (this->inNext != NULL){
			this->inNext->moveDirectoryFiles(copyDocument,preTempLine,tempLine,currentDirectory);			
		}

	}
}


//taşınacak yerin next kısmı boş olana kadar aranır.
void baseClass::moveDirectoryFiles2(string copyDocument,string preTempLine,baseClass * currentDirectory){

	if (this->next !=NULL ){
		this->next->moveDirectoryFiles2(copyDocument,preTempLine,currentDirectory);	

	}else{
		baseClass * a;
		a = new baseClass ;
		a = currentDirectory->moveDocument(copyDocument,preTempLine) ; 
		baseClass * b ;
		b = new baseClass ;

		b->setName(a->getName());
		this->next = b ;
		b->preNext =this;
	}
}

//taşınacak objenin hangi documentda olduğu tespit edileceği döngü
baseClass * baseClass::moveDocument(string copyDocument,string preTempLine){

	
	if (preTempLine == getName())
	{
		if (inNext != NULL)
		{
			return this->inNext->moveDocument2(copyDocument,preTempLine);
		}else if(inFile  != NULL){
			return	this->inFile->moveDocument2(copyDocument,preTempLine);
		}

	}else{

		if (this->inNext != NULL)
		{
			return this->inNext->moveDocument(copyDocument,preTempLine);		
		}	
	}

}

//taşınacak dökümanı son olarak burada bulur.
baseClass *  baseClass::moveDocument2(string copyDocument,string preTempLine)
{
	if (getName() == copyDocument)
	{
		this->preNext->next = NULL ;

		return this ;
		
	}else{
		if (this->next != NULL)
		{
			return this->next->moveDocument2(copyDocument,preTempLine);
		}
	}	

}

int baseClass::deleteControl(string tempLine){

	if(this->inNext != NULL){

		if (this->inNext->getName() == tempLine)
		{
			return 1 ;
	
		}else if (this->inNext != NULL)
		{
			return	this->inNext->deleteControl(tempLine);
		}

	}
	return 0;
}

//silinecek file hangi directoryde ise o bulunur burda
void baseClass::deleteFile(string preTempLine,string tempLine){

	if (this->getName() == preTempLine)
	{
		if (this->inNext != NULL)
		{
			
			this->inNext->deleteFile2(tempLine);
		}else if (this->inFile != NULL)
		{
			this->inFile->deleteFile2(tempLine);
		}
	
	}else{

		if (this->inNext != NULL)
		{
			this->inNext->deleteFile(preTempLine,tempLine);
		}

	} 	
}

//yanlarındaki nextlere bakılır.
void baseClass::deleteFile2(string tempLine){

	if (getName() != tempLine)
	{	
		if (this->next != NULL)
		{
			this->next->deleteFile2(tempLine);
		}
	}else 
	{	
		this->preNext->next = NULL ;
	}
}

//silinecek directory bulunur.
void baseClass::deleteDirectory(string tempLine)
{
	if (getName() == tempLine)
	{
		if (this->outNext->inNext != NULL)
		{
			
			this->outNext->inNext = this->next ;
			this->outNext->inNext = NULL ;			
			cout<<this->getName()<<endl;
		}
	}else{

		if (this->inNext != NULL)
		{
			this->inNext->deleteDirectory(tempLine);
		}
	}
}

//BASECLASS DESTRUCTORI
baseClass::~baseClass(){

	if (inFile != NULL)
	{
		delete inFile;
	}
	if (inNext != NULL)
	{
		delete inNext;
	}
	if (next != NULL)
	{
		delete next;
	}
	if (outNext != NULL)
	{
		delete outNext;
	}
	if (preNext != NULL)
	{
		delete preNext;
	}
}