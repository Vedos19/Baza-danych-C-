#include <iostream>
#include <fstream>
using namespace std;

class Osoba{
    string imie;
    string nazwisko;
    int dzien;
    int miesiac;
    int rok;

    public:
    
    Osoba(string im="Konrad", string naz="Rzeplinski", int d=1, int m=9, int r=1999){
        imie=im;
        nazwisko=naz;
        dzien=d;
        miesiac=m;
        rok=r;
    }

    void show(){
        cout<<imie<<" "<<nazwisko<<endl;
        cout<<"Data urodzenia: "<<dzien<<"."<<miesiac<<"."<<rok<<endl;
    }
};

class Student :public Osoba{
    string kierunek;
    int nr_albumu;

    public:
    Student(string im="Jan", string naz="Kowalski", int d=17, int m=2, int r=1999, 
    string k="Informatyka", int n_a=98365) :Osoba(im,naz,d,m,r){
        kierunek=k;
        nr_albumu=n_a;
    }
    void show(){
        Osoba::show();
        cout<<"Kierunek: "<<kierunek<<endl;
        cout<<"nr. albumu: "<<nr_albumu<<endl<<endl;
    }
};

class Wykladowca :public Osoba{
    string wyklada;
    string tytul;

    public:
    Wykladowca(string im="Tadeusz", string naz="Szczypka", int d=23, int m=11, int r=1976, 
    string t="Mgr. Inz. ", string w="Informatyka, Matematyka Dyskretna ") :Osoba(im,naz,d,m,r){
        tytul=t;
        wyklada=w;
    }
    void show(){
        cout<<tytul;
        Osoba::show();
        cout<<"Wyklada: "<<wyklada<<endl<<endl;
    }
};

void UI()
{
    int sw_a;
    string wybor;
    Osoba o1;
    Student s1;
    Wykladowca w1;

    o1.show(); cout<<endl;
    s1.show();
    w1.show();

    do{
        cout<<"Baza danych v0.1"<<endl<<endl; cout<<"Wybierz operacje:"<<endl; cout<<"1. Lista osob"<<endl; cout<<"2. Dodaj osobe"<<endl; cout<<"3. Wypisz liste osob"<<endl; cout<<"4. Wyjscie"<<endl;
        cin>>sw_a; cout<<endl;

        switch(sw_a){
            case 1:{
                o1.show();
            }
            break;

            case 2:{
                cout<<"a2"<<endl;
            }
            break;

            case 3:{
            }
            break;

            //wyjscie
            case 4:{
                cout<<"Zapisac i wyjsc? (T/N)"<<endl;
                cin>>wybor;
                if(wybor=="T")
                    sw_a=4;
            }
            break;

            default:
                cout<<"Blad"<<endl;
        }
        cout<<endl<<endl;
    }
    while(sw_a!=4);
};

int main(){
    fstream plik;
    plik.open("dane.txt", ios::out);
    plik.close();
    UI();
}