//Assignment_2_HamzaYoğurtcuoğlu_171044086.cpp
//22.03.2018 17:30

//Tokens represent players.
//Here, ports are numbered (1,2,3,4,5,6,7,8).
// A path card can be rotated clockwise or counter-clockwise(repeatedly)
//This game will be played on a 2D grid.
//On the sides of the grid 'o's represent exit/entry ports of the game.
//CORDINATE 1,2,3,4,5,6,7,8,9 FROM LEFT TO RIGHT
//IKI KISILIK 3X3 TSURO GAME
//COMPILER     g++ -std=c++11 assignment_2_HAMZAYOĞURTCUOĞLU_171044086.cpp -o assignment_2_HAMZAYOĞURTCUOĞLU_171044086

/*############################################################################*/
/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
/*----------------------------------------------------------------------------*/
/*------------------------------Includes--------------------------------------*/
/*----------------------------------------------------------------------------*/

#include<iostream>
#include<vector>
#include<stdlib.h>
#include<time.h>

using namespace std; 

class userClass ;   
class mapClass ;
class cardClass;

class gameClass             //birçok classı birleştiren ana oyun classı
{
	public:
		void allGameLoop(mapClass & gameMap , cardClass  cardObject[], userClass  user[]);    //tüm oyunun akışı bu loop içinde devam eder
        gameClass(){}                                                                         
		gameClass(int numberPlayer,mapClass & gameMap,userClass  user[]);              //kullanıcıların Map'a rastgele atamasıda yapılır.      
        int cardSelectFunction(int gamer);                                             //kullanıcı kart seçecek fonksiyon     
        void cordinateSelectFunction(cardClass  cardObject[], const userClass  user[],int gamer,int cardSelection,const mapClass & gameMap );
        void cardRotate(cardClass & cardObject,int gamer);              //kartı kulllanıcı istediği kadar rotate edebilir.(saat yönüne ve tersine)
        int gameSafeExit( mapClass & gameMap , userClass user [],int i);       //kullanıcıların tokenleri sorgulanır port kontrolü ve oyun çıkışı
        
    private:
    int cordinateChange ( mapClass & gameMap , userClass user [],int i ,int  & counter,int ,int ,int ,int ,int ,int  ) ;  //kullanıcının yeni konumu bulunur.
};

//Oyunun haritasını tutan class
class mapClass
{       
    public:
        friend void  operator +(const cardClass & cardObject , mapClass & gameMap);     //kullanıcının kartını haritaya ekleyen fonksiyon     
		friend class gameClass;                                                          
        inline int getterDimention(){return dimension;}                                     
        mapClass();
		void createBigMap();                      //haritayı ilk oluşumunu sağlayan fonksiyon (empty map)    
		void printMap()const;                     //haritayı ekrana yazdıran fonskiyon
	private:
		int dimension ;                           //haritanın kaça kaçlık olduğunu tutan değişken 
		vector<vector<char>> map;                 //2D vectör oyunun haritasını tutar.		
};

class userClass
{
	public:	
		friend class cardClass;	
		friend class gameClass;
		userClass(){}
		userClass(int i);             //kullanıcının tokeni belirlenir
	private:
		char userToken;	              //kullanıcınn karakter tokeni
		int row,column ;       //kullanıcınn karakternin nerde olduğunu tutan  değişken indexleri   
        int cardIndex[3];      //kullanıcının sahip olduğu kart indexleri
        int firstControl = 0 ; //portaldan ilk çıkış 
        char tempKeep ;        //bir önceki ve bir sonra character tutulur.
        int nextCardTransfer = 0;
};

class cardClass
{
	public:
        friend void  operator +(const cardClass & cardObject , mapClass & gameMap); 
        friend class userClass;
		friend class gameClass;
        cardClass();
		void printCard()const ;
	    void assignPath(int i,int j);

    private:
		vector<vector<char>> card;
		int counter1=0,counter2 = 0,counter3 = 0,counter4 = 0,
			counter5 = 0 ,counter6 =0,counter7 = 0,counter8 = 0;		//random sayılar bir daha aynı gelmesin diye atanan değişkenler
        int cordinate ;    
};

void welcomeToGamePrint();                                              // oyuncuları karşılayan print fonksiyon.   
int numberPlayerFunction();                                             //kullanıcı sayısı alınır.
void  operator +(const cardClass & cardObject , mapClass & gameMap);    //seçilen kartı mapa assign eden overload edilmiş fonksiyon


int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int numberPlayer;

	welcomeToGamePrint();

	mapClass gameMap;

    gameMap.createBigMap();	// Allocated vector for big map

    numberPlayer = numberPlayerFunction();

  	userClass user[numberPlayer];        //gamer sayısı kadar obje oluşturulur.

  	for (int i = 0; i < numberPlayer; ++i)	//explicit constructer bize tek tek kullanıcıdan token almamızı sağlıyor.
    	user[i] = userClass(i); 	

    gameClass mainGame(numberPlayer,gameMap,user);

    //system("clear");

    gameMap.printMap(); //mapın print fonksiyonu

	cardClass cardObject[gameMap.getterDimention()*numberPlayer*3]; //oyun max oynanış durumuna göre her zaman kullancıların elinde 3 kart olacak.

    mainGame.allGameLoop(gameMap,cardObject,user);  //oyunun tüm döngüsü burda gerçekleşir.

	return 0;
}
//oyun başlangıç karşılaması
void welcomeToGamePrint()
{
	cout<<"Welcome to Tsure Game\n";
	cout<<"---------------------\n\n\n";
}

//kaç kişi oynayacağını döndüren fonksiyon.
int numberPlayerFunction()
{
	int numberPlayer = 2; //kullanıcı  sayısı belirtilir.
    return numberPlayer;
}

//mapın boyutu belli oluyor !
mapClass::mapClass()
{
	dimension = 3 ;
	cout<<"\nYour Map\n";
}

