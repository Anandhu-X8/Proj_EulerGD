#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <string>
#include <set>
#include <sstream>
using namespace std;

int find_tri_sum(string word)
{
    int sum = 0;
    for (int i = 0; i < word.size(); i++)
    {
        sum += (word.at(i) - 64);
    }
    return sum;
}

int main()
{
    fstream infile;
    infile.open("p042_words.txt");

    vector<string> vect;
    string word;
    while (infile >> quoted(word))
    {
        vect.push_back(word);
    }

    set<int> tri_num;
    for (int i = 1; i < 40; i++)
    {
        tri_num.insert(i * (i + 1) * 0.5);
    }
    int finl = 0;
    for (auto iter = vect.begin(); iter != vect.end(); iter++)
    {
        if (tri_num.find(find_tri_sum(*iter)) != tri_num.end())
        {
            finl++;
        }
    }

    cout << finl << '\n';
}