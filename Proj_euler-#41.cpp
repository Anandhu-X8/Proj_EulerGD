#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isprime(string s)
{
    unsigned long long int i;
    i=stoi(s);
    if (i%2==0||i%3==0)
    {
        return false;
    }
    for (int j = 5; j*j < i; j++)
    {
        if (i%j==0||i%(j+2)==0)
        {
            return false;
        }
        
    }
    return true;

}
bool ispan(string s)
{
    int siz=s.size();
    string c="0000000000",check="0111111111";
    for (int i = 0; i < siz; i++)
    {
        c[s[i]-48]=49;
    }
   
    if (c.substr(0,siz+1)==check.substr(0,siz+1))
    {
        return true;
    }
    return false;
}
bool all(string aa)
{
    if (ispan(aa))
            {
                if(isprime(aa))
                {
                    return true;
                }
                
            }
            return false;
}
int main()
{
    string finl,aa;
    string mark="1";
    for (int i = 2; i <= 9; i++)
    {
        aa=mark;
        for (int j = 2; j <= i; j++)
        {
            aa.push_back(j+48);
        }
        
       
        do
        {
            if(all(aa))
            {
                finl=aa;
            }
            
            
        } while (next_permutation(aa.begin(),aa.end()));
        
        
    }
    cout<<finl<<endl;
    //cout<<all("2143")<<endl;
    
}