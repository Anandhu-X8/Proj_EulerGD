// i just spend 2 hours on this shit and still cant fix it :(
// 14 mins later i wrote the above comment,
// wanna know why i failed?
// BECAUSE I FUCKING PASSED THE VECTOR BY VALUE INSTEAD OF REFERENCE
// i have my +2 practical tomorrow and i spend 2 hours on this
#include <iostream>
#include <vector>
using namespace std;
//worst code ever 
//trust on the computational power of cpu
unsigned int sumofdiv(int N)
{
    unsigned int final = 0;
    for (int i = 1; i <= N / 2; i++)
    {
        if (N % i == 0)
        {
            final += i;
        }
    }
    return final;
}
int findnex(vector<int> vec, int pos) // to be used with vec1
{
    for (int i = pos + 1; i < 28124; i++)
    {
        if (vec.at(i) == 1)
        {
            return i;
        }
    }

    return 0;
}
void finder(vector<int> vec1, vector<int> &vec2, int i)
{
    int cup = findnex(vec1, 1), bucket;
    while (cup <= i / 2)
    {

        bucket = i - cup;
        if (vec1.at(bucket) == 1)
        {

            vec2.at(i) = 1;

            return;
        }
        cup = findnex(vec1, cup);
    }
}
int main()
{
    vector<int> vec1(28124, 0);
    vector<int> vec2(28124, 0);
    for (int i = 1; i < 28124; i++)
    {
        if (vec1.at(i) == 0)
        {

            if (sumofdiv(i) == i) // 2nd mult onwards is abund; 4th sum onwards is sumof abund
            {
                vec1.at(i * 2) = 1;
                vec1.at(i * 3) = 1;
                int j = 4;
                while (i * j < 28124)
                {
                    vec1.at(i * j) = 1;
                    vec2.at(i * j) = 1;
                    j++;
                }
            }
            else if (sumofdiv(i) > i)
            {
                vec1.at(i) = 1;
                int j = 2;
                while (i * j < 28124)
                {
                    vec1.at(i * j) = 1;
                    vec2.at(i * j) = 1;
                    j++;
                }
            }
        }
    }

    for (int i = 1; i < 28124; i++) // to solve anomalies
    {
        if (vec2.at(i) == 0)
        {
            finder(vec1, vec2, i);
            // todo
        }
    }
    unsigned int finall = 0;
    for (int i = 0; i < 28124; i++)
    {
        if (vec2.at(i) == 0)
        {
            finall += i;
        }
    }
    cout << finall << '\n';

    return 0;
}