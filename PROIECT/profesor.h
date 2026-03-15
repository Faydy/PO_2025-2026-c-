//
// Created by Samman Fady
//

#ifndef PROIECT_PROFESOR_H
#define PROIECT_PROFESOR_H
#include <iostream>
#include <cstring>
#include "elev.h"
using namespace std;

class Profesor {
private:
    int varsta;
    float salariu;
    char *nume, *materie, *telefon, *email;
    Elev *elevi;
    int numarElevi;
public:
    // Constructor fara parametru
    Profesor() : varsta(0), salariu(0), numarElevi(0) {
        nume = new char[strlen("N/A") + 1];
        strcpy(nume, "N/A");

        materie = new char[strlen("N/A") + 1];
        strcpy(materie, "N/A");

        telefon = new char[strlen("N/A") + 1];
        strcpy(telefon, "N/A");

        email = new char[strlen("N/A") + 1];
        strcpy(email, "N/A");

        elevi = nullptr;
    }

    // Constructor cu 2 parametrii
    Profesor(const char *nume_profesor, const char *materie_predata): salariu(0), varsta(0), numarElevi(0) {
        nume = new char[strlen(nume_profesor) + 1];
        strcpy(nume, nume_profesor);
        materie = new char[strlen(materie_predata) + 1];
        strcpy(materie, materie_predata);
        telefon = new char[strlen("N/A") + 1];
        strcpy(telefon, "N/A");
        email = new char[strlen("N/A") + 1];
        strcpy(email, "N/A");
        elevi = nullptr;
    }
    // Constructor cu 3 parametrii
    Profesor(const char *nume_profesor, const char *materie_predata, const float salariu_profesor): salariu(salariu_profesor), varsta(0), numarElevi(0) {
        nume = new char[strlen(nume_profesor) + 1];
        strcpy(nume, nume_profesor);
        materie = new char[strlen(materie_predata) + 1];
        strcpy(materie, materie_predata);
        telefon = new char[strlen("N/A") + 1];
        strcpy(telefon, "N/A");
        email = new char[strlen("N/A") + 1];
        strcpy(email, "N/A");
        elevi = nullptr;
    }

    // Constructor cu toti parametrii
    Profesor(const char *nume_profesor, const char *materie_predata, const int v, const float s, const char *nr_telefon, const char *mail): varsta(v), salariu(s), numarElevi(0){
        nume = new char[strlen(nume_profesor) + 1];
        strcpy(nume, nume_profesor);
        materie = new char[strlen(materie_predata) + 1];
        strcpy(materie, materie_predata);
        telefon = new char[strlen(nr_telefon) + 1];
        strcpy(telefon, nr_telefon);
        email = new char[strlen(mail) + 1];
        strcpy(email, mail);
        elevi = nullptr;
    }

    // Constructor de copiere
    Profesor(const Profesor &p) {
        nume = new char[strlen(p.nume) + 1];
        strcpy(nume, p.nume);
        materie = new char[strlen(p.materie) + 1];
        strcpy(materie, p.materie);
        telefon = new char[strlen(p.telefon) + 1];
        strcpy(telefon, p.telefon);
        email = new char[strlen(p.email) + 1];
        strcpy(email, p.email);
        varsta = p.varsta;
        salariu = p.salariu;
        if (p.numarElevi > 0) {
            numarElevi = p.numarElevi;
            elevi = new Elev[numarElevi];
            for (int i=0; i< numarElevi; ++i)
                elevi[i] = p.elevi[i];
        } else { numarElevi = 0; elevi = nullptr; }
    }

    // GETTERI

    // Getter de nume
    const char* getNume() const{ return nume; }
    // Getter de materie
    const char* getMaterie() const { return materie; }
    // Getter de varsta
    int getVarsta() const { return varsta; }
    // Getter de salariu
    float getSalariu() const { return salariu; }
    // Getter de telefon
    const char* getTelefon() const { return telefon; }
    // Getter de email
    const char* getEmail() const { return email; }

    // SETTERI

