#include <iostream>
using namespace std;
class Vector2D {
private:
    double x,y;
public:
    // Constructor cu parametrii si implicit
    Vector2D(double x = 0.0, double y = 0.0): x(x), y(y) {}
    // Constructor de copiere
    Vector2D(const Vector2D& v): x(v.x), y(v.y) {
    }
    // Operatorul +
    Vector2D operator+(const Vector2D &v) const{
        return Vector2D(x+v.x, y+v.y);
    }
    // Operatorul * pentru un scalar de tip double
    friend Vector2D operator*(const Vector2D& v, double a);
    friend Vector2D operator*(double a, const Vector2D& v);

    // Operator <<
    friend ostream& operator<<(ostream &os, const Vector2D &v) {
        os << '(' << v.x << ", " << v.y << ')' << '\n';
        return os;
    }
    // Operatorul ==
    bool operator==(const Vector2D& v) const {
        return abs(x - v.x) < 1e-9 && abs(y - v.y) < 1e-9;
    }
    // Operatorul !=
    bool operator!=(const Vector2D& v) const {
        return !(*this == v);
    }
};
Vector2D operator*(const Vector2D& v, double a){
    return Vector2D(v.x*a, v.y*a);
}
Vector2D operator*(double a, const Vector2D& v) {
    return v * a;
}
int main() {
    Vector2D x(2.3,4.5);
    cout << x;
    Vector2D x1(x);
    x = x * 2.3;
    cout << x;
    x1 = 2.3 * x1;
    cout << x1;
    return 0;
}