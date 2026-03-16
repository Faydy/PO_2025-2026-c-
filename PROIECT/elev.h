//
// Created by Samman Fady on 11.03.2026.
//

#ifndef PROIECT_Elev_H
#define PROIECT_Elev_H
#include <iostream>
#include <cstring>
using namespace std;
// structura Data (zi, luna, an)
struct Data {
    int zi, luna, an;
    Data(int z=1, int l=1, int a=2026) : zi(z), luna(l), an(a) {}
    bool operator==(const Data& d) const {
        return zi == d.zi && luna == d.luna && an == d.an;
    }
    bool operator!=(const Data&d) {
        return !(*this==d);
    }
    Data& operator=(const Data& d) {
        zi = d.zi;
        luna = d.luna;
        an = d.an;
        return *this;
    }
    // Operator de stream: citire
    friend istream& operator>>(istream& is, Data& d) {
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
    friend ostream& operator<<(ostream& os, const Data& d) {
        os << d.zi << '.' << d.luna << '.' << d.an;
        return os;
    }
};
// structura interval (DataInceput, DataSfarsit)
struct interval {
    Data DataInceput, DataSfarsit;
    interval(): DataInceput(), DataSfarsit() {}
    interval(const Data& start, const Data& end) {
        DataInceput = start;
        DataSfarsit = end;
    }
    // Constructor de copiere
    interval(const interval& i) {
        DataInceput = i.DataInceput;
        DataSfarsit = i.DataSfarsit;
    }
    // Operator de atribuire supraincarcat
    interval &operator=(const interval& d) {
        if (this != &d) {
            DataInceput = d.DataInceput;
            DataSfarsit = d.DataSfarsit;
        }
        return *this;
    }
    Data getDataInceput() const {
        return DataInceput;
    }
    Data getDataSfarsit() const {
        return DataSfarsit;
    }
};
// Clasa Elev
class Elev {
private:
    bool sedintaOnline;
    char *nume = nullptr;
    int clasa;
    interval perioadaAbonament;
    static int numarTotalElevi;
    float *note;
    int numarNote;
public:
    // Constructor fara parametrii
    Elev(): perioadaAbonament(){
        sedintaOnline = false;
        nume = new char[strlen("N/A") + 1];
        strcpy(nume, "N/A");
        clasa = 9;
        numarTotalElevi++;
        note = nullptr;
        numarNote = 0;
    }

