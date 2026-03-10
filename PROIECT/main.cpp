#include <iostream>
#include <cstring>
using namespace std;
// Clasa profesor
class Profesor {
private:
    int varsta;
    float salariu;
    char *nume, *materie, *telefon, *email;
public:
    // Constructor fara parametru
    Profesor() {
        nume = new char[strlen("N/A") + 1];
        strcpy(nume, "N/A");

        materie = new char[strlen("N/A") + 1];
        strcpy(materie, "N/A");

        telefon = new char[strlen("N/A") + 1];
        strcpy(telefon, "N/A");

        email = new char[strlen("N/A") + 1];
        strcpy(email, "N/A");

        varsta = 0;
        salariu = 0;
    }

    // Constructor cu 2 parametrii
    Profesor(const char *nume_profesor, const char *materie_predata) {
        nume = new char[strlen(nume_profesor) + 1];
        strcpy(nume, nume_profesor);
        materie = new char[strlen(materie_predata) + 1];
        strcpy(materie, materie_predata);
        telefon = new char[strlen("N/A") + 1];
        strcpy(telefon, "N/A");
        email = new char[strlen("N/A") + 1];
        strcpy(email, "N/A");
        varsta = 0;
        salariu = 0;
    }

    // Constructor cu toti parametrii
    Profesor(const char *nume_profesor, const char *materie_predata, const int v, const float s, const char *nr_telefon, const char *mail): varsta(v), salariu(s) {
        nume = new char[strlen(nume_profesor) + 1];
        strcpy(nume, nume_profesor);
        materie = new char[strlen(materie_predata) + 1];
        strcpy(materie, materie_predata);
        telefon = new char[strlen(nr_telefon) + 1];
        strcpy(telefon, nr_telefon);
        email = new char[strlen(mail) + 1];
        strcpy(email, mail);
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
    }

    // GETTERI

    // Getter de nume
    const char* getName() const{ return nume; }

    // Getter de materie
    const char* getMaterie() const { return materie; }

    // Getter de varsta
    const int getVarsta() const { return varsta; }

    // Getter de salariu
    const float getSalariu() const { return salariu; }

    // Getter de telefon
    const char* getTelefon() const { return telefon; }

    // Getter de email
    const char* getEmail() const { return email; }

    // Afisare
    void afisare_date() {
        cout << "Nume: " << nume << ", varsta: " << varsta << ", materie: " << materie << ", salariu: " << salariu << ", telefon: " << telefon << ", email: " << email << endl;
    }

    //Destructor
    ~Profesor() {
        delete[] nume;
        delete[] materie;
        delete[] telefon;
        delete[] email;
    }
};

int main() {
    Profesor p("Name", "DADA", 21, 23.2, "0771426949", "andreipopescu@gmail.com");
    Profesor x(p);
    p.afisare_date();
}