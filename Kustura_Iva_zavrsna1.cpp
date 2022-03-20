#include <iostream>
#include <cmath>
#include "biblioteka_vrijeme.cc"
using namespace std;
class ctrokut {
	private: 
	   		float s;
	   		cvrijeme vrijeme;
	public:
		   float a,b,c;
		   static int brojac;
		   int sifra;
		   float povr(){
		   	s=(a+b+c)/2;
		   	if((s*(s-a)*(s-b)*(s-c))<=0)
		   		return -1;
		   	else{
		   float P = sqrt(s*(s-a)*(s-b)*(s-c));
		   return P;
	        }
			}
			void unos(){
				vrijeme.pocetak();
				cout <<"Sifra "; cin >>sifra;
				cout <<"a: " ; cin >>a;
				cout <<"b: " ; cin >>b;
				cout <<"c: " ; cin >>c;
				vrijeme.kraj();
				cout <<"Vrijeme unosa " <<vrijeme.proteklo()/1000 << endl;
			}
			void ispis(){
				cout <<"Sifra " <<sifra<<endl;
				cout <<"a " <<a<<endl;
				cout <<"b " <<b<<endl;
				cout <<"c " <<c<<endl;
				cout <<"Vrijeme unosa " <<vrijeme.proteklo() <<endl;
				cout <<"Povrsina " <<povr()<<endl;
			}		
			
};
int ctrokut::brojac;
int main(){
	int c,i=0,n=0,d=0,s=0;
	ctrokut  *p;
	p=new ctrokut [50];

	do{
		cout << "Izaberite " <<endl;
		cout << "1.Unos podataka o trokutima u polje trokuta " <<endl;
		cout << "2.Ispis podataka o unesenim trokutima "<<endl;
		cout << "3.Statistika " <<endl;
		cout << "4.Prepoznavanje odreðenih vrsta trokuta " <<endl;
		cout << "9.Izlaz iz programa " <<endl;
		cin >>c;
		switch(c){
			case 1: 
					p[i++].unos();
					ctrokut::brojac++;
					break;
			case 2: 
					for(int j=0; j<i; j++)
						 p[j].ispis();
					break;
			case 3:
				cout <<"Ukupan broj korisnikovih unosa je " <<ctrokut::brojac<<"."<<endl;
				d=0,n=0;
				for(int j=0; j<i; j++){
					if(p[j].povr()==-1) n++;
					else {
						d++;
						s+=p[j].povr();
					}
			    }
			    cout <<"Ukupan broj unosa koje cine trokut je " <<d<<endl;
			    cout <<"Ukupan broj unosa koje ne cine trokuta je "<<n<<endl;
			    cout <<"Suma povrsina (vrijedi za unose koji cine trokut) "<<s<<endl;
			    break;
			case 4:
				for(int j=0; j<i; j++){
					if((pow(p[j].a,2)+pow(p[j].b,2)==pow(p[j].c,2)) ||
					(pow(p[j].b,2)+pow(p[j].c,2)==pow(p[j].a,2)) ||
					(pow(p[j].c,2)+pow(p[j].a,2)==pow(p[j].a,2))) p[j].ispis();
		}
				break;
				    
			case 9:
					return 0;
		}


	} while(1);
	
	
	
}
