#include <iostream>
using namespace std;

int fir_free(bool arr[])
{
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == false)
        {
            return i;
        }
    }
    return -1;
}
int inc_dig(int pres,bool arr[])
{
    pres++;
    while (pres<10)
    {
        if (arr[pres]==false)
        {
            return pres;
        }
        pres++;
    }
    return -2;
}
unsigned int fact(int N)
{
    if (N == 1)
    {
        return 1;
    }
    else
    {
        return N * fact(N - 1);
    }
}
int main()
{
    bool arr[10] = {0};
    unsigned int token, pos = 1;
    int digit;
    for (int i = 9; i > 0; i--)
    {
        token = fact(i);
        digit = fir_free(arr);
        while ((pos + token) <= 1000000)
        {
            pos+=token;
            digit=inc_dig(digit,arr);//next free digit
        }
        cout<<digit;
        arr[digit]=true;
    }
    cout<<fir_free(arr);
    return 0;
}

//YESSSS!!!!!