#include <iostream>
using namespace std;
unsigned int sum_fact_dig(unsigned long long int N);
// Try not to be stupid
int main()
{
    unsigned int finl = 0;
    for (unsigned long long int i = 3; i < 1000000; i++)
    {
        if (i == sum_fact_dig(i))
        {
            finl += i;
        }
    }
    cout << finl << "\n";
    cout << sum_fact_dig(7000000000) << "\n";
    return 0;
}

unsigned int sum_fact_dig(unsigned long long int N)
{
    unsigned int finl = 0;
    int arr[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    while (N > 0)
    {
        finl += arr[N % 10];
        N /= 10;
    }
    return finl;
}