    // Setter de nume
    void setNume(const char* nume) {
        if (this->nume != nullptr)
            delete[] this->nume;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
    }
    // Setter de materie
    void setMaterie(const char* materie) {
        if (this->materie != nullptr)
            delete[] this->materie;
        this->materie = new char[strlen(materie) + 1];
        strcpy(this->materie, materie);
    }
    // Setter de varsta
    void setVarsta(const int varsta) { this->varsta = varsta; }
    // Setter de salariu
    void setSalariu(const float salariu) { this->salariu = salariu; }
    // Setter de telefon
    void setTelefon(const char* nr_telefon) {
        if (telefon != nullptr)
            delete[] telefon;
        telefon = new char[strlen(nr_telefon) + 1];
        strcpy(telefon, nr_telefon);
    }
    // Setter de mail
    void setEmail(const char* mail) {
        if (email != nullptr)
            delete[] email;
        email = new char[strlen(mail) + 1];
        strcpy(email, mail);
    }
    // Functie de adaugare elev
    void adaugareElev(const Elev& e) {
        numarElevi++;
        Elev* temp = new Elev[numarElevi];
        for (int i = 0; i < numarElevi - 1; ++i)
            temp[i] = elevi[i];
        temp[numarElevi - 1] = e;
        delete[] elevi;
        elevi = temp;
    }
    // Operator de atribuire supraincarcat
    Profesor& operator=(const Profesor& p) {
        // verificare daca sunt la fel
        if (this == &p)
            return *this;
        // eliberare memorie
        delete[] nume;
        delete[] materie;
        delete[] telefon;
        delete[] email;
        delete[] elevi;

        nume = new char[strlen(p.nume) + 1];
        strcpy(nume, p.nume);

        materie = new char[strlen(p.materie) + 1];
        strcpy(materie, p.materie);

        telefon = new char[strlen(p.telefon) + 1];
        strcpy(telefon, p.telefon);

        email = new char[strlen(p.email) + 1];
        strcpy(email, p.email);

        if (p.numarElevi > 0) {
            numarElevi = p.numarElevi;
            elevi = new Elev[numarElevi];
            for (int i=0; i < numarElevi; ++i)
                elevi[i] = p.elevi[i];
        } else { numarElevi = 0; elevi = nullptr; }


        varsta = p.varsta;
        salariu = p.salariu;
        return *this;
    }
    // Operator de stream afisare
    friend ostream& operator<<(ostream& os, const Profesor& p) {
        os << "Nume: " << p.nume << ", varsta: " << p.varsta << " ani, materie: " << p.materie << ", salariu: " << p.salariu << " lei, telefon: " << p.telefon << ", email: " << p.email << '\n';
        if (p.numarElevi) {
            os << "Elevi coordonati: \n";
            for (int i = 0; i < p.numarElevi; ++i)
                os << '-' << p.elevi[i];
        } else os << "Nu are elevi coordonati \n";
        return os;
    }
    // Operator de stream intrare
    friend istream& operator>>(istream& is, Profesor& p) {
        char buffer[256];
        cout << "Nume: ";
        is.getline(buffer, 256);
        delete[] p.nume;
        p.nume = new char[strlen(buffer) + 1];
        strcpy(p.nume, buffer);

        cout << "Varsta: ";
        is >> p.varsta;

        cout << "Materie: ";
        is.get();
        is.getline(buffer, 256);
        delete[] p.materie;
        p.materie = new char[strlen(buffer) + 1];
        strcpy(p.materie, buffer);

        cout << "Salariu(in lei): ";
        is >> p.salariu;

        cout << "Telefon: ";
        is.get();
        is.getline(buffer, 256);
        delete[] p.telefon;
        p.telefon = new char[strlen(buffer) + 1];
        strcpy(p.telefon, buffer);

        cout << "Mail: ";
        is.getline(buffer, 256);
        delete[] p.email;
        p.email = new char[strlen(buffer) + 1];
        strcpy(p.email, buffer);

        return is;
    }
    // Operatorul de indexare
    Elev& operator[](int index) {
        if (index >= 0 && index < numarElevi)
            return elevi[index];
        throw out_of_range("EROARE: Indexul este out of range! \n");
    }
    // OPERATORII ++ si -- : modificari salariale cu o sedinta
    // Prefixat ++
    Profesor& operator++() {
        salariu += 100;
        return *this;
    }
    // Postfixat ++
    Profesor operator++(int) {
        Profesor copie(*this);
        salariu += 100;
        return copie;
    }
    // Prefixat --
    Profesor& operator--() {
        salariu -= 100;
        return *this;
    }
    // Postfixat --
    Profesor operator--(int) {
        Profesor copie(*this);
        salariu -= 100;
        return copie;
    }
    // OPERATORUL + SI -
    // Operatorul +
    friend Profesor operator+(const Profesor& x, float adaosSalariu) {
        Profesor copie = Profesor(x);
        copie.salariu += adaosSalariu;
        return copie;
    }
    friend Profesor operator+(float adaosSalariu, const Profesor& x) {
        return (x + adaosSalariu);
    }
    // Operatorul -
    friend Profesor operator-(const Profesor& x, float adaosSalariu) {
        return (x + (-adaosSalariu));
    }
    friend Profesor operator-(float adaosSalariu, const Profesor& x) {
        return (x - adaosSalariu);
    }
    // Operatorul ==
    bool operator==(const Profesor& x) const {
        return (strcmp(x.nume, nume) == 0);
    }
    // Operatorul !=
    bool operator!=(const Profesor& x) const {
        return !(*this == x);
    }
    // Operatorul <
    bool operator<(const Profesor& x) const {
        return salariu < x.salariu;
    }
    // Destructor
    ~Profesor() {
        delete[] nume;
        delete[] materie;
        delete[] telefon;
        delete[] email;
        delete [] elevi;
    }
};

#endif //PROIECT_PROFESOR_H