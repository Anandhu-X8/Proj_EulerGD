#include <iostream>
using namespace std;
        //so easyy, cleared on first try itself
int main()
{
    int cup=2,summ=1;
    for (int i = 1; i < 1001*1001; )
    {
        for (int j = 0; j < 4; j++)
        {
            i+=cup;
            summ+=i;
        }
        cup+=2;
    }
    cout<<summ<<'\n';
return 0;
}