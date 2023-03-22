#include <iostream>
#include <set>
using namespace std;
int main()
{
    typedef set<unsigned long long int> iset;
    iset tri, pent, hex;
    int count = 100000;
    for (int n = 1; n <= count; n++)
    {

        tri.insert((static_cast<unsigned long long int>(n) * (static_cast<unsigned long long int>(n) + 1ULL)) / 2ULL);
        pent.insert(((static_cast<unsigned long long int>(n)) * ((3ULL * static_cast<unsigned long long int>(n)) - 1ULL)) / 2ULL);
        hex.insert((static_cast<unsigned long long int>(n)) * ((2ULL * static_cast<unsigned long long int>(n)) - 1ULL));
    }

    auto hiter = hex.find(40755);
    hiter++;
    auto last = tri.rbegin();
    while (*hiter < *last)
    {
        if (pent.find(*hiter) != pent.end())
        {
            if (tri.find(*hiter) != tri.end())
            {
                cout << *hiter << '\n';
                goto label;
            }
        }
        hiter++;
    }
label:

    ;
}