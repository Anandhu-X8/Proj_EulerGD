#include <vector>
#include<set>
#include<iostream>
    //always keep in mind what you are lookig for
using namespace std;
bool isprime(int n)
{
    if(n<2)
    {
        return false;
    }
    if (n==2||n==3)
    {
        return true;
    }
    
    if(n%2==0||n%3==0)
    {
        return false;
    }
    for (int i = 5; i*i <= n; i+=6)
    {
        if(n%i==0||n%(i+2)==0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    unsigned int len=100000;
    vector<bool> array(len,false);
    set<int>prime;
    vector<int>square;
    for (int i = 1; i < len; i++)
    {
        if (isprime(i))
        {
            prime.insert(i);
            array.at(i)=true; //is prime
            
        }
        if (i<10000)
        {
            square.push_back(i*i); //covers upto 10^8
        }
        
        
    }
    
    
    int finl=0;
    for (int i = 5777; i < 5778; i+=2)
    {
        
        if (array[i]==false)
        {
            bool flag=false;
            //cout<<i<<endl;
            int head;
            auto step=square.begin(); //step is squares
            int twosqr=(*step)*2;
                while (twosqr<i)
                {        
                    cout<<" prime: "<<head<<" sqr: (2x) "<<*step<<" i: "<<i<<endl;
                    head=i-twosqr;
                    if(!isprime(head))  //we need to find a case where no such prime exist
                    {
                    flag=true;
                    }
                    else //there is a prime
                    {
                        flag=false; //if we find another pair later on
                        break; //if we find one pair, stop
                    }
                    
                    
                    step++;
                    twosqr=*step*2;
                    
                }
            if (flag==true)
            {
                
                     //the prime
                    
                    finl=i;
                    goto label;
            }
            
            
        }
        
    }
    label:
    cout<<finl<<endl;
    
}