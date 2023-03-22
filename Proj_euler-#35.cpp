#include <iostream>
#include <string>
using namespace std;
// RTFQ
bool isPrime(int N)
{
    if (N < 2)
    {
        return false;
    }
    if (N % 2 == 0 || N % 3 == 0)
    {
        return false;
    }

    for (int i = 6; i * i < N; i += 6)
    {
        if (N % (i - 1) == 0 || N % (i + 1) == 0)
        {
            return false;
        }
    }
    return true;
}
bool isCircular(int N)
{
    int NN;
    string stt = to_string(N);

    for (int i = 0; i < stt.size() - 1; i++)
    {
        char cc = stt[0];

        stt.erase(0, 1);

        stt.push_back(cc);

        NN = stoi(stt);

        if (!isPrime(NN))
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int finl = 0;
    for (int i = 1; i < 1000000; i++)
    {
        if (isPrime(i))
        {
            if (isCircular(i))
            {

                finl++;
            }
        }
    }
    cout << finl << '\n';
}