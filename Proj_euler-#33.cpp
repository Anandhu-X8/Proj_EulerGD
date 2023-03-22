#include <iostream>
using namespace std;

// Not at all proud of this code.
/* The only difference b/w a good code and a spagetti is
knowing what you are doing and proper order */
class Fraction
{
private:
    int Num;
    int Den;
    int gcd(int a, int b);

public:
    void print() const
    {
        cout << Num << '/' << Den << '\n';
    };
    Fraction main_dia()
    {
        Fraction f(Num / 10, Den % 10);
        return f;
    };
    Fraction dia_()
    {
        Fraction f(Num % 10, Den / 10);
        return f;
    };
    void normalize();
    friend bool operator==(Fraction &f, Fraction &s);
    Fraction &operator*=(const Fraction &f)
    {
        Num *= f.Num;
        Den *= f.Den;
        return *this;
    };
    Fraction(int a, int b);
    int denn()
    {
        return Den;
    };
    int num1() // 1 in 12
    {
        return Num / 10;
    };
    int num2() // 3 in 23
    {
        return Num % 10;
    };
    int den1() //
    {
        return Den / 10;
    };
    int den2()
    {
        return Den % 10;
    };
};
bool operator==(Fraction &f, Fraction &s)
{
    f.normalize();
    s.normalize();
    if (f.Num == s.Num && f.Den == s.Den)
    {
        return true;
    }
    return false;
}
Fraction::Fraction(int a, int b)
    : Num(a), Den(b)
{
}
void Fraction::normalize()
{
    int gc = gcd(Den, Num);
    Num /= gc;
    Den /= gc;
}
int Fraction::gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    Fraction finl(1, 1), dumm(1, 1);
    for (int i = 11; i < 99; i++) // numerator
    {
        for (int j = i + 1; j < 100; j++) // denominator
        {
            if (i % 10 == 0 || j % 10 == 0)
            {
                continue;
            }
            Fraction f(i, j);
            if (f.num2() == f.den1())
            {

                dumm = f.main_dia();
                f.normalize();
                dumm.normalize();
                if (f == dumm)
                {

                    finl *= dumm;
                }
            }

            if (f.num1() == f.den2())
            {

                dumm = f.dia_();
                f.normalize();
                dumm.normalize();
                if (f == dumm)
                {

                    finl *= dumm;
                }
            }
        }
    }
    finl.normalize();
    cout << finl.denn() << '\n';
}