// Oyun oynanacak mapın 2 boyutlu vektörünü oluşturuyor ve boyutları belirleniyor ve map için gerekli hatlar oluşturuluyor
void mapClass::createBigMap()
{
	map = vector<vector<char>>(6*dimension + 2);     //dimensiona göre iki boyutlu vektör ayırılıyor  
        
    for (int i = 0; i < 6*dimension + 2; ++i) 		//kartların boyu 6 new line ve alttan üstten 1 new line var    
         map[i] = vector<char>(dimension*12 + 4);	// her kart 12 karakter uzunluğunda ve map baştan iki ve sondan iki karakter fazladan var
	
	map[0][0]= '-' ,map[0][1] = '-' ;		//mapın en üstünün ilk iki tiresi

	for (int i = 2; i <dimension*12 + 2; ++i)
    {
		if (i==6||i==9||i==18||i==21||i==30||i==33) //map saten 6 ya altılık olacağı için bütün kombinasyon oluşturuldu.
			map[0][i] = 'o';				// ve giriş çıkış portları konuldu.
		
		else map[0][i] = '-';				//değilse '-' konuldu.
	}

	map[0][dimension*12+2] = '-',map[0][dimension*12+3] = '-'; //mapın en üstünün son iki tiresi

	map[6*dimension + 1][0]= '-' ,map[6*dimension + 1][1] = '-' ;	//mapın en altının ilk iki tiresi

	for (int i = 2; i <dimension*12 + 2; ++i)
	{
		if (i==6||i==9||i==18||i==21||i==30||i==33) //map saten 6 ya altılık olacağı için bütün kombinasyon oluşturuldu.
			map[6*dimension + 1][i] = 'o';				// ve giriş çıkış portları konuldu.
		
        else map[6*dimension + 1][i] = '-';				//değilse '-' konuldu.
	}

	map[6*dimension + 1][dimension*12+2] = '-',map[6*dimension + 1][dimension*12+3] = '-';
	
	for (int i = 1; i < 6*dimension + 1 ; ++i)
	{	for (int j = 0; j < dimension*12 + 4; ++j)
		{
			if (i==3||i==4||i==9||i==10||i==15||i==16) //map max 6x6 olacağı için belirli noktalar seçildi ve gelince o yazar
			{
				if (j==0||j==(dimension*12+3))
					map[i][j] = 'o';
				
				else map[i][j] = ' ';			// ortalara boşluk atar
			}
			else 
			{	
				if (j==0||j==(dimension*12+3))	// 'o' nun dışında | karakteri koyar.
						map[i][j] = '|';
				
				else	map[i][j] = ' ';
			}
		}
	}
}
//Oyunun haritasını ekrana yazdıran foksiyon
void mapClass::printMap()const
{
    for(int i = 0; i < 6*dimension + 2 ; ++i)
    {   
 	  for (int j = 0; j <dimension*12+4 ; ++j)
    	  cout<<map[i][j];

	  cout<<endl;
    }  
}

