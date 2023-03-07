#include <iostream>
using namespace std;
bool isPrime(int N)
{
    if (N<=1) //important step
    {
        return false;
    }
    for (int i = 2; i*i <= N; i++)
    {
        if(N%i==0)
        {
            return false;
        }
    }
    return true;
    
}
int check(int a,int b) //how many loops?
{
    int ann=0,n=0;
    bool flag=true;
    while(flag)
    {
        if(isPrime((n*n) +(a*n) +b))
        {
            n++;
            ann++;
        }
        else
        {
            flag=false;
        }
        
    }
    return ann;

}
int main()
{
    int f_count=0,finl;
    for (int b = -1000; b <= 1000; b++)
    {                                      // actually 4 mill iterations are not bad
        for (int a = -999;  a<1000; a++)
        {
            if(check(a,b)>f_count)
            {
                f_count=check(a,b);
                finl=a*b;
            }
            
        }
        
    }
    cout<<finl<<'\n';
    return 0;
    
}