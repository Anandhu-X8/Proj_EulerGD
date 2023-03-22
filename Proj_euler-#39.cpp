#include <iostream>
using namespace std;
int no_sol(int P)
{
    int sol = 0;

    for (int h = P / 3; h <= P / 2; h++)
    {
        int body = P - h;
        for (int a = body/2; a <= h && a<body; a++)
        {
            int c = body - a;
            if (h*h==a*a+c*c)
            {
                sol++;
            }
            
        }
    }

    return sol;
}
int main()
{
    int finl = 0, d,per;
    for (int p = 10; p <= 1000; p++)
    {
        d = no_sol(p);
        if (finl < d)
        {
            finl = d;
            per=p;
        }
    }
    cout << per << '\n';
    cout <<no_sol(120)<< '\n';
}