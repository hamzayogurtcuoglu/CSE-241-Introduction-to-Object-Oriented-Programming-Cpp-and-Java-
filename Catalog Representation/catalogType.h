
//ASSIGNMENT_6

//HAMZA YOĞURTCUOĞLU
//171044086

/*

	Catalog Olabilecek Türler
		- MOVIE
		- MUSIC
		- BOOK
	->Bu katalog türlerinin header ve getter setterlarını içerir.

*/


#ifndef CATALOGTYPE
#define CATALOGTYPE

#include<string>
#include<vector>
#include<iostream>
#include<fstream>

using namespace std;

class catalogMovie
{
	
	public:
		string getTitle(){return title;}
		string getDirector(){return director;}
		string getYear(){return year;}
		string getGenre(){return genre;}
		string getStarring(){return starring;}
		void setTitle(char titleT){title = title + titleT;}
		void setDirector(char directorT){director = director + directorT;}
		void setYear(char yearT){year = year + yearT;}
		void setGenre(char genreT){genre = genre + genreT;}
		void setStarring(char starringT){starring = starring + starringT;}
		void setIndexString(){ indexString++;}
		int getIndexString(){return indexString ;}
		int getExceptionControl(){return exceptionControl;}
		void setExceptionControl(){ exceptionControl++;}
		void movieSearcReset(){searchControl = 0;}			//search yapılır daha sonra resetlenir
		void setMovieSearchControl(){searchControl++;}		//search yapılır daha sonra resetlenir
		int getMovieSearchControl(){return searchControl;}	//search yapılır daha sonra resetlenir
		int getSortControl(){return sortControl;}	//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
		void setSortControl(){sortControl = 1;}		//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
		void sortControlReset(){sortControl = 0;}	//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
	private:
		int sortControl = 0;	//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
		int searchControl = 0;	//search yapılır daha sonra resetlenir
		string title;
		string director;
		string year;
		string genre;
		string starring;
		int indexString = 0;
		int exceptionControl = 0; // exceptionControl 0 ise exception değildir
								 //	bir ise orda hata vardır ve artık control edilmez catalogda .
};

class catalogMusic
{
	
	public:
		string getTitle(){return title;}
		string getArtists(){return artists;}
		string getYear(){return year;}
		string getGenre(){return genre;}
		void setTitle(char titleT){title = title + titleT;}
		void setArtists(char artistsT){artists = artists + artistsT;}
		void setYear(char yearT){year = year + yearT;}
		void setGenre(char genreT){genre = genre + genreT;}
		void setIndexString(){ indexString++;}
		int getIndexString(){return indexString ;}
		int getExceptionControl(){return exceptionControl;}
		void setExceptionControl(){ exceptionControl = 1;}
		void musicSearcReset(){searchControl = 0;}	//search yapılır daha sonra resetlenir
		void setMusicSearchControl(){searchControl++;}	//search yapılır daha sonra resetlenir
		int getMusicSearchControl(){return searchControl;}	//search yapılır daha sonra resetlenir
		int getSortControl(){return sortControl;}	//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
		void setSortControl(){sortControl = 1;}	//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
		void sortControlReset(){sortControl = 0;}	//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
	private:
		int sortControl = 0;		//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
		int searchControl = 0;		//search yapılır daha sonra resetlenir
		string title;
		string artists;
		string year;
		string genre;	
		int indexString = 0;
		int exceptionControl = 0; // exceptionControl 0 ise exception değildir
								 //	bir ise orda hata vardır ve artık control edilmez catalogda .
};


class catalogBook
{
	
	public:
		string getTitle(){return title;}
		string getAuthors(){return authors;}
		string getYear(){return year;}
		string getTags(){return tags;}
		void setTitle(char titleT){title = title + titleT;}
		void setAuthors(char authorsT){authors = authors + authorsT;}
		void setYear(char yearT){year = year + yearT;}
		void setTags(char tagsT){tags = tags + tagsT;}
		void setIndexString(){ indexString++;}
		int getIndexString(){return indexString ;}
		int getExceptionControl(){return exceptionControl;}
		void setExceptionControl(){ exceptionControl = 1;}
		void bookSearcReset(){searchControl = 0;}		//search yapılır daha sonra resetlenir
		void setBookSearchControl(){searchControl++;}	//search yapılır daha sonra resetlenir
		int getBookSearchControl(){return searchControl;}	//search yapılır daha sonra resetlenir
		int getSortControl(){return sortControl;}	//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
		void setSortControl(){sortControl = 1;}		//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
		void sortControlReset(){sortControl = 0;}	//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
	private:
		int sortControl = 0;	//sort yapıldıysa daha sorta kabul edilmez daha sonra resetlenir.
		int searchControl = 0;	//search yapılır daha sonra resetlenir
		string title;
		string authors;
		string year;
		string tags;
		int indexString = 0;
		int exceptionControl = 0; // exceptionControl 0 ise exception değildir
								 //	bir ise orda hata vardır ve artık control edilmez catalogda .
};


#endif