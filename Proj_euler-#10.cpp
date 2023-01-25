#include <iostream>
using namespace std;
bool IsPrime(int N);

int main()
{
    unsigned long long int sum=0;
    bool ErasS[2000001]={0};
    for (int i = 2; i < 1415; i++)
    {
        if (IsPrime(i))
        {
            int j=2*i;
            while (j<= 2000000)
            {
                ErasS[j]=true;
                j+=i;
            }
            
            
        }
        
    }
    for (int i = 1; i <=2000000; i++)
    {
        if (!ErasS[i])
        {
            sum+=i;
        }
        
    }
    cout<<sum-1<<'\n';//to dis-count one
    //redoing is spoiling the fun
    return 0;
    
}

bool IsPrime(int N)
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