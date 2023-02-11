#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector <int> vec;
    vector <int>:: iterator iter;
    int carry,j;
    vec.push_back(1);
    for (int i = 1; i <= 100; i++)
    {
       
        
        carry=0;
        for (iter=vec.begin() ; iter < vec.end(); ++iter)
        {
            carry=((*iter)*i)+carry;
            *iter=(carry%10);
            carry/=10;
        }
        while (carry>0)
        {
            vec.push_back(carry%10);
            carry/=10;
        }
        
        
    }
    unsigned int final=0;
    for (iter=vec.begin();iter!=vec.end();++iter)
    {
        final+=*iter;
    }
    cout<<final<<'\n';
    return 0;   
}