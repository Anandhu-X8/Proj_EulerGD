#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector <int> shovel(int a,int b) //a^b
{
    vector <int> vect;
    vect.push_back(a);
    for (int i = 2; i <= b; i++)
    {
        int carry=0;
        for (auto iter=vect.begin();iter!=vect.end();iter++)
        {
            carry=(*iter*a)+carry;
            *iter=carry%10;
            carry/=10;
        }
        while (carry!=0)
        {
            vect.push_back(carry%10);
            carry/=10;
        }
        
    }
    return vect;
}

int main()
{
    set<vector<int>> sheet;
     //sstt.insert(vectx);

    for (int a = 2; a <= 100; a++)
    {
        for (int b = 2; b <= 100; b++)
        {
            sheet.insert(shovel(a,b));
        }
        
    }
    cout<<sheet.size()<<'\n'; 
   
return 0;
}