#include <iostream>
#include <set>
#include <string>
using namespace std;
int count(int i,int j)
{
    string stt;
    stt+=(to_string(i)+to_string(j)+to_string(i*j)); //useful function
    return stt.size();
}
void put(set<int> &s, int N) //pass by ref
{
    int pain;

    while (N>0)
    {
        pain=N%10;
        if (pain==0)
        {
            return;
        }
        
        s.insert(pain);
        N/=10;
    }
    
}
bool isPan(int i,int j)
{
    set<int> stt;
    put(stt,i);
    put(stt,j);
    put(stt,i*j);
    if(stt.size()==9)
    {
        return true;
    }
    return false;
}
int main()
{
    set <int>sss;
    unsigned int sum=0;
    cout<<isPan(1,2)<<endl;
    for (int i = 1; i <= 2000; i++)
    {                           //honestly i dont know about these bounds
        //cout<<i<<endl;
        for (int j = 1; j < i && j<999; j++)
        {
            if (isPan(i,j))
            {
                if ((sss.find(i*j)==sss.end())&&count(i,j)==9)
                {
                    cout<<i<<'\t'<<j<<endl;
                    sss.insert(i*j);
                    sum+=(i*j);
                }
                
            }
            
        }
        
    }
    cout<<sum<<'\n';
    cout<<sss.size()<<endl;
    return 0;
}