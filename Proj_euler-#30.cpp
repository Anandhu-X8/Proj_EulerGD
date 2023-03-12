#include <iostream>
#include <cmath>
using namespace std;
int sum_5P_digits(int N)
{
    int sum=0,dig;
    while (N>0)
    {
        dig=N%10;
        sum+=(pow(dig,5));
        N/=10;
    }
    return sum;
}
int main()
{
    unsigned int summ=0;
    for (int i = 2; i < 1000000; i++)
    {
        if(i==sum_5P_digits(i))
        {
            summ+=i;
        }
    }
    cout<<summ<<'\n';
return 0;
}