

#include <iostream>
#include <cmath>
using namespace std;
int NthTrinum(int i);
int Num_odiv(int N);

int main()
{
    int i=1,tem=0;
    while (Num_odiv(tem)<500)
    {
        tem=NthTrinum(i);
        i++;
    }
    cout<<tem<<'\n';
    return 0;
}

int NthTrinum(int q)
{
    int sum=0;
    for (int i = 1; i <=q; i++)
    {
        sum+=i;
    }
    return sum;
}

int Num_odiv(int N)
{
    int ans=0,j=1;
    while (j<=sqrt(N))
    {
        if (N%j==0)
        {
            ans+=2;
        }
        j++;       
    }
    return ans;   
}