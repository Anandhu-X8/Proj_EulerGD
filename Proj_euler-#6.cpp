#include <iostream>
using namespace std;
int main()
{
    int sum1=0,sum2=0;
    for (int i = 1; i < 101; i++)
    {
        sum1+=(i*i);
    }
    for (int i = 0; i < 101; i++)
    {
        sum2+=i;
    }

    cout<<((sum2*sum2)-sum1)<<'\n';
    return 0;
    
}