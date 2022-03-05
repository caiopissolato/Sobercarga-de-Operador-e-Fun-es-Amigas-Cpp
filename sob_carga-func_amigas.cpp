#include <iostream>

using namespace std;

class Fraction{
    private:
        int num;
        int den;

    public:
        Fraction() : num(0), den(1){};
        Fraction(int n, int d){
            if(d == 0){
                num = 0;
                den = 1;
            } else {
                num = n;
                den = d;
            }
        }

        friend Fraction operator+(const Fraction &f1, const Fraction &f2);
        friend Fraction operator-(const Fraction &f1, const Fraction &f2);
        friend Fraction operator*(const Fraction &f1, const Fraction &f2);
        friend Fraction operator/(const Fraction &f1, const Fraction &f2);
        friend ostream &operator<<(ostream &os, const Fraction &f);
        friend istream &operator>>(istream &is, Fraction &f);
};

Fraction operator+(const Fraction &f1, const Fraction &f2){
    Fraction f0;
    if(f1.den == f2.den){
        f0.num = f1.num + f2.num;
        f0.den = f1.den;
    }else{
        f0.num = ((f1.num * f2.den) + (f2.num * f1.den));
        f0.den = f1.den * f2.den;
    }
    return f0;
}

Fraction operator-(const Fraction &f1, const Fraction &f2){
    Fraction f0;
   if(f1.den == f2.den){
        f0.num = f1.num - f2.num;
        f0.den = f1.den;
    }else{
        f0.num = ((f1.num * f2.den) - (f2.num * f1.den));
        f0.den = f1.den * f2.den;
    }

    return f0;
}

Fraction operator*(const Fraction &f1, const Fraction &f2){
    Fraction f0;
    f0.num = f1.num * f2.num;
    f0.den = f1.den * f2.den;
    
    return f0;
}

Fraction operator/(const Fraction &f1, const Fraction &f2){
    Fraction f0;
    f0.num = f1.num * f2.den;
    f0.den = f1.den * f2.num;

    return f0;
}

ostream &operator<<(ostream &os, const Fraction &f){
    os << f.num << "/" << f.den;
    return os;
}

istream &operator>>(istream &is, Fraction &f){
    is >> f.num >> f.den;
    if(!is){
        f = Fraction();
    }
    return is;
}

int main(){
    Fraction a(17, 26);
    Fraction b(11, 27);
    Fraction c, d, e, f;

    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;

    cout << endl << "Fraction a: " << endl;
    cout << a << endl;
    cout << "Fraction b: " << endl;
    cout << b << endl;
    cout << "Fraction c: " << endl;
    cout << c << endl;
    cout << "Fraction d: " << endl;
    cout << d << endl;
    cout << "Fraction e: " << endl;
    cout << e << endl;
    cout << "Fraction f: " << endl;
    cout << f << endl;

    cout << endl << "Resultados:" << endl;
    cout << a + b << endl;
    cout << c - d << endl;
    cout << e * f << endl;
    cout << e / f << endl;
}