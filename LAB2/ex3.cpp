#include <iostream>

using namespace std;
class Contor {
private:
    int valoare;
public:
    // Constructor de parametru si implicit
    Contor(int val = 2 ): valoare(val) {};
    // Constructor de copiere
    Contor(const Contor& alt):valoare(alt.valoare){};
    // Operatorul ++ prefixat
    Contor& operator++() {
        valoare++;
        return *this;
    }
    // Operatorul ++ postfixat
    Contor operator++(int) {
        Contor c(*this);
        ++(*this);
        return c;
    }
    /*
    // Operatorul ==
    bool operator==(const Contor& alt) const{
        return valoare == alt.valoare;
    }
    // Operatorul !=
    bool operator!=(const Contor& alt) const {
        return !(*this == alt);
    }
    // Operatorul <
    bool operator<(const Contor& alt) const {
        return valoare < alt.valoare;
    }
    // Operatorul <=
    bool operator<=(const Contor& alt) const {
        return !(alt < *this);
    }
    // Operatorul >
    bool operator>(const Contor& alt) const {
        return !(*this <= alt);
    }
    // Operatorul >=
    bool operator>=(const Contor& alt) const {
        return !(*this < alt);
    }*/

    // Bonus C++20 -> Inlocuire cei 6 operatori cu <=>
    bool operator==(const Contor&alt) const {
        return valoare == alt.valoare;
    }
    auto operator<=>(const Contor& alt) const {
        return valoare <=> alt.valoare;
    }
    // Getter de valoare
    int getVal() const { return valoare; }
};

int main() {
    Contor c(4);
    int x = (++c).getVal();
    // x o sa ia valoare lui c.valoare + 1, deoarece ++ este prefixat
    int y = (c++).getVal();
    // y o sa ia valoare lui c.valoare, deoarece ++ este postfixat, dupa acest apel c.valoare crescand cu 1
    cout << x << ' ' << y << endl ;
    y++;
    cout << ((x<=>y) < 0 ? "x < y": (x<=>y) > 0 ? "x > y": "x==y");
    return 0;
}