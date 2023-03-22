#include <vector>
#include <iostream>
#include <list>
using namespace std;
list<int> push_div(int i)
{
    list<int> list;
    
    int divis=2;
    int now=1;
    
   while (i>1)
   {
        while (i%divis==0)
        {
            now*=divis;
            i/=divis;
        }
        divis++;
        if(now!=1)
        {
            
            list.push_back(now);
            //cout<<now<<" ";
        }
       
        now=1;
   }
   return list;
    
}
int main()
{
    int len=1000000;
    list<int> check;
 
    vector<list<int> >vect(len,list<int>());
   list<int> origin;
   list<int> first2;
   list<int> last2;
   list<int> ounique;
   
   for (int i = 1; i < 5; i++)
   {
        vect.at(i)=push_div(i);
   }
   int fin=0;
    for (int i = 5; i <= 1000000; i++)
    {
        
        vect.at(i)=push_div(i);
        if (vect.at(i).size()!=4)
        {
            continue;
        }
        else  if(vect.at(i).size()==vect.at(i-3).size())
        {
            if (vect.at(i).size()==vect.at(i-1).size())
            {
                if(vect.at(i-1).size()==vect.at(i-2).size())
                {
                    cout<<"num: "<<i<<endl;
                    vect.at(i-3).merge(vect.at(i-2));
                    vect.at(i-3).merge(vect.at(i-1));
                    vect.at(i-3).merge(vect.at(i));
                    origin=vect.at(i-3);
                    vect.at(i-3).unique();
                    if (origin==vect.at(i-3))
                    {
                        fin=i-3;break;
                    }
                    
                }
            }
            

        }

       

    }
    // for (int i = 4485; i <= 4488; i++)
    // {
    //     vect.at(i)=push_div(i);
    //     for (auto it=vect.at(i).begin();it!=vect.at(i).end();it++)
    //     {
    //         cout<<*it<<" ";
    //     }
    //     cout<<endl;
    // }
    
    cout<<fin<<endl;
    
}