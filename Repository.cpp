//#pragma once
#include "Repository.h"
#include <iostream>
#include <vector>
#include "Medikament.h"
#include <algorithm>
using  namespace std;

Repository::Repository() {  /// initializez vectorul de medicamente gol, la fel si pe cel de undo/redo
    this->repo = {} ;
    this->undo_vector = {};
}


void Repository::einfugen(Medikament m) {
    if(repo.empty()){
        /// daca lista e goala, il adaug
        this->repo.push_back(m);
        undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
        cout<<"Successfully"<<endl;
    }
    else
        {
        for(int i= 0;i<this->repo.size(); i++) {
            if(this->repo[i].get_name() == m.get_name() && this->repo[i].get_konz() == m.get_konz()) {
                /// daca medicamentul e deja in repo, ii modific cantitatea
                this->repo[i].set_menge(this->repo[i].get_menge()+ m.get_menge());
                undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
                cout<<"Successfully"<<endl;
                return;
            }
        }
            ///daca nu se afla deja in repo, il adaug
            this->repo.push_back(m);
            undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
            cout<<"Successfully"<<endl;
        }


}


void Repository::loschen(Medikament m) {
    for(int i= 0;i<this->repo.size(); i++) {
            if(this->repo[i].get_name() == m.get_name() && this->repo[i].get_konz() == m.get_konz()){   /// daca il gasesc
            this->repo.erase(this->repo.begin()+i);                                       /// il sterg din lista
            undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
            cout<<"Successfully"<<endl;
            return;
        }
    }
}


void Repository::bearbeiten(Medikament& m) {
    cout<<"1: schimbare nume"<<endl<<"2: schimbare concentratie"<<endl<<"3: schimbare menge"<<endl;
    cout<<"0: exit"<<endl<<"Alegeti o tasta: ";
    int x; cin>>x;
    string n; int k; int menge;
    if(x == 0)
        return;
    while(x !=0 ) {
        if(x == 1) {       /// pt tasta 1 se schimba numele
            cout<<"Nume nou: ";
            cin >> n;
            for(int i= 0;i<this->repo.size(); i++) {
                if(this->repo[i].get_name() == m.get_name() && this->repo[i].get_konz() == m.get_konz()){       /// gasesc medicamentul respectiv in lista
                    this->repo[i].set_name(n);                                                      /// si ii schimb numele
                    m.set_name(n);
                    undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
                    cout<<" Successfully"<<endl;
                }
            }

        }
        else if (x == 2) {      /// pt tasta 2 se schimba concentratia
            cout<<"Concentratie noua: ";
            cin >> k;
            for(int i= 0;i<this->repo.size(); i++) {
                if(this->repo[i].get_name() == m.get_name() && this->repo[i].get_konz() == m.get_konz()){       /// gasesc medicamentul respectiv in lista
                    this->repo[i].set_konz(k);                                                       /// si ii schimb concentratia
                    m.set_konz(k);
                    undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
                    cout<<" Concentratie schimbata"<<endl;

                }
            }
        }
        else if (x == 3) {      /// pt tasta 3 se schimba menge
            cout<<"Cantitate noua: ";
            cin >> menge;
            for(int i= 0;i<this->repo.size(); i++) {
                if(this->repo[i].get_name() == m.get_name() && this->repo[i].get_konz() == m.get_konz()){       /// gasesc medicamentul respectiv in lista
                    this->repo[i].set_menge(menge);                                                  ///si ii schimb valoarea la menge
                    m.set_menge(menge);
                    undo_vector.push_back(this->repo);     /// salvez modificarea in lista de undo/redo
                    cout<<" Cantitate schimbata"<<endl;

                }
            }
        }
        cout<<"1: schimbare nume"<<endl<<"2: schimbare concentratie"<<endl<<"3: schimbare menge"<<endl;
        cout<<"0: exit"<<endl<<"Alegeti o tasta: ";
        cin>>x;
    }

}


void Repository::anzeigen() {
    for(int i= 0;i<this->repo.size(); i++) {
        cout << this->repo[i].get_name() << "   " <<this->repo[i].get_konz()<< '\t' << "Menge: " << this->repo[i].get_menge() << "   Preis: "
             << this->repo[i].get_preis();
        cout << endl;
    }
}


bool dupanume(Medikament i , Medikament j){     /// functie pentru sortarea dupa nume
    return(i.get_name() < j.get_name());
}

bool dupapret(Medikament i , Medikament j){     ///functie pentru sortarea dupa pret
    return(i.get_preis() < j.get_preis());
}

void Repository:: zeichenkette() {          /// se cauta in lista dupa nume
    cout<<"Suchen nach Name: ";
    string n; getline(std::cin,n);
    if(n.empty()){                      /// daca inputul e gol, se afiseaza sortate dupa nume
        sort(this->repo.begin(), this->repo.end(), dupanume);   /// sorteaza dupa nume
        anzeigen();
    } else
        for(int i= 0;i<this->repo.size(); i++) {
            if(this->repo[i].get_name().find(n) != string::npos)        /// daca se gaseste subsirul n in vreun nume
                cout<<this->repo[i].get_name()<<endl;                   /// sa se afiseze numele respectiv
        }
}


void Repository::knapp() {
    cout<<"Anzeigen der Medikamente, die knapp sind"<<endl;
    bool ok = false ;
    int x;
    cout<<"Menge weniger als: ";cin>>x;
    for(int i= 0;i<this->repo.size(); i++) {
        if(this->repo[i].get_menge() < x){
            cout<<this->repo[i].get_name()<<endl;
            ok = true;
        }
    }
    if(!ok) cout<<"Es gibt keine"<<endl;
}


void Repository::nachpreis() {          /// Medikamente gruppiert nach Preis
    sort(this->repo.begin(), this->repo.end(), dupapret);
    anzeigen();
}


void Repository::undo() {
    if(this->undo_vector.empty())
        cout<< "Functia de UNDO nu este posibila"<<endl;
    else{
        this->repo = undo_vector[undo_vector.size() - 2];
        cout<<"UNDO succesful"<<endl;
    }
}


void Repository::redo() {
    if(this->undo_vector.empty())
        cout<< "Functia de REDO nu este posibila"<<endl;
    else
    {
        this->repo = undo_vector[undo_vector.size() - 1];
        cout<<"REDO succesful"<<endl;
    }
}
vector<Medikament>& Repository::getList() {
    return this->repo;
}
