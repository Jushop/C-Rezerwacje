#include <iostream>
#include <string>
#include <fstream>
#include <conio.h> //wybór z klawiatury
#include <sstream>  // int na string;
#include <cstdlib>
#include <ctime> 

 // data

using namespace std;

struct dane {
	string nazwisko;
	string imie;
	string miasto;
	string nrDowodu;
	
};

struct pokoje {
	string ileOsob;
	string rodzaj;
	string wyposazenie;
};


struct rezerwacja {
	int nrKlienta;
	int nrPokoju;
	int day1;
	int day2;
	int mon1;
	int mon2;
	int year1;
	int year2;
	
};


short k;
dane klient[100];
short p;
pokoje pokoj[30];
short r;
rezerwacja rezerwuj[150];


// funkcje 

void MENU();
void ZobaczDane();
void ZobaczPokoje();
void ZobaczHistorie();
void wczytaj();
void dodajKlienta(string);
void dodajpokoj();
bool SprawdzDostep(int, int, int, int, int, int, int);
void Rezerwuje();
void SprawdzJakiPokoj(int, int , int , int , int , int , int );
void SprawdzDowod(int, int , int , int , int , int );
void WprowadzNowaRezerwacje(int , int , int , int , int , int , int , int );
void KtoRezerwowal(int);
void statystyka();
bool PoprawnaData(int, int , int );
void usun();
void zapisRezerwacji();

int main(int argc, char** argv) {
	
	 wczytaj();
	 
	 cout<<endl;
	 cout<<"*******Witamy*******"<<endl<<endl;
	 cout<<"**w**bazie**danych**"<<endl<<endl;
	 
	 
    time_t czas;
    time( & czas );
    printf( "Dzisiaj jest: %s\n", ctime( & czas ) );
    cout<<endl<<endl;
    
	 MENU();

  return 0;
}




  void ZobaczDane() {
  	 if ( k != 0)                             //musi byc conajmniej 1 element do wypisania
  {
    for (short j = 0; j < k; j++)   
    {                               
      cout <<"klient nr"<<" : "<<j+1<<" "<<endl;
      cout<<"Nazwisko i imi\251 :"<<" "<< klient[j].nazwisko<<" "<< klient[j].imie<< " ";
	  cout<<"Miejscowo\230\253 :"<< " " <<klient[j].miasto<<" "<<endl;
	  cout<<"Nr dowodu :"<<" "<<klient[j].nrDowodu<<endl<<endl;
    }
  }
  else
  cout <<"Nie ma \276adnego klienta w bazie!!";

  cout <<"Nacisnij ENTER";

  getchar();
  	
  }
  
 void MENU(){
 
 char wybor;
 	do {
		//system("cls");
		cout<< " 1. Rezerwacja *rezerwuj pok\242j*" << endl;
		cout<< " 2. Wy\230wietl oferty hotelu" <<endl;
		cout<< " 3. Wy\230wietl historie rezerwacji" << endl;
		cout<< " 4. Sprawdz jaki pok\242j jest najcze\230ciej rezerwowany" << endl;
		cout<< " 5. Rozbudowa hotelu - wprowadz nowy pok\242j"<<endl;
        cout<< " 6. Zobacz wszystkie dane klient\242w"<<endl;
		cout<< " 7. Usu\344 rezerwacje"<<endl;
		
		cout<< " ESC. Wyj\230cie" <<endl<<endl;
		
		wybor=getch();
		 
		switch (wybor){
     
         case 49: Rezerwuje();
         break;
         case 50: ZobaczPokoje();
         break;
         case 51: ZobaczHistorie();
         break;
         case 52: statystyka();
         break;
         case 53: dodajpokoj();
         break;
         case 54: ZobaczDane();
         break;
         case 55: usun();
         break;
         default:
         	
         	cout<<endl<<endl<<endl<<"Nieprawid\210owy wyb\242r!!"<<endl<<endl<<endl;
         break;   
         case 27:
         break;
    }

      
  } while ( wybor!= 27);
}
  
  
   void ZobaczHistorie() {
  	 if ( r != 0)                             //musi byc conajmniej 1 element do wypisania
  {
    for (short i = 0; i < r; i++)   //r jest indeksem umozliwiajacym wypisywanie kolejnych elementow.wypisuje od 0 do i
    {  
	cout<<"Rezerwacja nr :"<< i+1<<" ";
	cout<<"Nr Klienta : "<<rezerwuj[i].nrKlienta<<" ";            
    cout<<"Nr pokoju ; "<<rezerwuj[i].nrPokoju<<" ";
	cout<<"Data poczatkowa ; "<<rezerwuj[i].day1<<"."<<rezerwuj[i].mon1<<"."<<rezerwuj[i].year1<<" ";
	cout<<"Data koncowa : "<<rezerwuj[i].day2<<"."<<rezerwuj[i].mon2<<"."<<rezerwuj[i].year2<<endl;
    }
  }
  else{
    cout <<"Nikt nierezerowa³ pokoju !!";
}
     
     int nr;
     cout<<endl<<"Je\230li chcesz zobaczy\206 dane wpisz 'NR KLIENTA'"<<endl<<" Je\230li chcesz wyj\230\206 do menu wci\230nij 0 "<<endl;
     cin>>nr;
     cin.ignore();
     while(nr != 0){
     KtoRezerwowal(nr);
     cin>>nr;
     cin.ignore();
     }
    cout <<"Nacisnij ENTER";
    getchar();
  	
  }
  
  
  
   void ZobaczPokoje() {
  	 if ( p != 0){
        for (short i = 0; i < p; i++)   //p jest indeksem umozliwiajacym wypisywanie kolejnych elementow.wypisuje od 0 do i
        { 
	    cout<<"Pokoj nr : "<< i+1<<endl;
	    cout<<" Ten pok\242j jest "<<pokoj[i].ileOsob<<" osobowy "<<endl;
	    cout<<"Rodzaj pokoju : "<<pokoj[i].rodzaj<<endl;
	    cout<<"Pokoju wyposa\276ony jest w : "<<pokoj[i].wyposazenie<<endl;
       }
    }
     else
      cout <<"Aktualnie trwa remont hotelu !!";
  

     cout <<"Nacisnij ENTER Aby wróciæ do MENU";

     getchar();
  	
  }
  
		
		
