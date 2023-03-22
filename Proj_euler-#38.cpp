#include <iostream>
#include <string>
using namespace std;
bool isStrPan(string str) //  123456789
{
    string mat = "0000000000";
    for (int i = 0, n; i < 9; i++)
    {
        n = (str[i]) - 48;
        mat[n] = 49;
    }

    if (mat == "0111111111")
    {

        cout << "bopp" << endl;
        return true;
    }
    return false;
}
string genString(int N)
{
    string answ, dum = " ";
    int i = 1, num;
    while (answ.size() < 9)
    {
        num = N * i;
        answ.append(to_string(num));
        i++;
    }
    if (answ.size() == 9)
    {

        if (isStrPan(answ))
        {
            return answ;
        }
    }

    return dum;
}
int main()
{
    string finl = " ", temp;
    for (int i = 1; i < 9999; i++)
    {
        temp = genString(i);
        if (temp > finl)
        {
            finl = temp;
        }
    }
    cout << finl << '\n';
}