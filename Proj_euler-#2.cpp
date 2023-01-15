#include <iostream>
using namespace std;
unsigned int fibo(int I);
int main()
{
    int i=1;
    unsigned int temp=0;
    unsigned long long int sum=0;
    while (temp<=4000000)
    {
        temp=fibo(i);
        if (temp%2==0)
        {
            sum+=(unsigned long long int)temp;
        }
        
        i++;
    }
    cout<<"answer is "<<sum<<'\n';
    return 0;
}

unsigned int fibo (int i)
{
    if (i==1)
    {
        return 1;   
    }
    else if (i==2)
    {
        return 1;
    }
    else
    {
        return (fibo(i-1)+fibo(i-2));
    }
    
}