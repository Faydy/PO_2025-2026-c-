//
// Created by Samman Fady on 11.03.2026.
//

#ifndef PROIECT_Elev_H
#define PROIECT_Elev_H
#include <iostream>
#include <cstring>
using namespace std;
// structura data (zi, luna, an)
struct data {
    int zi, luna, an;
    data(int z=1, int l=1, int a=2026) : zi(z), luna(l), an(a) {}
    bool operator==(const data& d) const {
        return zi == d.zi && luna == d.luna && an == d.an;
    }
    bool operator!=(const data&d) {
        return !(*this==d);
    }
    data& operator=(const data& d) {
        zi = d.zi;
        luna = d.luna;
        an = d.an;
        return *this;
    }
    // Operator de stream: citire
    friend istream& operator>>(istream& is, data& d) {
        cout << "Zi: ";
        is >> d.zi;
        if (d.zi > 31)
            d.zi = 0;
        cout << "Luna: ";
        is >> d.luna;
        if (d.luna > 12)
            d.luna = 0;
        cout << "An: ";
        is >> d.an;
        return is;
    }
    // Operator de stream: afisare
    friend ostream& operator<<(ostream& os, const data& d) {
        os << d.zi << '.' << d.luna << '.' << d.an;
        return os;
    }
};
// structura interval (dataInceput, dataSfarsit)
struct interval {
    data dataInceput, dataSfarsit;
    interval(): dataInceput(), dataSfarsit() {}
    interval(const data& start, const data& end) {
        dataInceput = start;
        dataSfarsit = end;
    }
    // Constructor de copiere
    interval(const interval& i) {
        dataInceput = i.dataInceput;
        dataSfarsit = i.dataSfarsit;
    }
    // Operator de atribuire supraincarcat
    interval &operator=(const interval& d) {
        if (this != &d) {
            dataInceput = d.dataInceput;
            dataSfarsit = d.dataSfarsit;
        }
        return *this;
    }
    data getDataInceput() {
        return dataInceput;
    }
    data getDataSfarsit() {
        return dataSfarsit;
    }
};
// Clasa Elev
class Elev {
private:
    bool sedintaOnline;
    char *nume = nullptr;
    int clasa;
    interval perioadaAbonament;
public:
    // Constructor fara parametrii
    Elev(): perioadaAbonament(){
        sedintaOnline = false;
        nume = new char[strlen("N/A") + 1];
        strcpy(nume, "N/A");
        clasa = 9;
    }

    // Constructor cu toti parametrii
    Elev(const bool& online, const char* nume, const int clasa, const interval perioada) {
        sedintaOnline = online;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->clasa = clasa;
        perioadaAbonament = perioada;
    }
    // Constructor cu 4 parametrii
    Elev(const char* nume, const int clasa_, const interval perioada ): clasa(clasa_), perioadaAbonament(perioada){
        sedintaOnline = false;
        this -> nume = new char[strlen(nume) + 1];
        strcpy(this -> nume, nume);
    }
    // Constructor cu 3 parametrii
    Elev(const int clasa_, const interval perioada ): clasa(clasa_), perioadaAbonament(perioada){
        sedintaOnline = false;
        nume = new char[strlen("N/A") + 1];
        strcpy(nume, "N/A");
    }
    // Constructor de copiere
    Elev(const Elev& e): sedintaOnline(e.sedintaOnline), clasa(e.clasa), perioadaAbonament(e.perioadaAbonament) {
        nume = new char[strlen(e.nume) + 1];
        strcpy(nume, e.nume);
    }
    // Operator de atribuire supraincarcat =
    Elev& operator=(const Elev& e) {
        if (this == &e)
            return *this;
        sedintaOnline = e.sedintaOnline;
        if (nume != nullptr)
            delete[] nume;
        nume = new char[strlen(e.nume) + 1];
        strcpy(nume, e.nume);
        clasa = e.clasa;
        perioadaAbonament = e.perioadaAbonament;
        return *this;
    }
    // Operator de stream: afisare
    friend ostream& operator<<(ostream& os, const Elev& e) {
        interval x = e.perioadaAbonament;
        os << "Nume: " << e.nume << ", Clasa: " << e.clasa << ", Inceput abonament: " << x.getDataInceput() << ", Sfarsit abonament: " << x.getDataSfarsit() << '\n';
        return os;
    }
    // Operator de stream: citire
    friend istream& operator>>(istream& is, Elev& e) {
        char buffer[256];

        cout << "Nume: ";
        is.getline(buffer, 256);
        delete[] e.nume;
        e.nume = new char[strlen(buffer) + 1];
        strcpy(e.nume, buffer);

        cout << "Clasa: ";
        is >> e.clasa;
        data i, s;
        cout << "Inceput abonament: \n";
        is >> i;
        cout << "Sfarsit abonament: \n";
        is >> s;
        is.get();
        e.perioadaAbonament = interval(i, s);
        return is;
    }
    // Destructor
    ~Elev() {
        delete[] nume;
    }
};


#endif //PROIECT_Elev_H