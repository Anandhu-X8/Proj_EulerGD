#include <iostream>
using namespace std;

void IncD(int d,int&S)
    {
        if (d%7==0)
        {
            S++;
        }  
    }
int main()
{
    int days=1,sum=0;//1 denotes that the day is monday
    days+=365;//since the year 1900 has passed(not a leap yr)
    for (int i = 1901; i <= 2000; i++)
    {
        IncD(days,sum);days+=31;//jan
        IncD(days,sum);(i%4==0)?days+=29:days+=28;//feb
        IncD(days,sum);days+=31;//mar
        IncD(days,sum);days+=30;//april
        IncD(days,sum);days+=31;//may
        IncD(days,sum);days+=30;//june
        IncD(days,sum);days+=31;//jul
        IncD(days,sum);days+=31;//aug
        IncD(days,sum);days+=30;//sept
        IncD(days,sum);days+=31;//oct
        IncD(days,sum);days+=30;//nov
        IncD(days,sum);days+=31;//dec
    }
    
    cout<<sum<<'\n';
    return 0;
}