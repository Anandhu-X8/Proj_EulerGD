#include <iostream>
#include <vector>
using namespace std;

int repetand(int I);
int main()
{
    int fin=0,k;
    for (int i=1; i<1000; i++)
    {
        if (repetand(i)>fin)
        {
            fin=i;
        }
        
    }
    cout<<fin<<'\n';
    cout<<'\n'<<repetand(11);

return 0;
}

int repetand(int i)
{
    vector <int> vec;
    int divid=1;

    while(divid>0)
    {
        if(divid<i)
        {
            vec.push_back(0);
        }
        while (divid<i)
        {
            divid*=10;
        }
        divid%=i;
        vec.push_back(divid);
        vector <int> :: iterator iter;
        for(iter=vec.begin(); iter<(vec.end()-1);iter++ )
        {
            if(*iter==divid)
            {
                return (vec.end()-iter-1);
            }
        }
    }
    return 0;
    
}