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
    char sex;
public:
    // Constructor fara parametrii
    Parent() {
        nume = new char[strlen("N/A") + 1];
        strcpy(nume, "N/A");

        telefon = new char[strlen("N/A") + 1];
        strcpy(telefon, "N/A");

        copil = nullptr;
        sex = 'M';
    }
    // Constructor cu toti parametrii
    Parent(const char* nume, const char * telefon, Elev* copil, char sex) {
        this -> nume = new char[strlen(nume) + 1];
        strcpy(this -> nume, nume);

        this -> telefon = new char[strlen(telefon) + 1];
        strcpy(this -> telefon, telefon);

        if (copil != nullptr) {
            this -> copil = new Elev(*(copil));
        } else this -> copil = nullptr;

        this -> sex = sex;
    }

    // Constructor cu un trei parametrii
    Parent(const char* nume, const char* telefon, const char sex): copil(nullptr) {
        if (nume != nullptr) {
            this -> nume = new char[strlen(nume) + 1];
            strcpy(this -> nume, nume);
        }
        else this -> nume = nullptr;

        this -> telefon = new char[strlen(telefon) + 1];
        strcpy(this -> telefon, telefon);

        this -> sex = sex;
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

        sex = 'M';
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

        sex = parinte.sex;
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
            sex = parinte.sex;

        }
        return *this;
    }

    // Operator de stream: afisare
    friend ostream& operator<<(ostream& os, const Parent& p) {
        os << "Nume: " << (p.nume != nullptr? p.nume: "N/A") << ", sex: " << p.sex << ", telefon: " << p.telefon
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

        cout << "Sex: ";
        is >> p.sex;
        is.get();

        delete p.copil;
        p.copil = new Elev();
        cout << "Date elev: \n";
        is >> *(p.copil);
        return is;
    }
    // GETTERI
    const char* getNume() const { return nume; }
    const char* getTelefon() const { return telefon; }
    const Elev* getElev() const { return copil; }
    const char getSex() const{ return sex; }

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
    void setSex(const char& sex) {
        this -> sex = sex;
    }

    // Operator de indexare (o sa returneze caracterul cu indexul i din nume)
    char& operator[](int index) {
        if (nume!= nullptr && index >= 0 && index < strlen(nume))
            return nume[index];
        throw out_of_range("EROARE: Indexul este out of range! \n");
    }

    // Operatorul ++
    // Prefixat
    Parent& operator++() {
        if (copil != nullptr) ++(*copil); // creste clasa copilului
        return *this;
    }
    // Postfixat
    Parent operator++(int) {
        Parent copie(*this);
        if (copil != nullptr) ++(*copil);
        return copie;
    }
    // Operatorul --
    // Prefixat
    Parent& operator--() {
        if (copil != nullptr) --(*copil);
        return *this;
    }
    // Postfixat
    Parent operator--(int) {
        Parent copie(*this);
        if (copil != nullptr) --(*copil);
        return copie;
    }
    // Operatorul + (concateneaza numele)
    Parent operator+(const char* sufix) {
        Parent copie(*this);
        char* numeNou = new char[strlen(copie.nume) + strlen(sufix) + 1];
        strcpy(numeNou, copie.nume);
        strcat(numeNou, sufix);
        delete[] copie.nume;
        copie.nume = new char[strlen(numeNou) + 1];
        strcpy(copie.nume, numeNou);
        delete[] numeNou;
        return copie;
    }
    // Operatorul - (sterge copilul)
    Parent operator-(int) const {
        Parent copie(*this);
        delete copie.copil;
        copie.copil = nullptr;
        return copie;
    }
    // Operatorul ==
    bool operator==(const Parent& p) const { return strcmp(nume, p.nume) == 0; }
    bool operator!=(const Parent& p) const { return !(p==*this); }
    // Operatorul < (alfabetic dupa nume)
    bool operator<(const Parent& p) const { return strcmp(nume, p.nume) < 0; }

    ~Parent() {
        delete[] nume;
        delete[] telefon;
        delete copil;
    }
};

#endif //PROIECT_PARENT_H