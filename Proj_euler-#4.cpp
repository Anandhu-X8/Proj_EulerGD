#include <iostream>
using namespace std;
/* it is quite often the minute things that fuck things up */
bool IsPalindrome(int N);

int main()
{
    int sum = 0;
    for (int i = 999; i >= 100; i--)
    {
        for (int j = i; j >=100; j--)
        {
            //cout << i <<"\t" << j << '\n';
            if (IsPalindrome(i * j) )
            {
                //cout<<(i*j);
                if (i*j>sum)
                {
                    sum=i*j;
                }
                

                //cout<<sum;
            }
        }
    }
    cout << sum << '\n';
    return 0;
}

bool IsPalindrome(int N)
{
    int rev = 0, digit;
    int copy = N;
    while (N != 0)
    {
        digit = N % 10;
        rev = (rev * 10) + digit;
        N = N / 10;
    }
    if (rev == copy)
    {
        return true;
    }
    else
    {
        return false;
    }
}