//Bu constructer da tüm User'lerin karakterini belirler
userClass::userClass(int i)
{
    	if (i == 0 )
    		userToken ='X'; 	
    	else if (i == 1 )
    		userToken ='Y';    		   	    	 
}
//User'a rastgele haritadan bir porta atar.
gameClass::gameClass(int numberPlayer,mapClass & gameMap,userClass  user[])
{
	int boolenNumber ;    // iki ihtimal mevcut ya 0 ya en sağa bu yüzden  boolenNumber random alındı. 

	for (int i = 0; i < numberPlayer;)
	{
		do
		{	user[i].row = rand () % (gameMap.dimension*6+4) ;		// tokenlerin rastgele yerleştirilebilmesi için 'o' olduğu random bir yer row seçilir. 									
			                                                         
		}while(!(user[i].row==0||user[i].row==3||user[i].row==4||user[i].row==9||user[i].row==10||user[i].row==15||user[i].row==16||user[i].row==19));	

		if (user[i].row == 0 || user[i].row == 19)   
		{
			do
			{	user[i].column = rand () % (gameMap.dimension*12+2) ;  //eğer altta veya en üst ise ordaki 'o' karakterlerine atıcak' 

			}while(!(user[i].column == 6||user[i].column == 9||user[i].column == 18||user[i].column == 21||user[i].column == 30||user[i].column == 33));	
		}
		else if (!(user[i].row == 0 || user[i].row == 37))				//eğer row değilse en alt veya en üst random ya en sola yada en sağa 'o' yerine atıcak
		{
			boolenNumber = rand()% 2 ;           //iki ihtimal mevcut ya 0 ya en sağa bu yüzden  boolenNumber random tekrar alındı.

			if (boolenNumber == 0)       //en sola veya en üste koyacak.
				user[i].column = 0;         
			else
				user[i].column = gameMap.dimension*12+3;
		}
		if (gameMap.map[user[i].row][user[i].column] == 'o')
		{
			gameMap.map[user[i].row][user[i].column] = user[i].userToken; 	//eğer geçerli bir port seçildiyse diğer oyuncuya geçilecek.
			i++;
		}
	}
}
//kart oluşturma constructurı
cardClass::cardClass()
{
	card = vector<vector<char>>(6);  
    for (int i = 0; i < 6; ++i) 		//kartların boyu 6 new line ve alttan üstten 1 new line var
         card[i] = vector<char>(12);	// her kart 12 karakter uzunluğunda ve map baştan iki ve sondan iki karakter fazladan var
      
    for (int i = 0; i < 12;i++)
    {
    	if (i==4)
    		card[0][i]='1';		//kart vektörünün üstü kısmını üreten döngü
    	else if(i==7)
    		card[0][i]='2';									
    	else
    		card[0][i]='.';
    }

	for (int i = 0; i < 12;i++)
    {
    	if (i==4)
    		card[5][i]='6';		//kart vektörünün alt kısmını üreten döngü
    	else if(i==7)
    		card[5][i]='5';									
    	else
    		card[5][i]='.';
    }

    card[2][11] = '3';  //kartın orta kısmının köşelerinin sayılarını atanıyor
    card[2][0] = '8';
    card[3][11] = '4';
    card[3][0] = '7';
    for (int i = 1; i <5 ; ++i)             //kartın orta kısmını üreten döngü
    {       for (int j = 0; j < 12; ++j)
    		{
    			if ((i==1||i==4)&&(j==0||j==11))         //kartın köşelerinin çizer ':' koyar
    				card[i][j] = ':' ;

    			else if(j==1||j==2||j==3||j==5||j==6||j==8||j==9||j==10) 	
					card[i][j] = ' ' ;                                     //kartın boşluklarını ayarlar
    			else 
    			{	   				
    				if (card[i][j] == '\0')     //kartın orta kısmının pathlerini ayarlıyor.
    				{
    					int counter = 0;
    					while(counter == 0)
    					{	
                            card[i][j] = (char)(rand()%8+49);	

                            if ((counter1==0&&card[i][j]=='1')&& !((i==1)&&(j==4)))
    							counter++,++counter1,assignPath(i,j);                                                                                                                        
    						if ((counter2==0&&card[i][j]=='2')&& !((i==1)&&(j==7)))                
    							counter++,++counter2,assignPath(i,j);                               //bu döngüde 
    						if ((counter3==0&&card[i][j]=='3')&& !((i==2)&&(j==7)))                 //eğer ortadaki bağlantı yolları boş ise
    							counter++,++counter3,assignPath(i,j);                               //rastgele bir sayı atar.
    						if ((counter4==0&&card[i][j]=='4')&& !((i==3)&&(j==7)))
    							counter++,++counter4,assignPath(i,j);  
    						if ((counter5==0&&card[i][j]=='5')&& !((i==4)&&(j==7)))
    							counter++,++counter5,assignPath(i,j);
    						if ((counter6==0&&card[i][j]=='6')&& !((i==4)&&(j==4)))
    							counter++,++counter6,assignPath(i,j);
    						if ((counter7==0&&card[i][j]=='7')&& !((i==3)&&(j==4)))
    							counter++,++counter7,assignPath(i,j);
    						if ((counter8==0&&card[i][j]=='8')&& !((i==2)&&(j==4)))
    							counter++,++counter8,assignPath(i,j);
    					}	
    				}
    			}
    		}
    }
}
void cardClass::assignPath(int i,int j)
{   
    switch(card[i][j])
    {
        case '1': 
                  if (i==1 && j ==7 && counter2 ==0 )
                    card[1][4] = '2',counter2++;                            
                  if (i==2 && j==4&& counter8 == 0)                         
                    card[1][4] = '8',counter8++;
                  if (i== 2 && j == 7&& counter3 == 0)      
                    card[1][4] = '3',counter3++;
                  if (i==3 && j ==4&& counter7 == 0)
                    card[1][4] = '7',counter7++;
                  if (i== 3 && j == 7&& counter4 == 0)      
                    card[1][4] = '4',counter4++;
                  if (i==4 && j ==4&& counter6 == 0)                            //atanan sayının karşılık gelen yoluna 
                    card[1][4] = '6',counter6++;                //bağlantı yolunu yapar mesela 1 atadı 8 in karşısına
                   if (i==4 && j ==7&& counter5 == 0)                           //8 in karşısına 1 assign eder.
                    card[1][4] = '5',counter5++;
                  break;
        case '2': if (i== 1 && j == 4&& counter1 ==0)       
                    card[1][7] = '1',counter1++;
                  if (i==2 && j==4&& counter8 ==0)
                    card[1][7] = '8',counter8++;
                  if (i== 2 && j == 7&& counter3 ==0)       
                    card[1][7] = '3',counter3++;
                  if (i==3 && j ==4&& counter7 ==0)
                    card[1][7] = '7',counter7++;
                  if (i== 3 && j == 7&& counter4 ==0)       
                    card[1][7] = '4',counter4++;
                  if (i==4 && j ==4&& counter6 ==0)
                    card[1][7] = '6',counter6++;
                  if (i==4 && j ==7&& counter5 ==0)
                    card[1][7] = '5',counter5++;
                  break;         
        case '3': if (i== 1 && j == 4&& counter1 ==0)       
                    card[2][7] = '1',counter1++;
                  if (i==1 && j ==7&& counter2 ==0)
                    card[2][7] = '2',counter2++;
                  if (i==2 && j==4&& counter8 ==0)
                    card[2][7] = '8',counter8++;
                  if (i==3 && j ==4&& counter7 ==0)
                    card[2][7] = '7',counter7++;
                  if (i== 3 && j == 7&& counter4 ==0)       
                    card[2][7] = '4',counter4++;
                  if (i==4 && j ==4&& counter6 ==0)
                    card[2][7] = '6',counter6++;
                   if (i==4 && j ==7&& counter5 ==0)
                    card[2][7] = '5',counter5++;
                  break;
        case '4': if (i== 1 && j == 4&& counter1 ==0)       
                    card[3][7] = '1',counter1++;
                  if (i==1 && j ==7&& counter2 ==0)
                    card[3][7] = '2',counter2++;
                  if (i==2 && j==4&& counter8 ==0)
                    card[3][7] = '8',counter8++;
                  if (i== 2 && j == 7&& counter3 ==0)       
                    card[3][7] = '3',counter3++;
                  if (i==3 && j ==4&& counter7 ==0)
                    card[3][7] = '7',counter7++;
                  if (i==4 && j ==4&& counter6 ==0)
                    card[3][7] = '6',counter6++;
                   if (i==4 && j ==7&& counter5 ==0)
                    card[3][7] = '5',counter5++;
                  break;
        case '5': if (i== 1 && j == 4&& counter1 ==0)       
                    card[4][7] = '1',counter1++;
                  if (i==1 && j ==7&& counter2 ==0)
                    card[4][7] = '2',counter2++;
                  if (i==2 && j==4&& counter8 ==0)
                    card[4][7] = '8',counter8++;
                  if (i== 2 && j == 7&& counter3 ==0)       
                    card[4][7] = '3',counter3++;
                  if (i==3 && j ==4&& counter7 ==0)
                    card[4][7] = '7',counter7++;
                  if (i== 3 && j == 7&& counter4 ==0)       
                    card[4][7] = '4',counter4++;
                  if (i==4 && j ==4&& counter6 ==0)
                    card[4][7] = '6',counter6++;
                  break;
        case '6': if (i== 1 && j == 4&& counter1 ==0)       
                    card[4][4] = '1',counter1++;
                  if (i==1 && j ==7&& counter2 ==0)
                    card[4][4] = '2',counter2++;
                  if (i==2 && j==4&& counter8 ==0)
                    card[4][4] = '8',counter8++;
                  if (i== 2 && j == 7&& counter3 ==0)       
                    card[4][4] = '3',counter3++;
                  if (i==3 && j ==4&& counter7 ==0)
                    card[4][4] = '7',counter7++;
                  if (i== 3 && j == 7&& counter4 ==0)       
                    card[4][4] = '4',counter4++;
                   if (i==4 && j ==7&& counter5 ==0)
                    card[4][4] = '5',counter5++;
                  break;
        case '7': if (i== 1 && j == 4&& counter1 ==0)       
                    card[3][4] = '1',counter1++;
                  if (i==1 && j ==7&& counter2 ==0)
                    card[3][4] = '2',counter2++;
                  if (i==2 && j==4&& counter8 ==0)
                    card[3][4] = '8',counter8++;
                  if (i== 2 && j == 7&& counter3 ==0)   
                    card[3][4] = '3',counter3++;
                  if (i== 3 && j == 7&& counter4 ==0)   
                    card[3][4] = '4',counter4++;
                  if (i==4 && j ==4&& counter6 ==0)
                    card[3][4] = '6',counter6++;
                   if (i==4 && j ==7&& counter5 ==0)
                    card[3][4] = '5',counter5++;
                  break;
        case '8': if (i== 1 && j == 4&& counter1 ==0)   
                    card[2][4] = '1',counter1++;
                  if (i==1 && j ==7&& counter2 ==0)
                    card[2][4] = '2',counter2++;
                  if (i== 2 && j == 7&& counter3 ==0)       
                    card[2][4] = '3',counter3++;
                  if (i==3 && j ==4&& counter7 ==0)
                    card[2][4] = '7',counter7++;
                  if (i== 3 && j == 7&& counter4 ==0)       
                    card[2][4] = '4',counter4++;
                  if (i==4 && j ==4&& counter6 ==0)
                    card[2][4] = '6',counter6++;
                   if (i==4 && j ==7&& counter5 ==0)
                    card[2][4] = '5',counter5++;
                  break;                                             
    }
}
//kart ekrana yazdırılıyor
void cardClass::printCard()const
{
	for(int i = 0; i < 6 ; ++i)
 	{   
 		for (int j = 0; j <12 ; ++j)     
    		cout<<card[i][j];
   		
		cout<<endl;
	 }
}

