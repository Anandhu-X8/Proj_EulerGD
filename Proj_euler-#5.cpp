#include <iostream>
using namespace std;
//pretty cool huh
int main()
{
    unsigned int basket=1,final=2;
    for (int i = 1; i < 21; i++)
    {
        while (final%i!=0)
        {
            final+=basket;
        }
        basket=final;
        
    }
    cout<<final<<'\n';
    return 0;
    
}