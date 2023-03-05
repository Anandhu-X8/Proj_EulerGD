#include <iostream>
#include <vector>
using namespace std;

class BigInt
{
private:
    vector <int> vect;
public:
    BigInt(int i);
    BigInt();
    ~BigInt();
    friend BigInt operator+(BigInt A,BigInt B);
    int size()const;
    string toString();
};

BigInt::BigInt(int i)
:vect(vector<int>()) 
{
    vect.reserve(1000);
    vect.push_back(i);
}

BigInt:: BigInt()
:vect(vector<int>())
{
    vect.reserve(1000);
}

string BigInt::toString()
{
    string str;
    for(auto i=vect.rbegin();i!=vect.rend();i++)
    {
        str.push_back(*i+48);
    }
    return str;

}
int BigInt::size()const
{
    return vect.size();
}


BigInt::~BigInt()
{
}
BigInt operator+(BigInt first,BigInt second)
{
    BigInt result;
    int carry=0,num;
    auto iter1=first.vect.begin();
    auto iter2=second.vect.begin();
    while(iter1!=first.vect.end()&&iter2!=second.vect.end())
    {
        num=(*iter1+*iter2+carry);
        result.vect.push_back(num%10);
        carry=num/10;
        iter1++;iter2++;
    }
    while(iter1!=first.vect.end()) //in the case first has more digits
    {
        num=*iter1+carry;
        result.vect.push_back(num%10);
        carry=num/10;
        iter1++;
    }
     while(iter2!=second.vect.end()) //in case second has more digits
    {
        num=*iter2+carry;
        result.vect.push_back(num%10);
        carry=num/10;
        iter2++;
    }
    if (carry==1)
    {
        result.vect.push_back(carry);
    }
    return result;
}
int main()
{
    int i=2;
    BigInt first(1),second(1),third;
    while(third.size()<1000)
    {
        third=first+second;
        first=second;
        second=third;
        i++;
    }
    cout<<i<<endl;
    return 0;

}