void wczytaj(){
	 ifstream plik2("pokoje.txt", ios::in);
  plik2 >> p;
  short j = 0;
  plik2.get();
  do{
  
    getline(plik2, pokoj[p].ileOsob);

	getline(plik2,pokoj[j].rodzaj);

	getline(plik2,pokoj[j].wyposazenie);
	
    j++;
  } while( !plik2.eof() );

  //cout <<"Wczytano dane.";
  
  
  //getchar();
  
  ifstream plik1("dane.txt", ios::in);
  plik1 >> k;
  short i = 0;
  plik1.get();
  do{
  	
    getline(plik1,klient[i].nazwisko);
    
	getline(plik1,klient[i].imie);
	
	getline(plik1,klient[i].miasto);
	
	getline(plik1,klient[i].nrDowodu);
	 i++;
  } while( !plik1.eof() );

  //cout <<"Wczytano dane";
  //getchar();
  
  ifstream plik("rezerwacja.txt", ios::in);
  plik >> r;
  short s = 0;
  do{
  	plik>>rezerwuj[s].nrKlienta;
	plik>>rezerwuj[s].nrPokoju;
    plik>>rezerwuj[s].day1;
	plik>>rezerwuj[s].mon1;
	plik>>rezerwuj[s].year1;
	plik>>rezerwuj[s].day2;
	plik>>rezerwuj[s].mon2;
	plik>>rezerwuj[s].year2;
	
    s++;
  } while( !plik.eof() );

  //cout <<"Wczytano dane.";
  //getchar(); 
	
}


