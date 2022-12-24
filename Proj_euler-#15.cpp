/* So, funny story about this one, so i coded the solution on my phone and 
got the right answer but when executed on pc, it shows wrong answer. i even copy-
pasted the exact code. turns out different systems have different sizes for 
same datatypes */

#include <iostream>
using namespace std;
unsigned long long int lattz(int i, int j, unsigned long long int arr[][21]);
int main()
{
    unsigned long long int array[21][21]={0};
    cout<<lattz(20,20,array)<<endl;
    return 0;
}

unsigned long long  int lattz(int i, int j , unsigned long long  int arr[][21])
{
    if (arr[i][j]!=0)
    {
        return arr[i][j];
    }
    else if (i==0||j==0)
    {       
        arr[i][j]=1;
        return arr[i][j];
    }
    else
    {
        arr[i][j]=lattz(i-1,j,arr)+lattz(i,j-1,arr);
        return arr[i][j];
    }
    
    
}