#include <iostream>
using namespace std;

int pro_divs(int N)
{
    int ans=0;
    for (int i = 1; i <= N / 2; i++)
    {
        if (N % i == 0)
        {
            ans += i;
        }
    }
    return ans;  
}

int main()
{
    int j,final;
    for (int i = 1; i < 10000; i++)
    {
        if ((j=pro_divs(i))>i && j<= 10000)
        {
            if( pro_divs(j)==i)
            {
                final+=(i+j);
            }
        }
    }
    cout<<final<<"\n";
    return 0;
}
//yeah!