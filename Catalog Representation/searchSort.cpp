
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


void catalogOperation::sortSearch(ofstream & writeFile){

	string tempLine; //search veya sort hangisi olduğu bulunur.
	string allLine; //tek bir line direk alınır.
	string search; //search edilecek kelime
	string ignore;	//bu kısım parse edilirken ignore edilir.
	string type; //sort veya search edilecek tür öğrenilir.
	ifstream getFile;
	getFile.open("commands.txt");
	while(std::getline(getFile,allLine)){

		istringstream allLineTemp (allLine);
		
		std::getline(allLineTemp,tempLine,'"');

			if (tempLine == "search ") // search işlemi gerçekleştirilir.
			{
				std::getline(allLineTemp,search,'"');
				std::getline(allLineTemp,ignore,'"');
				std::getline(allLineTemp,type,'"'); 

				if (operationString == "movie")
				{
					try{
						if (type!="title"&&type!="director"&&type!="year"&&type!="genre"&&type!="starring")
							throw "Exception: command is wrong" ; // herhangi seçenek yoksa exception hatası atılır. 
						
						else {for (int i = 0; i < index; ++i){	//control yapılır hangi bölümden arama yapıldıysa
								if (type == "title") 
								{								//-1 olursa anlaşılırki o bölümde o kelime yok
									if(movieS[i].getTitle().find(search) != -1 && movieS[i].getExceptionControl()==0){
										
										movieS[i].setMovieSearchControl();
										setSearchControl();
									}	
								}else if (type == "director") 
								{
									if(movieS[i].getDirector().find(search) != -1 && movieS[i].getExceptionControl()==0){
										
										movieS[i].setMovieSearchControl();
										setSearchControl();
									}	
								}else if (type == "year") 
								{
									if(movieS[i].getYear().find(search) != -1 && movieS[i].getExceptionControl()==0){
										
										movieS[i].setMovieSearchControl();
										setSearchControl();
									}	
								}else if (type == "genre") 
								{
									if(movieS[i].getGenre().find(search) != -1 && movieS[i].getExceptionControl()==0){
										movieS[i].setMovieSearchControl();
										setSearchControl();
									}	
								}else if (type == "starring") 
								{
									if(movieS[i].getStarring().find(search) != -1 && movieS[i].getExceptionControl()==0){
										movieS[i].setMovieSearchControl();
										setSearchControl();
									}	
								}
							}	
						}					
						if (getSearchControl() == 0)
							throw "Exception: command is wrong" ;
						else{
							
							writeFile<<tempLine<<'"'<<search<<'"'<<" in "<<'"'<<type<<'"'<<endl;
							for (int i = 0; i < index; ++i)
							{
								if (movieS[i].getMovieSearchControl() != 0)
								{
									writeFile<<movieS[i].getTitle()<<" "<<movieS[i].getDirector()<<" "<<movieS[i].getYear()
									<<" "<<movieS[i].getGenre()<<" "<<movieS[i].getStarring()<<endl;
									movieS[i].movieSearcReset();
								}		
							}	
							resetSearchControl(); //eğer search yapılırken bir değer bulunduyda exception fırlatılmaz
												 //ve search döküman sayısı resetlenir.
						}							

					}catch(const char * exception){

						writeFile<<exception<<endl;
						writeFile<<allLine<<endl;
					}

				}
				else if (operationString == "music")
				{
					try{
						if (type!="title"&&type!="artists"&&type!="year"&&type!="genre")
							throw "Exception: command is wrong" ;	// herhangi seçenek yoksa exception hatası atılır.
						
						else {for (int i = 0; i < index; ++i){	//control yapılır hangi bölümden arama yapıldıysa
								if (type == "title") 
								{								//-1 olursa anlaşılırki o bölümde o kelime yok
									if(musicS[i].getTitle().find(search) != -1 && musicS[i].getExceptionControl()==0){
										musicS[i].setMusicSearchControl();
										setSearchControl();
									}	
								}else if (type == "artists") 
								{
									if(musicS[i].getArtists().find(search) != -1 && musicS[i].getExceptionControl()==0){
										musicS[i].setMusicSearchControl();
										setSearchControl();
									}	
								}else if (type == "year") 
								{
									if(musicS[i].getYear().find(search) != -1 && musicS[i].getExceptionControl()==0){
										musicS[i].setMusicSearchControl();
										setSearchControl();
									}	
								}else if (type == "genre") 
								{
									if(musicS[i].getGenre().find(search) != -1 && musicS[i].getExceptionControl()==0){
										musicS[i].setMusicSearchControl();
										setSearchControl();
									}	
								}
							}	
						}					
						if (getSearchControl() == 0)
							throw "Exception: command is wrong" ;
						else{
							
							writeFile<<tempLine<<'"'<<search<<'"'<<" in "<<'"'<<type<<'"'<<endl;
							for (int i = 0; i < index; ++i)
							{
								if (musicS[i].getMusicSearchControl() != 0)
								{
									writeFile<<musicS[i].getTitle()<<" "<<musicS[i].getArtists()<<" "<<musicS[i].getYear()
									<<" "<<musicS[i].getGenre()<<endl;
									musicS[i].musicSearcReset();
								}		
							}	

							resetSearchControl(); //eğer search yapılırken bir değer bulunduyda exception fırlatılmaz
						}							//ve search döküman sayısı resetlenir.

					}catch(const char * exception){

						writeFile<<exception<<endl;
						writeFile<<allLine<<endl;
					}

				}
				else if (operationString == "book")
				{
					try{
						if (type!="title"&&type!="authors"&&type!="year"&&type!="tags")
							throw "Exception: command is wrong" ;	// herhangi seçenek yoksa exception hatası atılır.
						
						else {for (int i = 0; i < index; ++i){ //control yapılır hangi bölümden arama yapıldıysa
								if (type == "title") 
								{									//-1 olursa anlaşılırki o bölümde o kelime yok
									if(bookS[i].getTitle().find(search) != -1 && bookS[i].getExceptionControl()==0){
										bookS[i].setBookSearchControl();
										setSearchControl();
									}	
								}else if (type == "authors") 
								{
									if(bookS[i].getAuthors().find(search) != -1 && bookS[i].getExceptionControl()==0){
										bookS[i].setBookSearchControl();
										setSearchControl();
									}	
								}else if (type == "year") 
								{
									if(bookS[i].getYear().find(search) != -1 && bookS[i].getExceptionControl()==0){
										bookS[i].setBookSearchControl();
										setSearchControl();
									}	
								}else if (type == "tags") 
								{
									if(bookS[i].getTags().find(search) != -1 && bookS[i].getExceptionControl()==0){
										bookS[i].setBookSearchControl();
										setSearchControl();
									}	
								}
							}	
						}					
						if (getSearchControl() == 0)
							throw "Exception: command is wrong" ; // herhangi seçenek yoksa exception hatası atılır.
						else{
							
							writeFile<<tempLine<<'"'<<search<<'"'<<" in "<<'"'<<type<<'"'<<endl;
							for (int i = 0; i < index; ++i)
							{
								if (bookS[i].getBookSearchControl() != 0)
								{
									writeFile<<bookS[i].getTitle()<<" "<<bookS[i].getAuthors()<<" "<<bookS[i].getYear()
									<<" "<<bookS[i].getTags()<<endl;
									bookS[i].bookSearcReset();
								}		
							}	

							resetSearchControl(); //eğer search yapılırken bir değer bulunduyda exception fırlatılmaz
						}							//ve search döküman sayısı resetlenir.

					}catch(const char * exception){

						writeFile<<exception<<endl;
						writeFile<<allLine<<endl;
					}

				}

			}else if (tempLine == "sort ") 	//sort işlemi bu sorguda yapılır.
			{
				std::getline(allLineTemp,type,'"');
				
				if (operationString == "movie")
				{
					try{

						set<string>SORT;
						if (type!="title"&&type!="director"&&type!="year"&&type!="genre"&&type!="starring")
							throw "Exception: command is wrong" ;
						else{

							if (type == "title"){
								for (int i = 0; i < index; ++i){
									if (movieS[i].getExceptionControl() == 0)
										SORT.insert(movieS[i].getTitle());
								}

								set<string>::const_iterator iterator ;
							
								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == movieS[i].getTitle())&&(movieS[i].getExceptionControl() == 0)&&(movieS[i].getSortControl()==0)){
										
											movieS[i].setSortControl();
											writeFile<<movieS[i].getTitle()<<" "<<movieS[i].getDirector()<<" "<<movieS[i].getYear()
											<<" "<<movieS[i].getGenre()<<" "<<movieS[i].getStarring()<<endl;	
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									movieS[i].sortControlReset();
									
							}else if (type == "director"){
								for (int i = 0; i < index; ++i){
									if (movieS[i].getExceptionControl() == 0)
										SORT.insert(movieS[i].getDirector());
								}
								
								set<string>::const_iterator iterator ;		//iterator işlemi sort edilimiş
																			//set template içinde arama için kullanılır.		
								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == movieS[i].getDirector())&&(movieS[i].getExceptionControl() == 0)&&(movieS[i].getSortControl()==0)){
										
											movieS[i].setSortControl();
											writeFile<<movieS[i].getTitle()<<" "<<movieS[i].getDirector()<<" "<<movieS[i].getYear()
											<<" "<<movieS[i].getGenre()<<" "<<movieS[i].getStarring()<<endl;	
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									movieS[i].sortControlReset();

							}else if (type == "year"){
								for (int i = 0; i < index; ++i){
									if (movieS[i].getExceptionControl() == 0)
										SORT.insert(movieS[i].getYear());
								}

								set<string>::const_iterator iterator ;
											//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.
							
								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == movieS[i].getYear())&&(movieS[i].getExceptionControl() == 0)&&(movieS[i].getSortControl()==0)){
										
											movieS[i].setSortControl();
											writeFile<<movieS[i].getTitle()<<" "<<movieS[i].getDirector()<<" "<<movieS[i].getYear()
											<<" "<<movieS[i].getGenre()<<" "<<movieS[i].getStarring()<<endl;	
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									movieS[i].sortControlReset();

							}else if (type == "genre"){
								for (int i = 0; i < index; ++i){
									if (movieS[i].getExceptionControl() == 0)
										SORT.insert(movieS[i].getGenre());
								}

								set<string>::const_iterator iterator ;
											
											//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.
								
								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == movieS[i].getGenre())&&(movieS[i].getExceptionControl() == 0)&&(movieS[i].getSortControl()==0)){
										
											movieS[i].setSortControl();
											writeFile<<movieS[i].getTitle()<<" "<<movieS[i].getDirector()<<" "<<movieS[i].getYear()
											<<" "<<movieS[i].getGenre()<<" "<<movieS[i].getStarring()<<endl;	
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									movieS[i].sortControlReset();

							}else if (type == "starring"){
								for (int i = 0; i < index; ++i){
									if (movieS[i].getExceptionControl() == 0)
										SORT.insert(movieS[i].getStarring());
								}

								set<string>::const_iterator iterator ;
											//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.

								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == movieS[i].getStarring())&&(movieS[i].getExceptionControl() == 0)&&(movieS[i].getSortControl()==0)){
										
											movieS[i].setSortControl();
											writeFile<<movieS[i].getTitle()<<" "<<movieS[i].getDirector()<<" "<<movieS[i].getYear()
											<<" "<<movieS[i].getGenre()<<" "<<movieS[i].getStarring()<<endl;	
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									movieS[i].sortControlReset();

							}	
						}	


					}catch(const char * exception){	//eğer sort edilecek alan yoksa burda catch edilir

						writeFile<<exception<<endl;
						writeFile<<allLine<<endl;

					}
					
				}else if (operationString == "music"){
					try{

						set<string>SORT;
						if (type!="title"&&type!="artists"&&type!="year"&&type!="genre")
							throw "Exception: command is wrong" ;
						else{

							if (type == "title"){
								for (int i = 0; i < index; ++i){
									if (musicS[i].getExceptionControl() == 0)
										SORT.insert(musicS[i].getTitle());
								}

								set<string>::const_iterator iterator ;
											//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.	
								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == musicS[i].getTitle())&&(musicS[i].getExceptionControl() == 0)&&(musicS[i].getSortControl()==0)){
										
											musicS[i].setSortControl();
											writeFile<<musicS[i].getTitle()<<" "<<musicS[i].getArtists()<<" "<<musicS[i].getYear()
											<<" "<<musicS[i].getGenre()<<endl;
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									musicS[i].sortControlReset();
									
							}else if (type == "artists"){
								for (int i = 0; i < index; ++i){
									if (musicS[i].getExceptionControl() == 0)
										SORT.insert(musicS[i].getArtists());
								}

								set<string>::const_iterator iterator ;
											//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.
								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == musicS[i].getArtists())&&(musicS[i].getExceptionControl() == 0)&&(musicS[i].getSortControl()==0)){
										
											musicS[i].setSortControl();
											writeFile<<musicS[i].getTitle()<<" "<<musicS[i].getArtists()<<" "<<musicS[i].getYear()
											<<" "<<musicS[i].getGenre()<<endl;
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									musicS[i].sortControlReset();

							}else if (type == "year"){
								for (int i = 0; i < index; ++i){
									if (musicS[i].getExceptionControl() == 0)
										SORT.insert(musicS[i].getYear());
								}

								set<string>::const_iterator iterator ;
												//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.

								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == musicS[i].getYear())&&(musicS[i].getExceptionControl() == 0)&&(musicS[i].getSortControl()==0)){
										
											musicS[i].setSortControl();
											writeFile<<musicS[i].getTitle()<<" "<<musicS[i].getArtists()<<" "<<musicS[i].getYear()
											<<" "<<musicS[i].getGenre()<<endl;
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									musicS[i].sortControlReset();

							}else if (type == "genre"){
								for (int i = 0; i < index; ++i){
									if (musicS[i].getExceptionControl() == 0)
										SORT.insert(musicS[i].getGenre());
								}
								set<string>::const_iterator iterator ;
											//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.
								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == musicS[i].getGenre())&&(musicS[i].getExceptionControl() == 0)&&(musicS[i].getSortControl()==0)){
										
											musicS[i].setSortControl();
											writeFile<<musicS[i].getTitle()<<" "<<musicS[i].getArtists()<<" "<<musicS[i].getYear()
											<<" "<<musicS[i].getGenre()<<endl;
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									musicS[i].sortControlReset();
							}	
						}	
					}catch(const char * exception){	//eğer sort edilecek alan yoksa burda catch edilir

						writeFile<<exception<<endl;
						writeFile<<allLine<<endl;

					}
				}else if (operationString == "book"){
					
					try{

						set<string>SORT;
						if (type!="title"&&type!="authors"&&type!="year"&&type!="tags")
							throw "Exception: command is wrong" ;
						else{

							if (type == "title"){
								for (int i = 0; i < index; ++i){
									if (bookS[i].getExceptionControl() == 0)
										SORT.insert(bookS[i].getTitle());
								}

								set<string>::const_iterator iterator ;
												//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.
								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == bookS[i].getTitle())&&(bookS[i].getExceptionControl() == 0)&&(bookS[i].getSortControl()==0)){
										
											bookS[i].setSortControl();
											writeFile<<bookS[i].getTitle()<<" "<<bookS[i].getAuthors()<<" "<<bookS[i].getYear()
											<<" "<<bookS[i].getTags()<<endl;
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									bookS[i].sortControlReset();
									
							}else if (type == "authors"){
								for (int i = 0; i < index; ++i){
									if (bookS[i].getExceptionControl() == 0)
										SORT.insert(bookS[i].getAuthors());
								}

								set<string>::const_iterator iterator ;
											//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.
								writeFile<<"sort "<<'"'<<type<<'"'<<endl;
								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == bookS[i].getAuthors())&&(bookS[i].getExceptionControl() == 0)&&(bookS[i].getSortControl()==0)){
										
											bookS[i].setSortControl();
											writeFile<<bookS[i].getTitle()<<" "<<bookS[i].getAuthors()<<" "<<bookS[i].getYear()
											<<" "<<bookS[i].getTags()<<endl;
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									bookS[i].sortControlReset();
									
							}else if (type == "year"){
								for (int i = 0; i < index; ++i){
									if (bookS[i].getExceptionControl() == 0)
										SORT.insert(bookS[i].getYear());
								}

								set<string>::const_iterator iterator ;
											//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.

								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == bookS[i].getYear())&&(bookS[i].getExceptionControl() == 0)&&(bookS[i].getSortControl()==0)){
										
											bookS[i].setSortControl();
											writeFile<<bookS[i].getTitle()<<" "<<bookS[i].getAuthors()<<" "<<bookS[i].getYear()
											<<" "<<bookS[i].getTags()<<endl;
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									bookS[i].sortControlReset();

							}else if (type == "tags"){
								for (int i = 0; i < index; ++i){
									if (bookS[i].getExceptionControl() == 0)
										SORT.insert(bookS[i].getTags());
								}

								set<string>::const_iterator iterator ;
												//iterator işlemi sort edilimiş
											//set template içinde arama için kullanılır.
								writeFile<<"sort "<<'"'<<type<<'"'<<endl;

								for ( iterator  = SORT.begin(); iterator !=SORT.end() ; iterator++)
								{
									for (int i = 0; i < index; ++i)
									{
										if ((*iterator == bookS[i].getTags())&&(bookS[i].getExceptionControl() == 0)&&(bookS[i].getSortControl()==0)){
										
											bookS[i].setSortControl();
											writeFile<<bookS[i].getTitle()<<" "<<bookS[i].getAuthors()<<" "<<bookS[i].getYear()
											<<" "<<bookS[i].getTags()<<endl;
										}
									}
								}	
								for (int i = 0; i < index; ++i)
									bookS[i].sortControlReset();
							}	
						}	
					}catch(const char * exception){//eğer sort edilecek alan yoksa burda catch edilir

						writeFile<<exception<<endl;
						writeFile<<allLine<<endl;
					}
				}
			}
	}
}