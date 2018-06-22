
// 171044086 _HAMZA _YOĞURTCUOĞLU   18:30 22.05.2018 
	
/*
	
	DİKKAT data.txt dosyasındaki formatta test ediniz. 
	Örnek : 
	
	movie
	"The Lord of the Rings: The Fellowship of the Ring" "Peter Jackson" "2001" "Adventure, Drama,Fantasy" "Elijah Wood, Ian McKellen, Orlando Bloom"
	"Twelve Monkeys" "Terry Gilliam" "1995" "Mystery, Sci-Fi, Thriller" " Bruce Willis, Madeleine Stowe, Brad Pitt"
	"Twelve Monkeys" "" "" "Sci-Fi, Thriller" " Bruce Willis, Madeleine Stowe, Brad Pitt"
	"Perfume: The Story of a Murderer" " Tom Tykwer" "2006" "Crime, Drama, Fantasy" "Ben Whishaw,Dustin Hoffman, Alan Rickman"
	"Twelve Monkeys" "" "" "Mystery, Sci-Fi, Thriller" " Bruce Willis, Madeleine Stowe, Brad Pitt"

	DİKKAT commands.txt dosyasındaki formatta test ediniz. 
	Örnek : 
			search "Monkeys" in "title"
			search "Spice" in "genre"
			sort "year"
			search "1995" in "year"
	
	COMPILER (MAKEFILE) :
			make (dosyaları derler)	
			make clean  (obje kodları siler)
			make run (exe dosyasını çalıştırır) ---- veya ./exe	
*/				

/*	
	Dosya dizini oluşturan program.
 	Komutlar :  delete 
				move
				copy
				cd
				cd ..
				cd /
*/

#include "catalogType.h"
#include "catalogOperation.h"

using namespace std;

int main(){

	catalogOperation * objectCatalogOperation ;	//data.txt dosyası okunur 
	objectCatalogOperation = new catalogOperation ;

	ofstream writeFile ;
	writeFile.open("output.txt");
	objectCatalogOperation->uniqueEntries(writeFile);// okunan data.txtden alınan veriler sonucunda unique entries bulunur.
													//	output.txt ye exception olarak yazılır.
	objectCatalogOperation->sortSearch(writeFile); //	sort ve search comutları burda gerçekleştirilir.
}