#include <iostream>
#include <vector>
using namespace std;
void shred(vector<short int> &vect, int i)
{
    string str = to_string(i);
    while (str.size() >= 1)
    {
        vect.push_back(str[0] - 48);
        str.erase(0, 1);
    }
}
int main()
{
    vector<short int> vect;
    vect.reserve(1000000);
    int i = 1;
    while (vect.size() < 1000000)
    {
        shred(vect, i);
        i++;
    }
    int mark = 1, finl = 1;
    for (int i = 1; i < 7; i++)
    {

        finl *= vect.at(mark - 1);
        mark *= 10;
    }

    cout << finl << '\n';
}