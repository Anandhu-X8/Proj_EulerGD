#include <iostream>
#include <vector>
using namespace std;
// The computer is not stupid, you are
vector<int> toBits(int N)
{
    vector<int> vect;
    while (N > 0)
    {
        vect.push_back(N % 2);
        N /= 2;
    }
    return vect;
}
bool isPali(vector<int> vec, int first, int last)
{
    if (last > first)
    {
        if (vec.at(first) != vec.at(last))
        {
            return false;
        }
        else
        {
            return isPali(vec, first + 1, last - 1);
        }
    }
    return true;
}
bool isPali(int N)
{
    int temo = N, rev = 0, dig;
    while (N > 0)
    {
        dig = N % 10;
        rev = rev * 10 + dig;
        N /= 10;
    }
    if (temo == rev)
    {
        return true;
    }
    return false;
}
int main()
{
    unsigned int finl = 0;

    for (int i = 1; i < 1000000; i++)
    {
        vector<int> b;
        b = toBits(i);
        if (isPali(b, 0, b.size() - 1))
        {
            // cout<<i<<'\t';
        }

        if (isPali(i))
        {
            vector<int> v;
            v.reserve(1000);
            v = toBits(i);
            if (isPali(v, 0, v.size() - 1))
            {
                cout << i << endl;
                finl += i;
            }
        }
    }
    vector<int> v;
    cout << finl << '\n';
    cout << isPali(911739) << '\n';
    v = toBits(911739);
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }

    cout << endl
         << isPali(v, 0, v.size() - 1) << '\n';
}