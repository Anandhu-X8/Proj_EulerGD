#include <iostream>
using namespace std;
//literally spagetti code
int main()
{
    unsigned int big = 0, ans = 1;
    bool *aar = new bool[1000001]();
    for (int i = 1; i < 1000001; i++)
    {
        if (aar[i] == false)
        {
            unsigned int N = i;
            int pro = 0;
            while (N != 1)
            {
                if (N % 2 == 0)
                {
                    N /= 2;
                }
                else
                {
                    N = N * 3 + 1;
                }
                if (N <= 1000000)
                {
                    *(aar + N) = true;
                }
                pro++;
            }
            if (pro > big)
            {
                big = pro;
                ans = i;
            }
        }
    }
    delete[] aar;
    cout << ans << '\n';
    return 0;
}