#include <iostream>
using namespace std;
// A little knowledge is a very dangerous thing
bool isPrime(int N)
{
    if (N < 2)
    {
        return false;
    }
    else if (N == 2 || N == 3)
    {
        return true;
    }
    else if (N % 2 == 0 || N % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= N; i += 6)
    {
        if (N % (i + 2) == 0 || N % (i) == 0)
        {
            return false;
        }
    }
    return true;
}
bool isTrunk(int N)
{

    int scoop = 10;
    while (N / scoop >= 1)
    {

        bool fir = isPrime(N % scoop);
        bool sec = isPrime(N / scoop);

        if (!(fir && sec))
        {
            return false;
        }
        scoop *= 10;
    }

    return true;
}

int main()
{
    int finl = 0;
    for (int i = 8; i < 1000000; i++)
    {
        if (isPrime(i))
        {
            if (isTrunk(i))
            {
                finl += i;
            }
        }
    }
    cout << finl << '\n';
}