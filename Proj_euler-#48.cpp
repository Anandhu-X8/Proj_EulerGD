#include <vector>
#include <iostream>
using namespace std;
class ten_digits
{
private:
    vector<int> vect;

public:
    void print() const;
    ten_digits(int N);
    ~ten_digits();
    void pow(int);
    ten_digits &operator+=(const ten_digits &right);
};

ten_digits &ten_digits::operator+=(const ten_digits &right)
{
    int carry = 0;
    auto it = vect.begin(); // this needs change
    auto jt = right.vect.begin();
    for (int i = 0; i < 10; i++)
    {
        carry = (*jt + *it) + carry;
        *it = carry % 10;
        carry /= 10;
        it++;
        jt++;
    }
    return *this;
}
void ten_digits::pow(int n)
/*
what this func actually does is: if n=4, mult vector by(4.4.4) so, if vector is 4,
                                        we get 4^4
 */
{

    for (int i = 0; i < n - 1; i++) // mult by n, n times
    {
        int carry = 0;
        for (auto it = vect.begin(); it != vect.end(); it++)
        {
            carry = (*it * n) + carry;
            *it = carry % 10;
            carry /= 10;
        }
    }
}

ten_digits::ten_digits(int N)
    : vect(vector<int>())
{
    for (int i = 0; i < 10; i++)
    {
        vect.push_back(N % 10);
        N /= 10;
    }
}

ten_digits::~ten_digits()
{
}

void ten_digits::print() const
{
    for (auto rt = vect.rbegin(); rt != vect.rend(); rt++)
    {
        cout << *rt;
    }
    cout << endl;
}

int main()
{
    ten_digits finl(0);
    for (int i = 1; i <= 1000; i++)
    {
        ten_digits now(i);
        now.pow(i);
        finl += now;
    }

    finl.print();
}
