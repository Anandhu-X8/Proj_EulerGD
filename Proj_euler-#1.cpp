#include <iostream>
using namespace std;
int main()
{
    int sum;
    for (int j = 0; j < 1000; j++)
    {
        if (j%3==0||j%5==0)
        {
            sum+=j;
        }
        
    }
    
    cout<<sum<<endl;
    return 0;
}