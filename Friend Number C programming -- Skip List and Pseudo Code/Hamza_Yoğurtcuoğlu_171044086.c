//HW7_Hamza_Yoğurtcuoğlu_171044086
//Kullanıcıdan Alınan Sayıyının Eğer Varsa Arkadaş Sayısını Bulan Program
#include<stdio.h>

int arkadas(int);

int main(){

	int sayi1,sayi2;
	printf("Arkadasını bulmak istediğiniz sayısıyı girin : ");
	scanf("%d",&sayi1);														//Arkadaş sayısı istenilen sayı kullanıcıdan alınır
   sayi2=arkadas(sayi1);                                       //Bu sayı arkadas fonksiyonuna arguman olarak gönderilir
   if(sayi2)                                                       //döndürülen sayı 0'dan farklı ise
   	printf("%d 'nin arkadas sayisi : %d\n",sayi1,sayi2);         //sayımızı ve arkadaş sayıyı ekrana yazdırır.
   else if(sayi2==0) printf("%d sayisinin arkadas sayisi bulunmamaktadır.\n ",sayi1); //döndürülen sayı 0 ise 
   return 0;																								  //ekrana arkadaş sayının bulunmadığını yazdırır.
}

int arkadas(int sayi){         //Eğer var ise arkadas sayısını döndüren fonksiyon
	
	int PTB1=0,PTB2=0;  	 		//Sayımızın arkadaş sayısını bulan döngü
	for(int i=1;i<sayi;i++){
		if(sayi%i==0)
			PTB1=PTB1+i;
	}
	
   for(int j=1;j<PTB1;j++){  // Arkadaş sayının çarpanlarının toplamını bulan döngü
   	if(PTB1%j==0)
   		PTB2=PTB2+j;
   }
	if(PTB2==sayi)      // Arkadaş sayımız,sayımıza eşit ise arkadaş sayımızı döndürür 
		return PTB1;
	else return 0;     //Bulunan sayı bizim sayımıza eşit değil ise 0 değeri döndürür.
}

