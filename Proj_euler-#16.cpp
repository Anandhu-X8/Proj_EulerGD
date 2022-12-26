#include<iostream>
using namespace std;

unsigned long int final (int arrr[]);
int main()
{
   
    int arry[325]={1};

    for (int  i = 0; i < 100; i++)
    {
        int carry=0;
        for(int j=0;j<325;j++)
        {
            int temp=arry[j]*1024+carry;
            arry[j]=temp%10;
            carry=temp/10;
        }
        
       
    }
    
    

    unsigned long int sum=final(arry);
    cout<<sum<<endl;
    for (int i = 0; i < 325; i++)
    {
        cout<<arry[i]<<"  ";
    }
    
    return 0;
    
    
    
}

unsigned long int final(int arr[])
{
    unsigned long int temp=0;
    for (int i = 0; i < 325; i++)
    {
        temp+=arr[i];
    }
    return temp;
}

