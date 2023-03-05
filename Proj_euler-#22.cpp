#include <iostream> //todo
#include <string>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;



int main()
{
    vector<string> mmm;
    string *stp, temp;
    stp = new string;
    int i = 0;
    ifstream infile("p022_names.txt");

    if (infile.is_open())
    {
        cout << "good\n";
    }

    while (infile >> temp)
    {
        mmm.push_back(temp);
    }

    sort(mmm.begin(),mmm.end());
   unsigned long long int fin=0;
 
    for (int i = 0; i < mmm.size(); i++)
    {
        temp=mmm.at(i);
        int k=0;
        for (int j = 0; j < temp.size(); j++)
        {
            k+=((temp.at(j))-64);
        }
       
        fin+=(k*(i+1));
    }

    cout<<fin<<'\n';
    return 0;
}