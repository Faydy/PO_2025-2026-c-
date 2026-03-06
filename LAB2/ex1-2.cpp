#include <cstring>
#include <iostream>

using namespace std;

class Carte {
private:
    char *titlu, *autor;
    int anPublicare;
public:
    // Constructor cu toti parametrii si implicit
    Carte(const char *title = "Atomic Habits", const char *author = "James Clear", int publishYear = 0): anPublicare(publishYear){
        titlu = new char[strlen(title) + 1];
        autor = new char[strlen(author) + 1];
        strcpy(titlu, title);
        strcpy(autor, author);
    }
    // Constructor de copiere (deep copy pentru char*)
    Carte(const Carte &c) {
        titlu = new char[strlen(c.titlu) + 1];
        autor = new char[strlen(c.autor) + 1];
        strcpy(titlu, c.titlu);
        strcpy(autor, c.autor);
        anPublicare = c.anPublicare;
    }
    // Destructor care elibereaza memoria si afiseaza un mesaj
    ~Carte() {
        cout << "Memorie eliberata" << endl;
        delete[] titlu;
        delete[] autor;
        titlu = nullptr;
        autor = nullptr;
    }
    // Operator = cu verificarea auto-atribuirii
    Carte& operator=(const Carte& c) {
        if (this == &c) return *this;
        delete[] titlu;
        titlu = new char[strlen(c.titlu) + 1];
        strcpy(titlu, c.titlu);
        delete[] autor;
        autor = new char[strlen(c.autor) + 1];
        strcpy(autor, c.autor);
        anPublicare = c.anPublicare;
        return *this;
    }
    // Operator <<
    friend ostream& operator<<(ostream &os, const Carte& c);
    // Operator >>
    friend istream& operator>>(istream &is, Carte& c);
};
ostream& operator<<(ostream &os, const Carte& c) {
    os << '"' << c.titlu << '"' << " de " << c.autor << " (" << c.anPublicare << ')' << endl;
    return os;
}
istream& operator>>(istream &is, Carte& c) {
    char buffer1[256], buffer2[256];
    is >> buffer1 >> buffer2 >> c.anPublicare;
    delete[] c.titlu;
    delete[] c.autor;
    c.titlu = new char[strlen(buffer1) + 1];
    strcpy(c.titlu, buffer1);
    c.autor = new char[strlen(buffer2) + 1];
    strcpy(c.autor, buffer2);
    return is;
}

int main() {
    // Creare carti
    Carte carte1("ION", "Liviu Rebreanu", 1920);
    Carte carte2("Morometii", "Marin Preda", 1955);
    Carte carte3("Micul Print", "Antoine de Saint-Exupery", 1943);
    // Citire carti
    cout << carte1 << carte2 << carte3;
    // Creare a 4-a carte citita de la tastatura
    Carte carte4;
    cin >> carte4;
    // Afisare a 4-a carte
    cout << carte4;
    return 0;
}