#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool allisgood(string s)
{
    int prime[] = {2, 3, 5, 7, 11, 13, 17};
    string sub;
    for (int i = 1; i < 8; i++)
    {
        sub = s.substr(i, 3);
        int subb = stoi(sub);
        if (subb % prime[i - 1] != 0)
        {
            return false;
        }
    }
    return true;
}
int main()
{
    unsigned long long int fin = 0;
    string tok = "0123456789";
    do
    {
        if (allisgood(tok))
        {
            fin += stoul(tok);
        }

    } while (next_permutation(tok.begin(), tok.end()));

    cout << fin << '\n';
}