void dodajpokoj(){
	int ilosc;
  cout <<"Podaj iloosobowy jest pok\242j \n"; 
  cin>>ilosc;
  string s;
  stringstream ss;
  ss.clear();
  ss << ilosc;
  s = ss.str();
  cin.ignore();
  cout <<"Podaj rodzaj : \n";
  getline(cin, pokoj[p].rodzaj);
  
  cout <<"Podaj wyposazenie pokoju: \n";
  getline(cin, pokoj[p].wyposazenie);
 
  pokoj[p].ileOsob=s;  
  cin.ignore();

  p++;

     ofstream plik2("pokoje.txt", ios::out | ios::trunc);

     plik2 <<p<<"\n";

  for (short j = 0; j < p; j++)
  {
    plik2<<pokoj[j].ileOsob<<endl;
	plik2<<pokoj[j].rodzaj<<endl;
	plik2<<pokoj[j].wyposazenie<<endl;
    
  }

plik2.close();
  cout <<"Dane zostaly zapisane! :). Wcisnij ENTER";

  getchar();    
}
	
	

	void dodajKlienta(string ND){
      cout <<"Podaj nazwisko \n";       
      getline(cin, klient[k].nazwisko);

      cout <<"Podaj imie : \n";
      getline(cin, klient[k].imie);

      cout <<"Podaj z jakiego jestes miasta: \n";
      getline(cin, klient[k].miasto);
  
      //"Zapisuje nr dowodu ;
      klient[k].nrDowodu=ND;
  

  
  cin.ignore();

  k++;
  
  ofstream plik1("dane.txt", ios::out | ios::trunc);

     plik1 <<k<<"\n";

  for (short j = 0; j < k; j++)
  {
    plik1<<klient[j].nazwisko<<endl;
	plik1<<klient[j].imie<<endl;
	plik1<<klient[j].miasto<<endl;
	plik1<<klient[j].nrDowodu<<endl;
    
  }
plik1.close();
  cout <<"Twoje dane osobowe zosta\210y zapisane!. Wcisnij ENTER! :)";
  getchar();
	
	
}	

void Rezerwuje(){
    int M, M1, D, D1, Y, Y1;               // Data
	int ileO;
	cout<<" Podaj iloosobowy chcesz mie\206 pok\242j : \n";
	cin>>ileO;

	cout<<" Napisz date rozpoczecia noclegu w postaci : DZIEN MIESIAC ROK (np: 6 4 2014)\n"<<endl;
	cin>>D>>M>>Y;
	cout<<" Napisz date zako\344czenia noclegu"<<endl;
	cin>>D1>>M1>>Y1;
	if (PoprawnaData( D,  M, Y)&& PoprawnaData( D1,  M1,  Y1)){
	SprawdzJakiPokoj(ileO, D, M, Y, D1, M1, Y1);
} else {
	cout<<"Nieprawid\210owa data"<<endl;
	Rezerwuje();
}
	
}



