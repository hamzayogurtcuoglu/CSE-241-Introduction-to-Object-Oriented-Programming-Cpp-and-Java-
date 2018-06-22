/*08.10.2017 */
/*HW02_Hamza_Yoğurtcuoğlu_171044086*/
/*Connect 4 oyunu user1 vs user2 ve user1 vs normal level computer şeklinde oynanır*/
/*LOAD ve SAVE komutlarıyla istenilen isimde kayıt edip istenildiğinde kaydedilmiş dosyayı oyuna yazan program*/
#include <iostream>
#include<cstdlib>
#include<fstream>
#include<string>
using namespace std;
ofstream SaveData;
ifstream LoadData;
void user1(char [][20],int ,string & ,char [][20],char,int,char,string);
void user2(char[][20], int,string &,char[][20], char, int, char,string);
void computer(char[][20], int,string &);
void choosingversus(char & );
void creatingboardletter(int);
void printboard(int,char[][20]);
int choosingsize(void);
bool verticalcompare(const char [][20],const int);   //2 boyutlu array referans gönderilmektedir,
bool horizontalcompare(const char[][20],const int);  //ve bu fonksiyonların içinde bu arraylere atama
bool rightupdiagonalcompare(const char[][20],const int);//yapılmadığı için 'const' declarationı alır.
bool leftupdiagonalcompare(const char[][20],const int);
bool rightdowndiagonalcompare(const char[][20],const int);
bool leftdowndiagonalcompare(const char[][20],const int);
int Save_txt(char[][20], int ,char [][20],char,int, char,string );
int Load_txt(char[][20], int ,char [][20], char,int, char,string );
int user1_vs_user2(int ,char [][20],char [][20],string &,char, int, char);
int user1_vs_computer(int,char [][20],char [][20],string &,char,int, char);
void won(int,char=' ');
const char  letterpoint[20]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T'};

int main() {
    srand(time(NULL));
    char versus,cpversus;
    int size,cpsize;
    size=choosingsize();
    choosingversus(versus);
    char  boardpoint[20][20]={};
    string letter;
    char saveboardpoint[20][20];
    for(auto vert=0;vert<20;vert++)
        for(auto horiz=0;horiz<20;horiz++)
            boardpoint[vert][horiz]='.';
    creatingboardletter(size);
    printboard(size,boardpoint) ;

    if(versus=='P')
    user1_vs_user2(size,boardpoint,saveboardpoint,letter,versus,cpsize,cpversus);
    if(versus=='C')
        user1_vs_computer(size,boardpoint,saveboardpoint,letter,versus,cpsize,cpversus);
   
    return 0; }
/*Ekrana boardun alfabedik sıralamasını yazar*/
void creatingboardletter (int size)
{ for(int i=0;i<size;i++)
    {cout<<letterpoint[i];
        cout<<" ";}
}/*Ekrana İstenilen Boyuttaki Tahtayı Çizer*/
void printboard(int size,char boardpoint[][20])
{ for(int i=0;i<size;i++)
    {    cout<<"\n";
        for(int j=0;j<size;j++)
            cout<<boardpoint[i][j]<<" ";}}
/*İstenilen Boyutu Kullanıcıdan Alınmasını Sağlar*/
int choosingsize(void)
{ int static size;
    cout<<"Enter a even size where it should be between 4x4,6x6..20x20."<<endl;
    cin>>size;  
    cin.clear();
    cin.ignore(1000,'\n');
    if(!((size<21,size>3)&&size%2==0))
    {  cerr<<"----You entered wrong number----\n";  return choosingsize()  ;}  else return size;}
/*Kime Karşı Oynamak İstediğini Belirten Fonksiyon*/
void choosingversus(char &versus)
{ cout<<"Enter Your Section: 1) User1 vs. User2 for (P) button : \n"<<"\t\t"<<"    2) User1 vs. Computer for (C) button :  ";
    cin>>versus;
    cin.clear();
    cin.ignore(1000,'\n');
    switch(versus)
    { case 'P':break;
        case 'C':break;
        default: cerr<<"----You entered wrong letter----\n"; return choosingversus(versus); }}