//kartı borda ekleme bütün borda işlemler burda dönmektedir
void gameClass::allGameLoop(mapClass & gameMap , cardClass  cardObject[], userClass  user[])
{
    int j = 0 ; // buda üretilen index i yi herhangi bir kullanıcının bir index tutucusu olarak gösteren index
    int i = 0 ; //i kart üreten fonksiyonu tutan index
    int safeExitIndex = 0 ; //
    int cardSelection ;
    int gamer = 1 ;
    int gameLoop = -1 ;
    while(gameLoop == -1)
    {    
        for (; i < 6; ++i)
        {
            cardObject[i]=cardClass();
            
            user[0].cardIndex[j] = i ;  //ilk üç kart kullanıcılara verildi.

            i++;                        //bu genel kart üretme indenxi

            cardObject[i]=cardClass();  //kart üretme contructure

            user[1].cardIndex[j] = i ;   //ilk üç kart ikinci kullanıcıya verildi.       

            j++;                        //kullanıcıların tuttuğu kart indexi
        }
       
        for (int a = 0; a < 3; ++a)
           cardObject[user[gamer-1].cardIndex[a]].printCard();    //kartlar ekrana bastırılır birinci oyuncunun

        cardSelection = cardSelectFunction(gamer);

        cardRotate(cardObject[user[gamer-1].cardIndex[cardSelection-1]],gamer);

        cordinateSelectFunction(cardObject,user,gamer,cardSelection,gameMap);

        cardObject[user[gamer-1].cardIndex[cardSelection-1]] + gameMap ;

        gameLoop=gameSafeExit( gameMap ,user , safeExitIndex );

        gameMap.printMap();

        i++;

        cardObject[i]=cardClass();
            
        user[gamer-1].cardIndex[cardSelection-1] = i ;

        if (gamer%numberPlayerFunction() ==0)
            gamer = 1;
        else gamer++;
    }
    cout<<"\nI am sorry you lost player "<<gameLoop+1<<"\n\n\n" ;
}
//kartı mapa ekleyen operator
void  operator +(const cardClass & cardObject , mapClass & gameMap)
{
        for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 12; ++j)
            {
                if (cardObject.cordinate==1||cardObject.cordinate==2||cardObject.cordinate==3)          //kartı borda ekleyen operator.
                    gameMap.map[i+1][(j+2)+(cardObject.cordinate-1)*12] = cardObject.card[i][j];
                
                else if (cardObject.cordinate==4||cardObject.cordinate==5||cardObject.cordinate==6)
                     gameMap.map[i+7][(j+2)+(cardObject.cordinate-4)*12] = cardObject.card[i][j];
                
                else if (cardObject.cordinate==7||cardObject.cordinate==8||cardObject.cordinate==9)
                     gameMap.map[i+13][(j+2)+(cardObject.cordinate-7)*12] = cardObject.card[i][j];
                
            }
        }
}
//seçilen kartı döndüren fonksiyon
int gameClass::cardSelectFunction(int gamer)
{
        int cardSelection;
        cout<<"\nPlayer "<< gamer<<",Choose Your Card (1-2-3)\n";
        cin>>cardSelection;
        cin.clear();
        cin.ignore(1000,'\n');
        cout<<endl;

        while(!(cardSelection==1||cardSelection==2||cardSelection==3))  //error kontroli yapılıyor
        {
            cout<<"Wrong number entered ! Please re-enter (1-2-3)"<<endl;
            cin>>cardSelection;
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<endl;
        }        
        return cardSelection;
}
// kordinatı kullanıcıdan alan fonksiyon 
void gameClass::cordinateSelectFunction(cardClass  cardObject[], const userClass  user[],int gamer,int cardSelection,const mapClass & gameMap)
{
      int fullCordinateControl = 0 ;
      cout<<"\nPlayer "<<gamer<< ", Choose a cordinate (Left to Right 1-2-3..-9)\n"; 
      cin>>cardObject[user[gamer-1].cardIndex[cardSelection-1]].cordinate;
      cin.clear();
      cin.ignore(1000,'\n');
      cout<<endl;

      while((cardObject[user[gamer-1].cardIndex[cardSelection-1]].cordinate<1)||(cardObject[user[gamer-1].cardIndex[cardSelection-1]].cordinate>9))
      {
           cout<<"Wrong cordinate entered ! Please re-enter (Left to Right 1-2-3..-9)"<<endl;//hata kontroli durumunda kullanıcıdan tekrar alınıyor
           cin>>cardObject[user[gamer-1].cardIndex[cardSelection-1]].cordinate;
           cin.clear();
           cin.ignore(1000,'\n');
           cout<<endl;
      }
}

