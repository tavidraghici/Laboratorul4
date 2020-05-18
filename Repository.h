#pragma once

#include <vector>
#include "Medikament.h"
using namespace std;

class Repository{
public:
    vector<Medikament> repo;    /// lista de obiecte de tip medicament
                                /// am lasat-o public, ca sa pot folosi mai bine asserturile din Tests.
    Repository();                   /// constructor
    vector <vector<Medikament> > undo_vector;    /// vectorul de undo/redo, care salveaza pe fiecare pozitie vectorul curent de medicamente(repo)
    void einfugen(Medikament m);    /// add
    void bearbeiten(Medikament& m); /// edit
    void loschen(Medikament m);     /// delete
    void anzeigen();                /// print all
    void zeichenkette();            /// suchen nach einer bestimmten zeichenkette
    void knapp();                   /// anzeigen aller medikamente die knapp sind
    void nachpreis();               /// gruppieren nach preis
    void undo();                    /// UNDO
    void redo();                    /// REDO
    vector<Medikament>& getList();
};