void SprawdzJakiPokoj(int ileO, int D, int M, int Y, int D1, int M1, int Y1){
    int dostepne=0;
    int NrP;
    string po;
    stringstream sp;
    sp.clear();
    sp << ileO;
    po = sp.str();
    char wyborII, wyborI;
	for(short i=0; i<=p; i++){
		if(pokoj[i].ileOsob == po){
			
			cout<<"sprawdzam pok\242j nr"<<i+1<< endl;
			if(SprawdzDostep(i+1, D, M, Y, D1, M1, Y1)){
				cout<<"Pokoj nr "<<i+1<<" jest dostepny w tym terminie "<< endl;
				dostepne++;
			}
			else{
				cout<<"pokoj nr:"<<i+1<<"Nie jest dostepny"<< endl;
			}
		}
	}
	if(dostepne != 0){
	cout<<endl<<endl;		
	cout<<"Wci\230nij   1   je\230li zdecydowale\230 si\251 zarezerwowa\206 pok\242j"<< endl;
	cout<<"Wci\230nij   2   je\230li chcesz zako\344czy\206 rezerwacje"<< endl<< endl;
	
	wyborII=getch();
	if(wyborII == 49){
		//cout<<"Wlasnie sprawdzamy czy byles juz naszym klientem \n";
		SprawdzDowod( D,  M, Y,  D1,  M1,  Y1);
	}
	else{
	MENU();
}    //pokoje nie sa do wynajecia
	}
	if(dostepne == 0){
		cout<<endl;
		cout<<"Przepraszamy w danym terminie wybrane pokoje nie sa dostepna"<<endl;
		cout<<"Jesli chcesz ponownie wybrac termin wcisnij  A"<<endl;
		cout<<"Jesli chcesz wr\242cic do menu wcisnij  B"<<endl;
		cin>>wyborI;
		if(wyborI == 65 || wyborI == 97){
			Rezerwuje();
		}
		else {
			MENU();
		}
	}
}

	
bool SprawdzDostep(int NrP, int D, int M, int Y, int D1, int M1, int Y1){ 

	int status=2; 
	if( r!=0){
	short j=0; 
	
	while( (j < r) && (status != 0)){ 
	    if(rezerwuj[j].nrPokoju == NrP ){
		if((Y < rezerwuj[j].year1) && (Y1 < rezerwuj[j].year1)
		|| (Y > rezerwuj[j].year2) && (Y1 > rezerwuj[j].year2)
		|| (Y == rezerwuj[j].year1) && (M < rezerwuj[j].mon1)
		&& (Y1 == rezerwuj[j].year1) && (M1 < rezerwuj[j].mon1)
		|| (Y == rezerwuj[j].year2) && (M > rezerwuj[j].mon2)
		&&(Y1 == rezerwuj[j].year2) && (M1 > rezerwuj[j].mon2)
		|| (Y == rezerwuj[j].year1) && (M == rezerwuj[j].mon1) && (D < rezerwuj[j].day1) 
		&& (Y1 == rezerwuj[j].year1) && (M1 == rezerwuj[j].mon1) && (D1 < rezerwuj[j].day1) 
		|| (Y == rezerwuj[j].year2) && (M == rezerwuj[j].mon2) && (D > rezerwuj[j].day2 )
		&& (Y1 == rezerwuj[j].year2) && (M1 == rezerwuj[j].mon2) && (D1 > rezerwuj[j].day2 ))
		{
			status = 1; 
		} 
		else {
			status = 0;
	}
	}
	j++;
}
} else{
	cout<<"Nie ma nic zarezerwowane"<< endl;
}
//cout<<"status = "<<status;
	if(status != 0){ 
		return true;
}
    else {
    	return false; }
}
	


	

	
	void SprawdzDowod( int D, int M, int Y, int D1, int M1, int Y1){
	int NK;  //nr klienta
	string  ND;    //nr dowodu
	int NP;
	cout<<"Podaj Nr pokoju"<< endl<<endl;
	cin>>NP;
	if( (NP <= p)||(NP>0)){
	cout<<"Podaj sw\242j nr dowodu"<< endl<<endl;
	cin>>ND;                      
	if(k!=0){
		short j=0;
		while((klient[j].nrDowodu != ND) && (j < k)){
          j++;			
		}
		if(j < k){
			cout<<"Jeste\230 w bazie klient\242w tw\242j nr klienta to "<<" "<<j+1<< endl;
			NK=j+1;
			WprowadzNowaRezerwacje(NK, NP, D,  M,  Y,  D1, M1,  Y1);
		}
		else {
			cout<<"Nie ma Ci\251 w bazie. \n Tw\242j nr klienta : "<<" "<<j+1<< endl;
			NK=j+1;
			WprowadzNowaRezerwacje( NK, NP,  D,  M,  Y,  D1,  M1,  Y1);
			dodajKlienta(ND);
			
		}
	}
	else {
		if(k == 0){                                  
			NK=1;
			WprowadzNowaRezerwacje( NK, NP,  D,  M,  Y,  D1,  M1,  Y1);
			dodajKlienta(ND);
		}
	}
	
}
else {
	cout<<"Nie ma takiego pokoju"<<endl;
}
	
	
}
	

 void WprowadzNowaRezerwacje(int NK, int NP, int D, int M, int Y, int D1, int M1, int Y1){
	

    cout<<"Wprowadzono Nr Klienta  \n";
    rezerwuj[r].nrKlienta=NK;
    cout<<"Wprowadzono Nr Pokoju \n";
	rezerwuj[r].nrPokoju=NP;
	cout<<"Wprowadzono daty \n";
	rezerwuj[r].day1=D;
	
	rezerwuj[r].mon1=M;
	
	rezerwuj[r].year1=Y;
	
	rezerwuj[r].day2=D1;
	
    rezerwuj[r].mon2=M1;
    
	rezerwuj[r].year2=Y1;


  cin.ignore();

  r++;
  zapisRezerwacji();
}
void zapisRezerwacji(){
    ofstream plik("rezerwacja.txt", ios::out | ios::trunc);

     plik <<r<<"\n";

  for (short j = 0; j < r; j++)
  {
    	plik<<rezerwuj[j].nrKlienta<<endl;
		plik<<rezerwuj[j].nrPokoju<<endl;
		plik<<rezerwuj[j].day1<<endl;
		plik<<rezerwuj[j].mon1<<endl;
		plik<<rezerwuj[j].year1<<endl;
		plik<<rezerwuj[j].day2<<endl;
		plik<<rezerwuj[j].mon2<<endl;
		plik<<rezerwuj[j].year2<<endl;
    
  }

plik.close();
  cout <<"Dane rezerwacji zosta³y zapisane  :). Wcisnij ENTER";

  getchar();   
   
}
  
  
  void KtoRezerwowal(int NRK){
      if( (NRK <= k) && (NRK > 0)){
		cout<<klient[NRK-1].nazwisko<<" "<<klient[NRK-1].imie<<"  "<<klient[NRK-1].miasto<<" "<<klient[NRK-1].nrDowodu<<endl;
	}
	else {
		cout<<"Wpisa\210e\230 z\210y numer klienta!!!"<<endl;
	}
        		
  }
  
  
  void statystyka(){
  
  int max=0, max2=0;
  int maximum=0;
  int j=1;
  if(p != 0){
  
  while(j <= p){
  	for(int i = 0; i < r; i++){
  		if(rezerwuj[i].nrPokoju == j){
  			max++;
  		}
  		if(rezerwuj[i].nrPokoju == j+1){
  			max2++;
  		}
  	}
  	if((max > max2)&& (max > maximum)){
  		maximum=j;
  	}
  	if((max2 > max)&& (max2 > maximum)) {
  		maximum=j+1;
  	}
  	j=j+2;
  	
  }
  cout<<"Najcze\230ciej rezerwowanym pokojem jest pok\242j nr:"<<"  "<<maximum<<endl;
  cout<<"Pok\242j przeznaczony dla"<<"  "<<pokoj[maximum-1].ileOsob<<"  "<<"go\230ci"<<endl;
  cout<<"Wyposa\276ony jest w:"<<"  "<<pokoj[maximum-1].wyposazenie<<endl;
  cout<<endl<<endl;
  cout<<"Mo\276e i Ty go zarezerwujesz? ;) "<<endl<<endl;
  cout<<"Wci\230nij ENTER"<<endl;
  getchar();
}
else {
	cout<<"\276aden pok\242j nie by\210 rezerwowany"<<endl;
}
}



