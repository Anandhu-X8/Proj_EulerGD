#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

bool isprime(string num)
{
    int n = stoi(num);
    if (n < 2)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
bool isprime(int n)
{
    if (n < 2)
    {
        return false;
    }
    if (n == 2 || n == 3)
    {
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    string finl;
    for (int i = 1000; i <= 9999; i++)
    {
        if (i == 1487)
        {
            continue;
        }
        if (isprime(i))
        {
            // cout<<i<<endl;
            set<int> combs;
            string snum = to_string(i);
            do
            {
                if (snum[0] == '0')
                {
                    continue;
                }
                else
                {
                    if (isprime(snum))
                    {
                        // cout<<snum<<endl;
                        combs.insert(stoi(snum));
                    }
                }

            } while (next_permutation(snum.begin(), snum.end())); // after this loop all prime perms are in set, sorted

            for (auto it = combs.begin(); it != combs.end(); it++) // it larger than jt
            {
                for (auto jt = combs.begin(); jt != it; jt++)
                { // seq: *jt,<diff>, *it, it+diff
                    int diff = *it - *jt;
                    if (combs.find(*it + diff) != combs.end()) //
                    {

                        finl += (to_string(*jt) + to_string(*it) + to_string(*it + diff));
                        cout << finl << endl;
                        goto label;
                    }
                }
            }
        }
    }

label:;
}