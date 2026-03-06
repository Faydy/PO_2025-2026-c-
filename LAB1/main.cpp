#include <iostream>
#include <string>
#include <vector>
using namespace std;
void interschimba(int &a, int& b)
{
    int aux = a;
    a = b;
    b = aux;
}
void interschimbaPointer(int *a, int *b)
{
    int *aux = b;
    b = a;
    a = aux;
}

double ariaDisc(const double& r)
{
    const double pi = 3.14159265358979;
    ///r =2;
    return pi * r * r;
}
void afisareVector(const int* V, int n)
{
    for(int i=0; i < n; ++i)
        cout << V[i] << ' ';

}
struct Dreptunghi{
    double latime, inaltime;
    double arie() const{
        return latime * inaltime;
    }
    double perimetru() const{
        return 2 * (latime + inaltime);
    }
    void scaleaza(double factor){
        latime *= factor;
        inaltime *= factor;
    }
    void afiseaza() const{
        cout << "Latimea: " << latime << " Inaltime: " << inaltime << " Arie:" << arie() << " Perimetru: " << perimetru() << '\n';
    }
};

class Student{
private:
    string nume;
    int varsta;
    double nota;
public:
    Student(string nume, int varsta, double nota){
        this -> nume = nume;
        this -> varsta = varsta;
        this->nota  = (nota >= 1.0 && nota <= 10.0)? nota: 1.0;
    }
    string getNume() const {return nume;}
    int getVarsta() const {return varsta;}
    double getNota() const {return nota;}

    void setNota(double nota){
        if(nota >= 1.0 && nota <= 10.0)
            this -> nota = nota;
    }
    void afiseaza() const{
        cout << "Nume: " << nume << " Varsta" << varsta << " Nota: " << nota << '\n';
    }
    bool aTrecut() const{
        return nota >= 5.0;
    }
};

/// Declarare tablou global 5 numere intregi
int tablou[5];
int& element(int i){
    if(i>=0 && i<=4)
        return tablou[i];
    else
        return tablou[0];
}
int main()
{

    int a,b;
    cin >> a >> b;
    int suma = a+b, diferenta = a-b, produs = a*b, cat = a/b;
    cout << suma << ' ' << diferenta << ' ' << produs << ' ' << cat << '\n';
    (b == 0)? cout << (a%b ==0) << boolalpha << ' ' << (a%b ==0) : cout << "Nu se poate imparti \n";


    cin >> a >> b;
    interschimba(a,b);
    cout << a << ' ' << b << '\n';
    int *a1 = &a, *b1 = &b;
    interschimbaPointer(a1,b1);
    cout << a << ' ' << b << '\n';

    const int x = 2;
    ///int*x1 = &x;

    Dreptunghi d1, d2;
    d1.inaltime = 2;
    d1.latime = 3;

    d2.latime = 5;
    d2.inaltime = 7;

    d2.scaleaza(2);
    d1.scaleaza(2);
    d1.afiseaza();
    cout << endl;
    d2.afiseaza();


    Student studenti[3] = {
     Student("Alex", 18, 6.5),
     Student("Andrei", 19, 7.8),
     Student("Ionut", 20, 4.3)
    };
    cout << boolalpha << studenti[0].aTrecut() << ' ' << studenti[1].aTrecut() << ' ' << studenti[2].aTrecut() << '\n';

    /// BONUS

    element(2) = 99;
    for(int i=0; i<5;++i)
        cout << element(i) << ' ';


    return 0;
}
