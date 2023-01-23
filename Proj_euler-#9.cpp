#include <iostream>
using namespace std;
int main()
{
    for (int i = 4; i < 998; i++)
    {
        int basket=1000-i;
        for (int k = 1; k <= (basket-1)/2; k++)
        {
            int j=basket-k;
            if ((i*i)==(j*j)+(k*k))
            {
                cout<<i*j*k<<'\n';
                cout<<i<<" "<<j<<" "<<k;
                goto label;
            }
            
        }
        
    }
    label:
    return 0;
}