//card rotate etme fonksiyonu 1 verise sağ yönünün tersine 2 verirse kullanıcı saat yönüne 0 verirse çıkar fonksiyondan
void gameClass::cardRotate(cardClass & cardObject,int gamer)
{   
    int rotate ;                //sağa (2) , sola (1) veya çıkış (0) karakrını alan değişken  
    vector<char>cardTemp(16);   //geçiçi kart sayılarını tutan vektör
    do
    {   
      cout<<"\nPlayer"<<gamer <<" , Will you rotate the card (Left : 1 - Right : 2 - No : 0 )\n"; 
      cin>>rotate;
      cin.clear();
      cin.ignore(1000,'\n');
      cout<<endl;
        while(rotate<0||rotate>2)
        {
           cout<<"Wrong rotate number entered ! Please re-enter (Left : 1 - Right : 2 - No : 0 )"<<endl;
           cin>>rotate;
           cin.clear();
           cin.ignore(1000,'\n');
           cout<<endl;
        }    
        if (rotate==1)      //kartı sola döndürülecek mi sorgusu 
        {                                                   
            cardTemp[0] = cardObject.card[0][7] ;
            cardTemp[1] = cardObject.card[0][4] ;
            cardTemp[2] = cardObject.card[2][0] ;       //önceki kart sayıları tutuluyor
            cardTemp[3] = cardObject.card[3][0] ;
            cardTemp[4] = cardObject.card[5][4] ;
            cardTemp[5] = cardObject.card[5][7] ;
            cardTemp[6] = cardObject.card[3][11] ;
            cardTemp[7] = cardObject.card[2][11] ;
            cardTemp[8] = cardObject.card[1][4] ;
            cardTemp[9] = cardObject.card[1][7] ;
            cardTemp[10] = cardObject.card[2][4] ;
            cardTemp[11] = cardObject.card[2][7] ;
            cardTemp[12] = cardObject.card[3][4] ;
            cardTemp[13] = cardObject.card[3][7] ;
            cardTemp[14] = cardObject.card[4][4] ;
            cardTemp[15] = cardObject.card[4][7] ;
          
            cardObject.card[0][7] = cardTemp[6] ;
            cardObject.card[0][4] = cardTemp[7] ;
            cardObject.card[2][0] = cardTemp[0] ;
            cardObject.card[3][0] = cardTemp[1] ;
            cardObject.card[5][4] = cardTemp[2] ;
            cardObject.card[5][7] = cardTemp[3] ;         //karttaki sayılar sola döndürülüyor tutulan sayılar sayesinde
            cardObject.card[3][11] = cardTemp[4] ;
            cardObject.card[2][11] = cardTemp[5] ;
            cardObject.card[3][4] = cardTemp[8] ;
            cardObject.card[2][4] = cardTemp[9] ;
            cardObject.card[4][4] = cardTemp[10] ;
            cardObject.card[4][7] = cardTemp[12] ;
            cardObject.card[3][7] = cardTemp[14] ;
            cardObject.card[2][7] = cardTemp[15] ;
            cardObject.card[1][7] = cardTemp[13] ;
            cardObject.card[1][4] = cardTemp[11] ;
        }
        else if (rotate==2)         //kartı sağa döndürülecek mi sorgusu
        {
            cardTemp[0] = cardObject.card[0][7] ;
            cardTemp[1] = cardObject.card[0][4] ;
            cardTemp[2] = cardObject.card[2][0] ;       //önceki kart sayıları tutuluyor
            cardTemp[3] = cardObject.card[3][0] ;
            cardTemp[4] = cardObject.card[5][4] ;
            cardTemp[5] = cardObject.card[5][7] ;
            cardTemp[6] = cardObject.card[3][11] ;
            cardTemp[7] = cardObject.card[2][11] ;
            cardTemp[8] = cardObject.card[1][4] ;
            cardTemp[9] = cardObject.card[1][7] ;
            cardTemp[10] = cardObject.card[2][4] ;
            cardTemp[11] = cardObject.card[2][7] ;
            cardTemp[12] = cardObject.card[3][4] ;
            cardTemp[13] = cardObject.card[3][7] ;
            cardTemp[14] = cardObject.card[4][4] ;
            cardTemp[15] = cardObject.card[4][7] ;
       
            cardObject.card[0][7] = cardTemp[2] ;
            cardObject.card[0][4] = cardTemp[3] ;   //karttaki sayılar sağa döndürülüyor tutulan sayılar sayesinde
            cardObject.card[2][0] = cardTemp[4] ;
            cardObject.card[3][0] = cardTemp[5] ;
            cardObject.card[5][4] = cardTemp[6] ;
            cardObject.card[5][7] = cardTemp[7] ;
            cardObject.card[3][11] = cardTemp[0] ;
            cardObject.card[2][11] = cardTemp[1] ;
            cardObject.card[3][4] = cardTemp[15] ;
            cardObject.card[2][4] = cardTemp[14] ;
            cardObject.card[4][4] = cardTemp[13] ;
            cardObject.card[4][7] = cardTemp[11] ;
            cardObject.card[3][7] = cardTemp[9] ;
            cardObject.card[2][7] = cardTemp[8] ;
            cardObject.card[1][7] = cardTemp[10] ;
            cardObject.card[1][4] = cardTemp[12] ; 
        }
         cardObject.printCard();            //döndürülen kart ekrana print edilir.
    }while(rotate!=0);                      //kullanıcı 0 girdiyse döndürmeden çıkar ve fonksiyon sonlanır. 
}   
//kullanıcıların tokenleri sorgulanır port kontrolü ve oyun çıkışı
int gameClass::gameSafeExit( mapClass & gameMap , userClass user [],int i)
{

    for (; i < numberPlayerFunction(); i++)
    {
        // oyuna ilk giriş sorgusu ...
        if (user[i].firstControl == 0){
                //oyuncunun  oyuna girdimi girmedi mi sorgusu burda yapılır ve yanına kart oynanırsa direk oyuna giriş yapar
            if (user[i].row == 0 && !(gameMap.map[1][user[i].column] == ' ' )){
                user[i].tempKeep = gameMap.map[1][user[i].column] ;
                gameMap.map[1][user[i].column] = user[i].userToken ;                //bu dört sorgu kullanıcının oyuna  girebilmesi için soldan sağdan
                gameMap.map[user[i].row][user[i].column] = 'o' ;                    // yukarıdan ve aşağıdan sorgulama yapar
                user[i].firstControl++;       
                user[i].row = 1; 
            }    //   
            else if (user[i].row == gameMap.dimension*6+1 && !(gameMap.map[gameMap.dimension*6][user[i].column] == ' ' )){
                user[i].tempKeep = gameMap.map[gameMap.dimension*6][user[i].column] ;
                gameMap.map[gameMap.dimension*6][user[i].column] = user[i].userToken ;          
                gameMap.map[user[i].row][user[i].column] = 'o' ;
                user[i].firstControl++;
                user[i].row = gameMap.dimension*6 ;     
            }
            else if (user[i].column == 0 && !(gameMap.map[user[i].row][2] == ' ')){
                user[i].tempKeep = gameMap.map[user[i].row][2] ;
                gameMap.map[user[i].row][2] = user[i].userToken;
                gameMap.map[user[i].row][user[i].column] = 'o' ;
                user[i].firstControl++;
                user[i].column = 2 ; 
            }
            else if (user[i].column == gameMap.dimension*12+3 && !(gameMap.map[user[i].row][gameMap.dimension*12+1] == ' ')){
                user[i].tempKeep = gameMap.map[user[i].row][gameMap.dimension*12+1] ;
                gameMap.map[user[i].row][gameMap.dimension*12+1] = user[i].userToken;
                gameMap.map[user[i].row][user[i].column] = 'o';        
                user[i].firstControl++;
                user[i].column = gameMap.dimension*12+1  ;       
            }
        }
        
        if (user[i].column == 2 || user[i].column == 14 ||user[i].column ==26 )
        {
            int counter = 0 ;
            switch(user[i].column)
            {
                case 2 : 
                        if (user[i].row==3||user[i].row == 4){
                            cordinateChange(gameMap,user,i,counter,1,2,7,14,4,0);
                            break;}                                                           //oyunda olan kullanıncının soldan ve   
                         if (user[i].row ==9||user[i].row ==10){                              //column 2 de olanların sorgusunu yapar  
                            cordinateChange(gameMap,user,i,counter,7,2,13,14,4,0);
                            break;}
                         if (user[i].row ==15||user[i].row ==16){
                           cordinateChange(gameMap,user,i,counter,13,2,19,14,4,0);
                            break;}    
                case 14 :
                        if (user[i].row==3||user[i].row == 4){
                            cordinateChange(gameMap,user,i,counter,1,14,7,26,4,0);
                            break;}                                                             //oyunda olan kullanıncının soldan ve  
                         if (user[i].row ==9||user[i].row ==10){                                //column 14 de olanların sorgusunu yapar
                            cordinateChange(gameMap,user,i,counter,7,14,13,26,4,0);
                            break;}
                         if (user[i].row ==15||user[i].row ==16){
                           cordinateChange(gameMap,user,i,counter,13,14,19,26,4,0);
                            break;}
                case 26 :
                        if (user[i].row==3||user[i].row == 4){
                            cordinateChange(gameMap,user,i,counter,1,26,7,38,4,0);
                            break;}
                         if (user[i].row ==9||user[i].row ==10){
                            cordinateChange(gameMap,user,i,counter,7,26,13,38,4,0);          //oyunda olan kullanıncının soldan ve 
                            break;}                                                         //column 26 dan olanların sorgusunu yapar
                         if (user[i].row ==15||user[i].row ==16){
                           cordinateChange(gameMap,user,i,counter,13,26,19,38,4,0);
                            break;}
            }
        }
        else if (user[i].column ==13 || user[i].column == 25 ||user[i].column == 37 )
        {
            int counter = 0 ;
            switch(user[i].column)
            {
                case 13 : 
                         if (user[i].row==3||user[i].row == 4){
                            cordinateChange(gameMap,user,i,counter,1,2,7,14,-4,0);
                            break;}                                                       //oyunda olan kullanıcının sağdan ve
                         if (user[i].row ==9||user[i].row ==10){
                            cordinateChange(gameMap,user,i,counter,7,2,13,14,-4,0);         //column 13 dan olanların sorgusunu yapar
                            break;}
                         if (user[i].row ==15||user[i].row ==16){
                           cordinateChange(gameMap,user,i,counter,13,2,19,14,-4,0);
                            break;}    
                case 25 :
                        if (user[i].row==3||user[i].row == 4){
                            cordinateChange(gameMap,user,i,counter,1,14,7,26,-4,0);
                            break;}                                                         //oyunda olan kullanıcının sağdan 
                         if (user[i].row ==9||user[i].row ==10){
                            cordinateChange(gameMap,user,i,counter,7,14,13,26,-4,0);         //column 25 de olanların sorgusunu yapar
                            break;}
                         if (user[i].row ==15||user[i].row ==16){
                           cordinateChange(gameMap,user,i,counter,13,14,19,26,-4,0);
                            break;}
                case 37:
                        if (user[i].row==3||user[i].row == 4){
                            cordinateChange(gameMap,user,i,counter,1,26,7,38,-4,0);
                            break;}                                                         //oyunda olan kullanıcının sağdan 
                         if (user[i].row ==9||user[i].row ==10){
                            cordinateChange(gameMap,user,i,counter,7,26,13,38,-4,0);        //column 37 de olanların sorgusunu yapar
                            break;}
                         if (user[i].row ==15||user[i].row ==16){
                           cordinateChange(gameMap,user,i,counter,13,26,19,38,-4,0);
                            break;}
            }  
        }
        else if (user[i].column == 6 || user[i].column == 9 ||user[i].column == 18||user[i].column == 21||user[i].column == 30||user[i].column == 33)
        {
            int counter = 0 ;
            switch(user[i].column)
            {   case 6 :
                case 9 : 
                         if (user[i].row==1)
                            cordinateChange(gameMap,user,i,counter,1,2,7,14,0,1);
                         if (user[i].row ==7)
                            cordinateChange(gameMap,user,i,counter,7,2,13,14,0,1);
                         if (user[i].row ==13)
                           cordinateChange(gameMap,user,i,counter,13,2,19,14,0,1);
                         if (user[i].row==6)
                            cordinateChange(gameMap,user,i,counter,1,2,7,14,0,-1);
                         if (user[i].row ==12)
                            cordinateChange(gameMap,user,i,counter,7,2,13,14,0,-1);
                         if (user[i].row ==18)                                              //oyuncunun column yukarıdan ve aşşağıdan 6 ve 9 column sorgusu
                           cordinateChange(gameMap,user,i,counter,13,2,19,14,0,-1);   
                         break;    
                case 18 : 
                case 21 : 
                        if (user[i].row==1)
                            cordinateChange(gameMap,user,i,counter,1,14,7,26,0,1);
                         if (user[i].row ==7)
                            cordinateChange(gameMap,user,i,counter,7,14,13,26,0,1);
                         if (user[i].row ==13)
                           cordinateChange(gameMap,user,i,counter,13,14,19,26,0,1);
                         if (user[i].row==6)
                            cordinateChange(gameMap,user,i,counter,1,14,7,26,0,-1);          //oyuncunun column yukarıdan ve aşşağıdan 18 ve 21 column sorgusu
                         if (user[i].row ==12)
                            cordinateChange(gameMap,user,i,counter,7,14,13,26,0,-1);
                         if (user[i].row ==18)
                           cordinateChange(gameMap,user,i,counter,13,14,19,26,0,-1);   
                         break;            
                case 30 :
                case 33 :
                        if (user[i].row==1)
                            cordinateChange(gameMap,user,i,counter,1,26,7,38,0,1);
                         if (user[i].row ==7)
                            cordinateChange(gameMap,user,i,counter,7,26,13,38,0,1);
                         if (user[i].row ==13)
                           cordinateChange(gameMap,user,i,counter,13,26,19,38,0,1);          //oyuncunun column yukarıdan ve aşşağıdan 30 ve 33 column sorgusu
                        if (user[i].row==6)
                            cordinateChange(gameMap,user,i,counter,1,26,7,38,0,-1);
                         if (user[i].row ==12)
                            cordinateChange(gameMap,user,i,counter,7,26,13,38,0,-1);
                         if (user[i].row ==18)
                           cordinateChange(gameMap,user,i,counter,13,26,19,38,0,-1);   
                         break;
            }    
        }      
        if (user[i].firstControl ==1){
        
            if (gameMap.map[user[i].row][user[i].column-2] == 'o'){
                 gameMap.map[user[i].row][user[i].column] = user[i].tempKeep ;
                gameMap.map[user[i].row][user[i].column-2] = user[i].userToken;          
                return i ;
            }
            else if (gameMap.map[user[i].row][user[i].column+2] == 'o'){
                gameMap.map[user[i].row][user[i].column] = user[i].tempKeep ;           //kullanıcının kazanmadığını durumu sorgulayan sorgular
                gameMap.map[user[i].row][user[i].column+2] = user[i].userToken;       
                return i ;
            }
            else if (gameMap.map[user[i].row-1][user[i].column] == 'o'){
                gameMap.map[user[i].row][user[i].column] = user[i].tempKeep ;
                gameMap.map[user[i].row-1][user[i].column] = user[i].userToken;        
                return i ;   
            }
            else if (gameMap.map[user[i].row+1][user[i].column] == 'o'){
                gameMap.map[user[i].row][user[i].column] = user[i].tempKeep ;
                gameMap.map[user[i].row+1][user[i].column] = user[i].userToken;        
                return i ;            
            }
        }    
    }
    return -1 ;    
}
//yer değiştirecek olan gamer tokeninin yeni yerine yerleştiren foksiyon 
int gameClass::cordinateChange( mapClass & gameMap , userClass user [],int i ,int  & counter,int beginingRow,int beginingColumn,int endRow,int endColumn,int leftOrRight,int upOrDown)
{   
    int recursionStop = -1 ;

    if (user[i].nextCardTransfer == 0 ) //bu if sorgusu sayesinde gamer tokenleri transfer olmaktadır connected path numbera
    {
        for (int j = beginingRow; j <endRow ; ++j)
        {
            if (counter ==1){                       
                user[i].nextCardTransfer++;
                break;
            }

            for (int l = beginingColumn; l <endColumn ; ++l)
            {    //eğer x tokeninin karşısındaki tokenle aynı sütun ve satır bulunursa oyuncunun tokeni mapda o konuma atanır.
                if ((gameMap.map[user[i].row+upOrDown][user[i].column+leftOrRight] == gameMap.map[j][l]) && (user[i].column+leftOrRight) !=l){
                    gameMap.map[user[i].row][user[i].column] = user[i].tempKeep ;
                    user[i].tempKeep = gameMap.map[j][l] ;
                    gameMap.map[j][l] = user[i].userToken;        
                    user[i].row = j;
                    user[i].column = l ;  
                    counter++;              
                }
                    if (counter==1)//ve kartın diğer yerlerinee bakmak gerekmez döngü tamamlanır
                    break ;
            }
        }
    }     
    if ((user[i].column == 2 || user[i].column == 14 ||user[i].column ==26)&&!(gameMap.map[user[i].row][user[i].column-1] == ' ') ) {
        user[i].tempKeep = gameMap.map[user[i].row][user[i].column-1] ;
        gameMap.map[user[i].row][user[i].column-1] = user[i].userToken;         //bir yana bir sola bir üst alt geçme sorguları
        gameMap.map[user[i].row][user[i].column] = user[i].tempKeep;        
        user[i].column = user[i].column-1 ;       
        user[i].nextCardTransfer = 0 ;
        recursionStop=gameSafeExit(gameMap,user,i);  
        if (recursionStop != -1){                       //eğer gamerin kartından diğer karta geçiş varsa kontrolü yapılır (sola geçiş)
            gameMap.printMap();
            cout<<"\nI am sorry you lost player "<<recursionStop+1<<"\n\n\n" ;
            exit(1);
        }
    }                                   
    else if ((user[i].column ==13 || user[i].column == 25 ||user[i].column == 37)&& !(gameMap.map[user[i].row][user[i].column+1] == ' ')){
        user[i].tempKeep = gameMap.map[user[i].row][user[i].column+1] ;
        gameMap.map[user[i].row][user[i].column+1] = user[i].userToken;
        gameMap.map[user[i].row][user[i].column] = user[i].tempKeep  ;
        user[i].column = user[i].column+1 ;
        user[i].nextCardTransfer = 0 ;                         
        recursionStop=gameSafeExit(gameMap,user,i);      //eğer gamerin kartından diğer karta geçiş varsa kontrolü yapılır (sağa geçiş)
        if (recursionStop != -1){
            gameMap.printMap();
            cout<<"\nI am sorry you lost player "<<recursionStop+1<<"\n\n\n" ;   
            exit(1);
        }
    }
    else if (user[i].column == 6 || user[i].column == 9 ||user[i].column == 18||user[i].column == 21||user[i].column == 30||user[i].column == 33){
         if ((user[i].row == 7||user[i].row == 13)&& !(gameMap.map[user[i].row-1][user[i].column] == ' ' ))
         {
             user[i].tempKeep = gameMap.map[user[i].row-1][user[i].column] ;
             gameMap.map[user[i].row-1][user[i].column] = user[i].userToken ;
             gameMap.map[user[i].row][user[i].column] = user[i].tempKeep ;
             user[i].row = user[i].row-1;   
             user[i].nextCardTransfer = 0 ;                      //eğer gamerin kartından diğer karta geçiş varsa kontrolü yapılır (yukarı geçiş)
             recursionStop = gameSafeExit(gameMap,user,i);
             if (recursionStop != -1){
                gameMap.printMap();
                cout<<"\nI am sorry you lost player "<<recursionStop+1<<"\n\n\n" ;
                exit(1);        
             }
         }
        else if ((user[i].row == 6||user[i].row == 12)&& !(gameMap.map[user[i].row+1][user[i].column] == ' ' ))
        {
            user[i].tempKeep = gameMap.map[user[i].row+1][user[i].column] ;
            gameMap.map[user[i].row+1][user[i].column] = user[i].userToken ;
            gameMap.map[user[i].row][user[i].column] = user[i].tempKeep ;       
            user[i].row = user[i].row + 1; 
            user[i].nextCardTransfer = 0 ;
           recursionStop = gameSafeExit(gameMap,user,i);        //eğer gamerin kartından diğer karta geçiş varsa kontrolü yapılır (alt geçiş)
            if (recursionStop != -1){
                gameMap.printMap();
                cout<<"\nI am sorry you lost player "<<recursionStop+1<<"\n\n\n" ;
                exit(1);     
            }
        }
    }
}
/*############################################################################*/
/*           End of Assignment_2_HamzaYoğurtcuoğlu_171044086.cpp              */
/*############################################################################*/
