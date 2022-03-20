// MD5:ML9NOwOeDrGJ0C0axNtl8g==// Verifikator 4.08// Program:zavrsna11// Opis zadatka:zavrsna11// Autor:Iva Kustura// Poèetno vrijeme:21.1.2021. 3:53:46// Završno vrijeme:21.1.2021. 4:59:38// Identifikatori:main,cstudent,mat_br,prez_ime[40],c,*sljedeci,sljedeci,*student,int,unos,*zadnji,*novi,zadnji,ispis,*tekuci,dat,cprijava,sif_prij,predmet[30],rok[20],prijava,dat.open,*,upis,br1,provjera,mat,ispis1,ispisi,b,br3,br3// IP:fe80::1d61:e06e:ce1:19c3%5 ( 2673 )// #:#include <iostream>,#include <cmath>,#include <fstream>,#include <iomanip>,// Uspješnih/neuspješnih prevoðenja:43/9#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>
using namespace std;
class cstudent {
	private:
			cstudent *sljedeci;
	public:
			int mat_br;
			char prez_ime[40];
			cstudent(){
				sljedeci=NULL;
	}
			void unos(){
				cstudent *zadnji, *novi;
				zadnji=this;
				while(zadnji->sljedeci)
					zadnji=zadnji->sljedeci;
				novi=new cstudent;
				zadnji->sljedeci=novi;
				cout <<"Maticni broj "; cin>>novi->mat_br;
				cout <<"Prezime i ime "; cin>>novi->prez_ime;
			}
			void ispis(){
				cstudent *tekuci=this->sljedeci;
				while(tekuci){
					cout <<"Maticni broj " <<tekuci->mat_br<<endl;
					cout <<"Prezime i ime " <<tekuci->prez_ime<<endl;
					tekuci=tekuci->sljedeci;
				}
			}
			int provjera(int mat){
				cstudent *tekuci=this->sljedeci;
				while(tekuci)
				{
					if(tekuci->mat_br==mat) 
							return 1;
					tekuci=tekuci->sljedeci;
				}
				return 0;
			}
			void b();
};
fstream dat;
cstudent *student;
class cprijava{
	public:
		int sif_prij;
		int mat_br;
		char predmet [30];
		char rok [20];
		cprijava(){
			dat.open("prijava.dat", ios::out);
			dat.close(); dat.clear();
		}
		void unos(){
			dat.open("prijava.dat", ios::out | ios::app | ios::binary);
			cout <<"Sifra prijave " ; cin >>sif_prij;
			do{
			cout <<"Maticni broj " ; cin >>mat_br;
			}while(student->provjera(mat_br)==0);
			cout <<"Predmet " ; cin >>predmet; 
			cout <<"Rok "; cin >>rok;
			dat.write((char *)this, sizeof(*this));
			dat.close();
		}
		void ispis(){
			dat.open("prijava.dat", ios::in | ios::binary);
			while(1){
				dat.read((char *)this, sizeof(*this));
				if(dat.eof()) break;
				cout <<"Sifra prijave " <<sif_prij<<endl;
				cout <<"Maticni broj "<<mat_br<<endl;
				cout <<"Predmet " <<predmet<<endl;
				cout <<"Rok "<<rok<<endl;
			}
			dat.close();
		}
		void ispisi(){
			int mat;
			dat.open("prijava.dat", ios::in | ios::binary);
			cout <<"Maticni broj "; cin >>mat;
			while(1){
				dat.read((char *)this, sizeof(*this));
				if(dat.eof()) break;
				if(mat_br==mat){
			 		cout<<"Sifra prijave " <<sif_prij<<endl;
 			 		cout<<"Maticni broj " <<mat_br<<endl;
 			 		cout <<"Predmet "<<predmet<<endl;
 			 		cout <<"Rok "<<rok<<endl;
					}
			}
			dat.close();
		}
};
cprijava prijava;
void cstudent::b(){
	int br3;
	cstudent *tekuci=this->sljedeci;
	while(tekuci){
			cout <<"Maticni broj " <<tekuci->mat_br<<endl;
			cout <<"Prezime i ime " <<tekuci->prez_ime<<endl;
			br3=0;
			dat.open("prijava.dat", ios::in | ios::binary);
			while(1){
				dat.read((char *)&prijava, sizeof(prijava));
				if(dat.eof()) break;
				if(prijava.mat_br==tekuci->mat_br)
					br3++;
			}
			tekuci=tekuci->sljedeci;
			cout <<"Ukupan broj prijava " <<br3 <<endl;
			dat.close();
	
}
}
int main(){
student=new cstudent;
 int c, br1=0, br2=0;
 do{
 			cout <<"Izaberite " <<endl;
			cout <<"1.Upis studenata " <<endl;
			cout <<"2.Ispis svih studenata " <<endl;
			cout <<"3.Upis prijava " <<endl;
			cout <<"4.Ispis svih prijava " <<endl;
			cout <<"5.Ukupan broj studenata i prijava " <<endl;
			cout <<"6.Ispis svih prijava zadanog studenta " <<endl;
			cout <<"7.Popis studenata tako da uz svakog pise broj prijava " <<endl;
			cin >>c;
			switch(c){
										case 1:
															student->unos();
															br1++;
															break;
										case 2:
															student->ispis();
															break;
										case 3: 
															prijava.unos();
															br2++;
															break;
										case 4:
															prijava.ispis();
															break;
										case 5:
															cout <<"Ukupan broj studenata "<<br1<<endl;
															cout <<"Ukupan broj prijava " <<br2<<endl;
															break;
										case 6:
															prijava.ispisi();
															break;
										case 7:
															student->b();
															break;
			}
 }while(1);
}
