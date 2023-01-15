#include <iostream>
#include <cmath>
using namespace std;
/* this is a miracle!!
this worked on the first try!!! */

unsigned long long int Reduce(unsigned long long int I );
int PrimeNext(int N);
bool isPrime(int N);
int main()
{
    unsigned long long int num=600851475143;
    cout<<Reduce(num)<<'\n';
    return 0;
}

unsigned long long int Reduce(unsigned long long int Num)
{
    int div=3;
    while (Num/div!=1)
    {
        if (Num%div==0) //div completly divides num
        {
            Num/=div;
        }
        else
        {
            div=PrimeNext(div);
        }
        
    }
    return Num;
}

int PrimeNext(int N)
{
    int Ans=N;
    do
    {
        Ans++;
    } while (!isPrime(Ans));
    return Ans;
}

bool isPrime(int N)
{
    for (int i = 2; i < sqrt(N); i++)
    {
        if (N%i==0)
        {
            return false;break;
        }
        
    }
    return true;
}