bool PoprawnaData(int dzien, int miesiac, int rok){
	if((miesiac == 2)&&(dzien >0)&&(dzien <=29)&&(rok % 4 == 0 && rok % 100 != 0 || rok % 400 == 0)){
		return true;
	}
	else{
        if((miesiac == 2)&&(dzien >0)&&(dzien <29)){
		return true;
	    }

	else{
		if((miesiac >= 1 && miesiac <= 12)&& (miesiac % 2 == 0)&&(miesiac != 2)&&(dzien <= 30)&&(dzien>0)){
			return true;
		}
	
	else{
		if((miesiac >= 1 && miesiac <= 12)&& (miesiac % 2 != 0)&&(dzien <= 31)&&(dzien>0)){
			return true;
		}
	
	else{
	return false;
    }
   }
  }
 }

}

    	
 void usun(){
 	
 	short kogo;

  if (r != 0)
  {
    cout <<"Podaj numer rezerwacji kt\242ra chcesz usun\245\206: ";
    cin >>kogo;
    cin.ignore();

    if (kogo > r || kogo < 1)
    cout <<"Operacja nie powiodla sie. Brak rezerwacji o takim numerze";
    else
    {
      for (short k = kogo; k < r; k++)    
      {
         //polega na zastapieniu elementu , elementem nastepnym,  na nastepnie r--
        
        rezerwuj[k-1].nrKlienta = rezerwuj[k].nrKlienta;
	    rezerwuj[k-1].nrPokoju = rezerwuj[k].nrPokoju;
		rezerwuj[k-1].day1 = rezerwuj[k].day1;
		rezerwuj[k-1].mon1 = rezerwuj[k].mon1;
		rezerwuj[k-1].year1 = rezerwuj[k].year1;
		rezerwuj[k-1].day2 = rezerwuj[k].day2;
		rezerwuj[k-1].mon2 = rezerwuj[k].mon2;
		rezerwuj[k-1].year2 = rezerwuj[k].year2;
      }
      r--;

      cout <<"Operacja zakonczyla sie sukcesem! Rezerwacja o numerze "<<kogo<<" zostala usunieta!";
      zapisRezerwacji();
    }

  }
  else
  {
    cout <<"Nie ma rezerwacji!! Wci\230nij ENTER"<<endl;
    getchar();
  }
 } 
 
	
