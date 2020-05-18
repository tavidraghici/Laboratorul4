#pragma once
#include <string>

class Medikament{
private:
    std::string name;
    int konzentration;
    int menge;
    float preis;

public:
    Medikament(std::string n, int konz,int menge,float preis);    /// constructor
    std::string get_name();
    void set_name(std::string n);
    int get_konz();
    void set_konz(int k);
    int get_menge();
    void set_menge(int m);
    float get_preis();
    void set_preis(float p);


};