void won(int challenge,char a)
{if(challenge==1){cout<<a<<" won,Conratulations :)\n"; }
if(challenge==2){cout<<"\nNobody won\n ";}}
/*Birinci kullanıcının hamlesini kontrol eden fonksiyon*/
void user1(char boardpoint [][20],int size,string & letter,char saveboardpoint[][20],char versus,int cpsize,char cpversus)
{ string temp_a,temp_b;
    cout<<"User1 enter a letter :";
    getline(cin,letter);
    cin.clear();
    char temp2=letter[0];
    if(letter.size()>=4)
    {temp_a=letter;
        temp_b=letter;
        temp_a.erase(temp_a.begin()+4,temp_a.end());
        temp_b.erase(temp_b.begin(),temp_b.end()-temp_b.length()+5);
        if(temp_a=="SAVE")
            Save_txt(boardpoint,size,saveboardpoint,versus,cpsize,cpversus,temp_b);
        else if(temp_a=="LOAD")  Load_txt(boardpoint,size,saveboardpoint,versus,cpsize,cpversus,temp_b);
        else cerr<<"\nWRONG COMMAND\n";   user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);}
    if (!(sizeof(letter[0])==sizeof(char)))
    {cerr<<"\nWRONG MOVE \n";  user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);}
    else if(size<temp2-64)
    {cerr<<"\nWRONG MOVE \n";     return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);}
    switch (temp2){
        case 'A': for(int i=size;i>0;i--)
                if(boardpoint[i-1][0]=='.')
                {       boardpoint[i-1][0]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'B': for(int i=size;i>0;i--)
                if(boardpoint[i-1][1]=='.')
                {       boardpoint[i-1][1]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'C': for(int i=size;i>0;i--)
                if(boardpoint[i-1][2]=='.')
                {       boardpoint[i-1][2]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'D': for(int i=size;i>0;i--)
                if(boardpoint[i-1][3]=='.')
                {       boardpoint[i-1][3]='x';
                    return ; }   cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'E': for(int i=size;i>0;i--)
                if(boardpoint[i-1][4]=='.')
                {       boardpoint[i-1][4]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'F': for(int i=size;i>0;i--)
                if(boardpoint[i-1][5]=='.')
                {       boardpoint[i-1][5]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'G': for(int i=size;i>0;i--)
                if(boardpoint[i-1][6]=='.')
                {       boardpoint[i-1][6]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'H': for(int i=size;i>0;i--)
                if(boardpoint[i-1][7]=='.')
                {       boardpoint[i-1][7]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'I': for(int i=size;i>0;i--)
                if(boardpoint[i-1][8]=='.')
                {       boardpoint[i-1][8]='x';
                    return ; } cerr<<"Full!\n";  return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'J': for(int i=size;i>0;i--)
                if(boardpoint[i-1][9]=='.')
                {       boardpoint[i-1][9]='x';
                    return ; } cerr<<"Full!\n";  return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'K': for(int i=size;i>0;i--)
                if(boardpoint[i-1][10]=='.')
                {       boardpoint[i-1][10]='x';
                    return ; }cerr<<"Full!\n";return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'L': for(int i=size;i>0;i--)
                if(boardpoint[i-1][11]=='.')
                {       boardpoint[i-1][11]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'M': for(int i=size;i>0;i--)
                if(boardpoint[i-1][12]=='.')
                {       boardpoint[i-1][12]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'N': for(int i=size;i>0;i--)
                if(boardpoint[i-1][13]=='.')
                {       boardpoint[i-1][13]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'O': for(int i=size;i>0;i--)
                if(boardpoint[i-1][14]=='.')
                {       boardpoint[i-1][14]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'P': for(int i=size;i>0;i--)
                if(boardpoint[i-1][15]=='.')
                {       boardpoint[i-1][15]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'Q': for(int i=size;i>0;i--)
                if(boardpoint[i-1][16]=='.')
                {       boardpoint[i-1][16]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'R': for(int i=size;i>0;i--)
                if(boardpoint[i-1][17]=='.')
                {       boardpoint[i-1][17]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'S': for(int i=size;i>0;i--)
                if(boardpoint[i-1][18]=='.')
                {       boardpoint[i-1][18]='x';
                    return ; } cerr<<"Full!\n";  return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'T': for(int i=size;i>0;i--)
                if(boardpoint[i-1][19]=='.')
                {       boardpoint[i-1][19]='x';
                    return ; }  cerr<<"Full!\n"; return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        default:  cerr<<"\nWRONG MOVE \n";  return user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus); }}
/*İkinci kullanıcının hamlesini control eden fonksiyon*/
void user2(char boardpoint[][20],int size, string &letter,char saveboardpoint[][20],char versus,int cpsize,char cpversus)
{ cout<<"\nUser2 enter a letter :";
    string temp_a,temp_b;
    getline(cin,letter);
    cin.clear();
    char temp2=letter[0];
    if(letter.size()>=4)
    {temp_a=letter;
        temp_b=letter;
        temp_a.erase(temp_a.begin()+4,temp_a.end());
        temp_b.erase(temp_b.begin(),temp_b.end()-temp_b.length()+5);
        if(temp_a=="SAVE")
            Save_txt(boardpoint,size,saveboardpoint,versus,cpsize,cpversus,temp_b);
        else if(temp_a=="LOAD")  Load_txt(boardpoint,size,saveboardpoint,versus,cpsize,cpversus,temp_b);
        else cerr<<"\nWRONG COMMAND\n"; user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);}
    if (!(sizeof(letter[0])==sizeof(char)))
    {cerr<<"\nWRONG MOVE\n"; user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);}
    else if(size<temp2-64)
    {cerr<<"\nWRONG MOVE\n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);}
    switch (temp2){
        case 'A': for( int i=size;i>0;i--)
                if(boardpoint[i-1][0]=='.')
                {       boardpoint[i-1][0]='o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'B': for(int i=size;i>0;i--)
                if(boardpoint[i-1][1]=='.')
                {       boardpoint[i-1][1]='o';
                    return ; }  cerr<<"Full!\n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'C': for(int i=size;i>0;i--)
                if(boardpoint[i-1][2]=='.')
                {       boardpoint[i-1][2]='o';
                    return ; }  cerr<<"Full!\n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'D': for(int i=size;i>0;i--)
                if(boardpoint[i-1][3]=='.')
                {       boardpoint[i-1][3]='o';
                    return ; }  cerr<<"Full!\n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'E': for(int i=size;i>0;i--)
                if(boardpoint[i-1][4]=='.')
                {       boardpoint[i-1][4]='o';
                    return ; }  cerr<<"Full!\n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'F': for(int i=size;i>0;i--)
                if(boardpoint[i-1][5]=='.')
                {       boardpoint[i-1][5]='o';
                    return ; }  cerr<<"Full!\n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'G': for(int i=size;i>0;i--)
                if(boardpoint[i-1][6]=='.')
                {       boardpoint[i-1][6]='o';
                    return ; }  cerr<<"Full!\n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'H': for(int i=size;i>0;i--)
                if(boardpoint[i-1][7]=='.')
                {       boardpoint[i-1][7]='o';
                    return ; }  cerr<<"Full!\n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'I': for(int i=size;i>0;i--)
                if(boardpoint[i-1][8]=='.')
                {       boardpoint[i-1][8]='o';
                    return ; }  cerr<<"Full!\n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'J': for(int i=size;i>0;i--)
                if(boardpoint[i-1][9]=='.')
                {       boardpoint[i-1][9]='o';
                    return ; }  cerr<<"Full!\n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'K': for(int i=size;i>0;i--)
                if(boardpoint[i-1][10]=='.')
                {       boardpoint[i-1][10]='o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'L': for(int i=size;i>0;i--)
                if(boardpoint[i-1][11]=='.')
                {       boardpoint[i-1][11]='o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'M': for(int i=size;i>0;i--)
                if(boardpoint[i-1][12]=='.')
                {       boardpoint[i-1][12]='o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'N': for(int i=size;i>0;i--)
                if(boardpoint[i-1][13]=='.')
                {       boardpoint[i-1][13]='o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'O': for(int i=size;i>0;i--)
                if(boardpoint[i-1][14]=='.')
                {       boardpoint[i-1][14]='o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'P': for(int i=size;i>0;i--)
                if(boardpoint[i-1][15]=='.')
                {       boardpoint[i-1][15]='o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'Q': for(int i=size;i>0;i--)
                if(boardpoint[i-1][16]=='.')
                {       boardpoint[i-1][16]='o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'R': for(int i=size;i>0;i--)
                if(boardpoint[i-1][17]=='.')
                {       boardpoint[i-1][17]= 'o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'S': for(int i=size;i>0;i--)
                if(boardpoint[i-1][18]=='.')
                {       boardpoint[i-1][18]='o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        case 'T': for(int i=size;i>0;i--)
                if(boardpoint[i-1][19]=='.')
                {       boardpoint[i-1][19]='o';
                    return ; } cerr<<"Full!\n";  return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        default:  cerr<<"WRONG MOVE \n"; return user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus); }}
/*Bilgisayarın yapacağı hamleleri control eden fonksiyon*/
void computer(char boardpoint[][20],int size,string &letter)
{ string temp;
    temp=letter;
    letter=rand()%20+65;
    cin.clear();
    if(!(letter==temp||letter[0]-temp[0]==1||letter[0]-temp[0]==-1))
        return computer(boardpoint,size,temp);
    else if(size<letter[0]-64)
        return computer(boardpoint,size,temp);
    switch (letter[0]){
        case 'A': for(int i=size;i>0;i--)
                if(boardpoint[i-1][0]=='.')
                {       boardpoint[i-1][0]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'B': for(int i=size;i>0;i--)
                if(boardpoint[i-1][1]=='.')
                {       boardpoint[i-1][1]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'C': for(int i=size;i>0;i--)
                if(boardpoint[i-1][2]=='.')
                {       boardpoint[i-1][2]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'D': for(int i=size;i>0;i--)
                if(boardpoint[i-1][3]=='.')
                {       boardpoint[i-1][3]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'E': for(int i=size;i>0;i--)
                if(boardpoint[i-1][4]=='.')
                {       boardpoint[i-1][4]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'F': for(int i=size;i>0;i--)
                if(boardpoint[i-1][5]=='.')
                {       boardpoint[i-1][5]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'G': for(int i=size;i>0;i--)
                if(boardpoint[i-1][6]=='.')
                {       boardpoint[i-1][6]='o';
                    return ; }  return computer(boardpoint,size,letter);
        case 'H': for(int i=size;i>0;i--)
                if(boardpoint[i-1][7]=='.')
                {       boardpoint[i-1][7]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'I': for(int i=size;i>0;i--)
                if(boardpoint[i-1][8]=='.')
                {       boardpoint[i-1][8]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'J': for(int i=size;i>0;i--)
                if(boardpoint[i-1][9]=='.')
                {       boardpoint[i-1][9]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'K': for(int i=size;i>0;i--)
                if(boardpoint[i-1][10]=='.')
                {       boardpoint[i-1][10]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'L': for(int i=size;i>0;i--)
                if(boardpoint[i-1][11]=='.')
                {       boardpoint[i-1][11]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'M': for(int i=size;i>0;i--)
                if(boardpoint[i-1][12]=='.')
                {       boardpoint[i-1][12]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'N': for(int i=size;i>0;i--)
                if(boardpoint[i-1][13]=='.')
                {       boardpoint[i-1][13]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'O': for(int i=size;i>0;i--)
                if(boardpoint[i-1][14]=='.')
                {       boardpoint[i-1][14]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'P': for(int i=size;i>0;i--)
                if(boardpoint[i-1][15]=='.')
                {       boardpoint[i-1][15]='o';
                    return ; }  return computer(boardpoint,size,letter);
        case 'Q': for(int i=size;i>0;i--)
                if(boardpoint[i-1][16]=='.')
                {       boardpoint[i-1][16]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'R': for(int i=size;i>0;i--)
                if(boardpoint[i-1][17]=='.')
                {       boardpoint[i-1][17]= 'o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'S': for(int i=size;i>0;i--)
                if(boardpoint[i-1][18]=='.')
                {       boardpoint[i-1][18]='o';
                    return ; }   return computer(boardpoint,size,letter);
        case 'T': for(int i=size;i>0;i--)
                if(boardpoint[i-1][19]=='.')
                {       boardpoint[i-1][19]='o';
                    return ; }   return computer(boardpoint,size,letter);
        default: return computer(boardpoint,size,letter); }}
/*Herhangi kullanıcıdan birinin dikey şekilde üstüste dörtlü sıralamasını kontrol eden fonksiyon*/
bool verticalcompare(const char boardpoint [][20],const int size)
{
    for(int i=0;i<=size;i++)
    {
        for(int j=size-1;j>=0;j--)
        {int counter=0;
            if (boardpoint[j][i]=='x')
            {for (auto control=j-1;control>j-4;control--)
                {if(boardpoint[control][i]=='x')counter++;
                    if(counter==3)
                        return true;}}}}
    for(int i=0;i<=size;i++)
    { for(int j=size-1;j>=0;j--)
        {int counter=0;
            if (boardpoint[j][i]=='o')
            {for (auto control=j-1;control>j-4;control--)
                {if(boardpoint[control][i]=='o')counter++;
                    if(counter==3)
                        return true;}}}} return false; }
/*Herhangi kullanıcıdan birinin yatay şekilde yanyana dörtlü sıralamasını kontrol eden fonksiyon*/
bool horizontalcompare(const char boardpoint[][20],const int size)
{ for(int i=size-1;i>=0;i--)
    { for(int j=0;j<=size;j++) {int counter=0;
            if(boardpoint[i][j]=='x')
            {for(auto control=j+1;control<j+4;control++)
                { if(boardpoint[i][control]=='x') counter++;
                    if(counter==3)
                        return true;}}}}
    for(int i=size-1;i>=0;i--) {
        for(int j=0;j<=size;j++) {int counter=0;
            if(boardpoint[i][j]=='o')
            {for(auto control=j+1;control<j+4;control++)
                { if(boardpoint[i][control]=='o') counter++;
                    if(counter==3)
                        return true;}}}}return false;       }
/*Haritanın sol üstü çapraz olarak kontrol eden foksiyon*/
bool leftupdiagonalcompare (const char boardpoint[][20],const int size)
{ for(int a=0;a<size;a++)
    {int j=-1;
        for(int k=size-1-a;k>=0;k--)
        {if (boardpoint[k][j=j+1]=='x')
            {int counter=0;
                int f=j;
                for(auto control=k-1;control>k-4;control--)
                { if(boardpoint[control][f=f+1]=='x')
                        counter++;
                    if(counter==3)
                        return true; }}}}
    for(int a=0;a<size;a++) {
        int j = -1;
        for (int k = size - 1 - a; k >= 0; k--) {
            if (boardpoint[k][j = j + 1] == 'o') {
                int counter = 0;
                int f = j;
                for (auto control = k - 1; control > k - 4; control--) {
                    if (boardpoint[control][f = f + 1] == 'o')
                        counter++;
                    if (counter == 3)
                        return true; }}}} return false; }
/*Haritanın sağ üstü çapraz olarak kontrol eder*/
bool rightupdiagonalcompare(const char boardpoint[][20],const int size)
{ for(int a=0;a<size;a++)
    {int j=size;
        for(int k=size-1-a;k>=0;k--)
        {if (boardpoint[k][j=j-1]=='x')
            {int counter=0;
                int f=j;
                for(auto control=k-1;control>k-4;control--)
                { if(boardpoint[control][f=f-1]=='x')
                        counter++;
                    if(counter==3)
                        return true; }}}}
    for(int a=0;a<size;a++)
    {int j=size;
        for(int k=size-1-a;k>=0;k--)
        {if (boardpoint[k][j=j-1]=='o')
            {int counter=0;
                int f=j;
                for(auto control=k-1;control>k-4;control--)
                { if(boardpoint[control][f=f-1]=='o')
                        counter++;
                    if(counter==3)
                        return true; }}}}return false; }
/*Haritanın sağ aşşağıyı çapraz olarak kontrol eder*/
bool rightdowndiagonalcompare(const char boardpoint[][20],const int size)
{ for(int a=0;a<size;a++)
    {int j=size;
        for(int k=0+a;size>k;k++)
        {if (boardpoint[k][j=j-1]=='x')
            {int counter=0;
                int f=j;
                for(auto control=k+1;control<k+4;control++)
                { if(boardpoint[control][f=f-1]=='x')
                        counter++;
                    if(counter==3)
                        return true; }}}}
    for(int a=0;a<size;a++)
    {int j=size;
        for(int k=0+a;size>k;k++)
        {if (boardpoint[k][j=j-1-a]=='o')
            {int counter=0;
                int f=j;
                for(auto control=k+1;control<k+4;control++)
                {
                    if(boardpoint[control][f=f-1]=='o')
                        counter++;
                    if(counter==3)
                        return true; }}}}return false; }
/*Haritanın sol aşşağıyı çapraz olarak kontrol eder*/
bool leftdowndiagonalcompare(const char boardpoint[][20],const int size)
{ for(int a=0;a<size;a++)
    {int j=-1;
        for(int k=0+a;k<=size;k++)
        {if (boardpoint[k][j=j+1]=='x')
            {int counter=0;
                int f=j;
                for(auto control=k+1;control<k+4;control++)
                { if(boardpoint[control][f=f+1]=='x')
                        counter++;
                    if(counter==3)
                        return true; }}}
    }for(int a=0;a<size;a++)
    {int j=-1;
        for(int k=0+a;k<=size;k++)
        {if (boardpoint[k][j=j+1]=='o')
            {int counter=0;
                int f=j;
                for(auto control=k+1;control<k+4;control++)
                { if(boardpoint[control][f=f+1]=='o')
                        counter++;
                    if(counter==3)
                        return true; }}}}return false; }
/*kullanıcı1 ve 2 nin sıralama algoritmasını veren fonksiyon*/
int user1_vs_user2(int size,char boardpoint[][20],char saveboardpoint[][20], string & letter,char versus,int cpsize,char cpversus)
{for(int temp=0;(size*size)/2>temp;temp++) {
        cout<<"\n";
        user1(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        cout<<"\n";
        if(horizontalcompare(boardpoint,size))
        {   creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0);}
        if(verticalcompare(boardpoint,size))
        {   creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0);}
        if(leftupdiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0);}
        if(rightupdiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0);}
        if(leftdowndiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0); }
        if(rightdowndiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0);}
        creatingboardletter(size);
        cout<<"\n";
        printboard(size,boardpoint);
        cout<<"\n";
        user2(boardpoint,size,letter,saveboardpoint,versus,cpsize,cpversus);
        if(horizontalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0);}
        if(verticalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0);}
        if(rightupdiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0);}
        if(leftupdiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0);}
        if(leftdowndiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0); }
        if(rightdowndiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0);}
        creatingboardletter(size);
        cout<<"\n";
        printboard(size,boardpoint);
        cout<<"\n"; }/*Default Arguments*/won(2); exit (0);}
/*kullanıcı1 ve computerın sıralama algoritması*/
int user1_vs_computer(int size,char boardpoint[][20],char saveboardpoint[][20],string & letter, char versus,int cpsize,char cpversus )
{for (int temp = 0; (size * size)/2 > temp; temp++) {
        cout<<"\n";
        user1(boardpoint, size,letter,saveboardpoint,versus,cpsize,cpversus);
        if(horizontalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0);}
        if(verticalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0);}
        if(rightupdiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0);}
        if(leftupdiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0);}
        if(leftdowndiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0); }
        if(rightdowndiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'x');
            exit (0);}
        cout<<"\n";
        creatingboardletter(size);
        cout<<"\n";
        printboard(size, boardpoint);
        cout<<"\n";
        computer(boardpoint, size,letter);
        if(horizontalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0);}
        if(verticalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0);}
        if(rightupdiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0);}
        if(leftupdiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0);}
        if(leftdowndiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0); }
        if(rightdowndiagonalcompare(boardpoint,size))
        {creatingboardletter(size);
            cout<<"\n";
            printboard(size,boardpoint);
            cout<<"\n";won(1,'o');
            exit (0);}
        cout<<"\n";
        creatingboardletter(size);
        cout<<"\n";
        printboard(size, boardpoint);
        cout<<"\n"; }/*default argument*/won(2);}
/*Oyunun İsteni̇ldi̇ği̇ Yerde Karşilaşmanin, "SAVE" Komutuyla "İsteni̇ldi̇ği̇ İsi̇mde" Kayit Eden Program ÖRNEK:SAVE 171044086 yada SAVE.TXT*/
int Save_txt(char boardpoint[][20],int size,char saveboardpoint[][20],char versus,int cpsize,char cpversus, string  letter)
{
    cout<<"YOUR GAME IS SAVING..."<<endl;
    decltype(letter) fileName="SAVE.TXT";
    fileName=letter;
    cout<<fileName ;
    cpversus=versus;
    cpsize=size;
    SaveData.open(fileName.c_str(),fstream::out);
    SaveData<<cpsize;
    SaveData<<cpversus;
    for(int i=0;i<size;i++)
    {    cout<<"\n";
        for(int j=0;j<size;j++) {
            saveboardpoint[i][j] = boardpoint[i][j];
            SaveData << saveboardpoint[i][j];
        }}SaveData.close();
    creatingboardletter(size);
    cout<<"\n";
    printboard(size,boardpoint);
    cout<<"\n";
if(versus=='P')return user1_vs_user2(size,boardpoint,saveboardpoint,letter,versus,cpsize,cpversus);
    else if(versus=='C')return user1_vs_computer(size,boardpoint,saveboardpoint,letter,versus,cpsize,cpversus);
}
/*KAYIT EDİLEN OYUNU, LOAD KOMUTUYLA OYUNA YAZDIRAN FONKSİYON*/
int Load_txt(char boardpoint[][20],int size,char saveboardpoint[][20],char versus,int  cpsize,char cpversus, string  letter)
{  decltype(letter) fileName="LOAD.TXT";
    fileName=letter;
    LoadData.open(fileName.c_str(),fstream::out);
    if(LoadData.fail())
    {    cerr<<"NO lOADING FILE";
        if(versus=='P')return user1_vs_user2(size,boardpoint,saveboardpoint,letter,versus,cpsize,cpversus);
        else if(versus=='C')return user1_vs_computer(size,boardpoint,saveboardpoint,letter,versus,cpsize,cpversus);}
    cout<<"YOUR GAME IS LOADING..."<<endl;
    LoadData>>cpsize;
    LoadData>>cpversus;
    size=cpsize;
    versus=cpversus;
    for(int i=0;i<size;i++)
    {    cout<<"\n";
        for(int j=0;j<size;j++) {

            LoadData>>saveboardpoint[i][j];
            boardpoint[i][j]=saveboardpoint[i][j];}}
    LoadData.close();
    creatingboardletter(size);
    cout<<"\n";
    printboard(size,boardpoint);
    cout<<"\n";
    if(versus=='P')return user1_vs_user2(size,boardpoint,saveboardpoint,letter,versus,cpsize,cpversus);
    else if(versus=='C')return user1_vs_computer(size,boardpoint,saveboardpoint,letter,versus,cpsize,cpversus);}

