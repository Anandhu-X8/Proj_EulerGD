#include <iostream>
using namespace std;
/* man,dont sweat yourself, take a rest */
bool isprime(int );
int main()
{
    int i=2,j=4;//i-th prime number
    do
    {
        j++; 
        if (isprime(j))
        {
            i++;
        }
    } while (i!=10001);
    cout<<j<<'\n';
    return 0;
}

bool isprime(int N)
{
    for (int i = 2; i <= N/2; i++)
    {
        if (N%i==0)
        {
            return false;
        }
        
    }
    return true;
}