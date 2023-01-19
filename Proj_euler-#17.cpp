#include <iostream>
using namespace std;

int LetterCount(int N);
int CountSum();

/* takeaway: always check miniute details you added in your code;
never take it for granted since they can be something wrong
turns out nineteen has 8 letters */

int main()
{
    cout << "The answer is: " << CountSum() << '\n';
    return 0;
}

int LetterCount(int N)
{
    if (N < 20 && N >= 0)
    {
        switch (N)
        {
        case 0:
            return 0;
        case 1://one
        case 2://two
        case 6://six
        case 10://ten
            return 3;
           
        case 4://four
        case 5://five
        case 9://nine
            return 4;
        

        case 3://three
        case 7://seven
        case 8://eight
            return 5;
           

        case 11://eleven
        case 12://twelve
            return 6;
           

        case 15://fifteen
        case 16://sixteen
            return 7;
           

        case 19://nineteen
        case 13://thirteen
        case 14://fourteen
        case 18://eighteen
            return 8;
           

        case 17://seventeen
            return 9;
           

        default:
            return 0;
        }
    }
    else if (N > 19 && N < 100)
    {
        switch (N / 10) // only 2-9
        {
        case 2://twenty
        case 3://thirty
        case 8://eighty
        case 9://ninety
            return (6 + LetterCount(N % 10));
            
        case 4://forty
        case 5://fifty
        case 6://sixty
            return (5 + LetterCount(N % 10));
            
        case 7://seventy
            return (7 + LetterCount(N % 10));
            

        default:
            return 0;
        }
    }
    else if (N > 99 && N < 1000)
    {
        if (N%100==0)
        {
            return( LetterCount(N /100)+7); //no need for and
        }
        else
        {
            return (LetterCount(N / 100) + LetterCount(N % 100) + 10); // 10 for "hundred and"
        }
        
        
    }
    else
    {
        return 11; // 8 for "one thousand"
    }
}

int CountSum()
{
    int sum = 0;
    for (int i = 1; i <= 1000; i++)
    {
        sum += LetterCount(i);
    }
    return sum;
}