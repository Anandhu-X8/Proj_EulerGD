#include <vector>
#include <iostream>
using namespace std;

// all problems are simple, dont make it look hard
// the worst thing you can do is underestimate the question and jump into coding
// the fuck you gonna code if you dont know what you are doing?

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

int find_vsum(vector<int> &vect, int &pos, int &len)
{ // casually overlooking an outofrange error
    int fpos = pos;
    int finl = 0;
    for (int i = 0; i < len; i++)
    {
        finl += vect[fpos];
        fpos++;
    }
    return finl;
}

int main()
{
    vector<int> primes;
    primes.reserve(100000);
    for (int i = 0; i < 100000; i++)
    {
        if (isprime(i))
        {
            primes.push_back(i);
        }
    }
    int temp_sum = 0;
    int j = 0;
    while (temp_sum < 1000000)
    {
        temp_sum += primes[j];
        j++;
    }

    // todo sum of first lstvec primes in < mill
    j--;
    ; // first lasvc primes is just under a mill
      // and no longer chain exists(hopefully)

    for (int last_vec = j; last_vec > 0; last_vec--) // all possible length of chains
    {
        for (int begin = 0; begin <= j - last_vec; begin++) // all chains of given length
        {
            temp_sum = find_vsum(primes, begin, last_vec);
            if (isprime(temp_sum))
            {
                goto label;
            }
        }
    }

    label:

    cout << temp_sum << '\n';
}