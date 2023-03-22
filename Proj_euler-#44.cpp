#include <iostream>
#include <set>
using namespace std;

// RTFQ
// you retard
int main()
{
    set<int> pent;
    for (int i = 1; i <= 10000; i++)
    {
        pent.insert((i * (3 * i - 1)) / 2);
    }

    int D = 0;

    for (auto it = pent.begin(); it != pent.end(); it++)
    {

        for (auto jt = pent.begin(); jt != it; jt++)
        {

            if ((pent.find(*it + *jt) != pent.end()) && (pent.find(*it - *jt) != pent.end()))
            {
                cout << *it << " " << *jt << endl;
                D = *it - *jt;
                break;
            }
        }
    }
    cout << D << endl;
}