    // Constructor cu toti parametrii
    Elev(const bool& online, const char* nume, const int clasa, const interval perioada, const float *note, const int numarNote) {
        sedintaOnline = online;
        this->nume = new char[strlen(nume) + 1];
        strcpy(this->nume, nume);
        this->clasa = clasa;
        perioadaAbonament = perioada;
        numarTotalElevi++;
        this -> numarNote = numarNote;
        if (note != nullptr && numarNote) {
            this -> note = new float[numarNote];
            for (int i = 0; i < numarNote; ++i)
                this -> note[i] = note[i];
        } else {
            this -> note = nullptr;
            this -> numarNote = 0;
        }
    }
    // Constructor cu 4 parametrii
    Elev(const char* nume, const int clasa_, const interval perioada ): clasa(clasa_), perioadaAbonament(perioada){
        sedintaOnline = false;
        this -> nume = new char[strlen(nume) + 1];
        strcpy(this -> nume, nume);
        numarTotalElevi++;
        note = nullptr;
        numarNote = 0;
    }
    // Constructor cu 3 parametrii
    Elev(const int clasa_, const interval perioada ): clasa(clasa_), perioadaAbonament(perioada){
        sedintaOnline = false;
        nume = new char[strlen("N/A") + 1];
        strcpy(nume, "N/A");
        numarTotalElevi++;
        note = nullptr;
        numarNote = 0;
    }
    // Constructor de copiere
    Elev(const Elev& e): sedintaOnline(e.sedintaOnline), clasa(e.clasa), perioadaAbonament(e.perioadaAbonament), numarNote(e.numarNote) {
        nume = new char[strlen(e.nume) + 1];
        strcpy(nume, e.nume);
        numarTotalElevi++;
        if (e.note != nullptr && e.numarNote) {
            note = new float[e.numarNote];
            for (int i = 0; i < e.numarNote; ++i)
                note[i] = e.note[i];
        } else { note = nullptr; numarNote = 0; }
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

        delete [] note;
        numarNote = e.numarNote;
        if (e.note != nullptr && e.numarNote) {
            note = new float[e.numarNote];
            for (int i = 0; i < e.numarNote; ++i)
                note[i] = e.note[i];
        } else { note = nullptr; numarNote = 0; }

        return *this;
    }
    // Calculator de medie
    float getMedie() const {
        if (numarNote == 0) return 0.0f;
        float suma = 0;
        for (int i = 0; i < numarNote; ++i)
            suma += note[i];
        return suma / numarNote;
    }
    // Adaugare nota
    void adaugareNota(float nota) {
        float* temp = new float[numarNote + 1];
        for (int i = 0; i < numarNote; ++i)
            temp[i] = note[i];
        temp[numarNote] = nota;
        delete[] note;
        note = temp;
        numarNote++;
    }
    // Eliminare nota
    void eliminareNota(float nota) {
        float *temp = new float[numarNote];
        int j = 0;
        for (int i = 0; i < numarNote; ++i)
            if (note[i] != nota)
                temp[j++] = note[i];
        delete[] note;
        note = temp;
        numarNote = j;
    }
    // Operator de indexare
    float& operator[](int index) {
        if (index >=0 && index < numarNote)
            return note[index];
        throw out_of_range("Eroare: indexul este out of range! \n");
    }
    // GETTERI
    static int getNumarTotalElevi() { return numarTotalElevi; }
    const char* getNume() const { return nume; }
    const bool getSedintaOnline() const{ return sedintaOnline; }
    const int getClasa() const { return clasa; }
    const interval getPerioadaAbonament() const { return perioadaAbonament; }
    const int getNumarNote() const { return numarNote; }
    const float* getNote() const{
        if (numarNote == 0)
            return nullptr;
        float* copie = new float[numarNote];
        for (int i = 0; i < numarNote; ++i)
            copie[i] = note[i];
        return copie;
    }
    // Setteri
    void setSedintaOnline(bool online) { sedintaOnline = online; }
    void setClasa(int clasa) { this -> clasa = clasa; }
    void setNume(const char* nume) {
        delete[] this -> nume;
        this -> nume = new char[strlen(nume) + 1];
        strcpy(this -> nume, nume);
    }
    void setPerioadaAbonament(const interval& perioada) {
        perioadaAbonament = perioada;
    }
    void setNote(const float* noteNoi, const int numarNote) {
        delete[] note;
        this -> numarNote = numarNote;
        if (noteNoi != nullptr && numarNote != 0) {
            note = new float[numarNote];
            for (int i = 0; i < numarNote; ++i)
                note[i] = noteNoi[i];
        } else {
            note = nullptr;
            this -> numarNote = 0;
        }
    }

    // Operatorul ++
    // Prefixat
    Elev& operator++() {
        clasa++;
        return *this;
    }
    // Postfixat
    Elev operator++(int) {
        Elev copie(*this);
        clasa++;
        return copie;
    }
    // Operatorul --
    // Prefixat
    Elev& operator--() {
        clasa--;
        return *this;
    }
    // Postfixat
    Elev operator--(int) {
        Elev copie(*this);
        clasa--;
        return copie;
    }

    // Operatorul +
    Elev operator +(float nota) const {
        Elev copie(*this);
        copie.adaugareNota(nota);
        return copie;
    }
    friend Elev operator+(float nota, const Elev& e) {
        return e + nota;
    }
    // Operatorul -
    Elev operator-(float nota) const {
        Elev copie(*this);
        copie.eliminareNota(nota);
        return copie;
    }
    // Operatorul ==
    bool operator==(const Elev& e) const {
        return strcmp(nume, e.nume) == 0;
    }
    // Operatorul !=
    bool operator!=(const Elev& e) const {
        return !(e == *this);
    }
    // Operatorul <
    bool operator<(const Elev& e) const {
        return getMedie() < e.getMedie();
    }

    // Operator de stream: afisare
    friend ostream& operator<<(ostream& os, const Elev& e) {
        os << "Nume: " << e.nume << ", Clasa: " << e.clasa << ", Inceput abonament: " << e.perioadaAbonament.DataInceput << ", Sfarsit abonament: " << e.perioadaAbonament.DataSfarsit << '\n';
        if (e.numarNote) {
            os << ", Note: ";
            for (int i = 0; i < e.numarNote; ++i)
                os << e.note[i] << ' ';
            os << '\n';
        }
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
        Data i, s;
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
        delete[] note;
        numarTotalElevi--;
    }
};

inline int Elev::numarTotalElevi = 0;
#endif //PROIECT_Elev_H