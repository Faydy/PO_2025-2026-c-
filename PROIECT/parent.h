//
// Created by Samman Fady on 11.03.2026.
//

#ifndef PROIECT_PARENT_H
#define PROIECT_PARENT_H
#include "elev.h"
#include <iostream>
#include <cstring>
class Parent {
private:
    char* nume, *telefon;
    Elev* copil;
public:
    // Constructor fara parametrii
    Parent() {
        nume = new char[strlen("N/A") + 1];
        strcpy(nume, "N/A");

        telefon = new char[strlen("N/A") + 1];
        strcpy(telefon, "N/A");

        copil = nullptr;
    }
    // Constructor cu toti parametrii
    Parent(const char* nume, const char * telefon, Elev* copil) {
        this -> nume = new char[strlen(nume) + 1];
        strcpy(this -> nume, nume);

        this -> telefon = new char[strlen(telefon) + 1];
        strcpy(this -> telefon, telefon);

        if (copil != nullptr) {
            this -> copil = new Elev(*(copil));
        } else this -> copil = nullptr;
    }

    // Constructor cu un parametru
    Parent(const char* nume): copil(nullptr) {
        if (nume != nullptr) {
            this -> nume = new char[strlen(nume) + 1];
            strcpy(this -> nume, nume);
        }
        else this -> nume = nullptr;
        telefon = new char[strlen("N/A") + 1];
        strcpy(telefon, "N/A");
    }

    // Constructor cu 2 parametrii
    Parent(const char* nume, Elev* copil) {
        if (nume != nullptr) {
            this -> nume = new char[strlen(nume) + 1];
            strcpy(this -> nume, nume);
        }
        else this -> nume = nullptr;

        if (copil != nullptr) {
            this -> copil = new Elev(*(copil));
        } else this -> copil = nullptr;

        telefon = new char[strlen("N/A") + 1];
        strcpy(telefon, "N/A");
    }

    //Constructor de copiere
    Parent(const Parent& parinte) {
        nume = new char[strlen(parinte.nume) + 1];
        strcpy(nume, parinte.nume);

        telefon = new char[strlen(parinte.telefon) + 1];
        strcpy(telefon, parinte.telefon);

        if (parinte.copil != nullptr) {
            copil = new Elev(*(parinte.copil));
        } else copil = nullptr;
    }

    // Operator de atribuire supraincarcat
    Parent& operator=(const Parent& parinte) {
        if (this != &parinte)
        {
            if (nume != nullptr)
                delete[] nume;
            nume = new char[strlen(parinte.nume) + 1];
            strcpy(nume, parinte.nume);

            if (telefon != nullptr)
                delete[] telefon;
            telefon = new char[strlen(parinte.telefon) + 1];
            strcpy(telefon, parinte.telefon);

            delete copil;
            if (parinte.copil != nullptr)
                copil = new Elev(*(parinte.copil));
            else
                copil = nullptr;

        }
        return *this;
    }

    // Operator de stream: afisare
    friend ostream& operator<<(ostream& os, const Parent& p) {
        os << "Nume: " << (p.nume != nullptr? p.nume: "N/A") << ", telefon: " << p.telefon
        << ", copil: ";
        if (p.copil != nullptr)
            os << *(p.copil) << '\n';
        else
            os << "N/A" << '\n';
        return os;
    }
    // Operator de stream: citire
    friend istream& operator>>(istream& is, Parent& p) {
        char buffer[256] ;

        cout << "Nume: ";
        is.getline(buffer, 256);
        delete[] p.nume;
        p.nume = new char[strlen(buffer) + 1];
        strcpy(p.nume, buffer);

        cout << "Numar de telefon: ";
        is.getline(buffer, 256);
        delete[] p.telefon;
        p.telefon = new char[strlen(buffer) + 1];
        strcpy(p.telefon, buffer);

        delete p.copil;
        p.copil = new Elev();
        cout << "Date elev: \n";
        is >> *(p.copil);
        return is;
    }
    // GETTERI
    const char* getNume() { return nume; }
    const char* getTelefon() { return telefon; }
    const Elev* getElev() { return copil; }

    // SETTERI
    void setNume(const char* nume) {
        if (this -> nume != nullptr) delete[] this -> nume;
        this -> nume = new char[strlen(nume) + 1];
        strcpy(this -> nume, nume);
    }
    void setTelefon(const char* telefon) {
        if (this -> telefon != nullptr) delete[] this -> telefon;
        this -> telefon = new char[strlen(telefon) + 1];
        strcpy(this -> telefon, telefon);
    }
    void setCopil(const Elev* elev) {
        if (copil != nullptr)
            delete copil;
        copil = new Elev(*(elev));
    }

    // Operator de indexare (o sa returneze caracterul cu indexul i din nume)
    char& operator[](int index) {
        if (index >= 0 && index < strlen(nume))
            return nume[index];
        throw out_of_range("EROARE: Indexul este out of range! \n");
    }


    ~Parent() {
        delete[] nume;
        delete[] telefon;
        delete copil;
    }
};

#endif //PROIECT_PARENT_H