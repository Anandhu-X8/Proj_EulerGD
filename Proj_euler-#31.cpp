#include <iostream>
using namespace std;
int static count=0;
/*the logic is to chop bucket with largest cup
then again untill three conditons occur
if == its a conbination
then backtrack with a smaller cup*/
void Partition(int bucket, int cups[],int cup)
{
    if (cup<9)
    {
        if (cups[cup]==1)
        {
            count++;
            return;
        }
        if (bucket>cups[cup])
        {
            Partition(bucket,cups,cup+1);
            Partition(bucket-cups[cup],cups,cup);
        }
        else if(bucket==cups[cup])
        {
            count++;
            Partition(bucket,cups,cup+1);
        }
        else if(bucket<cups[cup])
        {
            Partition(bucket,cups,cup+1);
        }
        
        
    }

}
int main()
{
    
    int cups[]={200,100,50,20,10,5,2,1,0};
    Partition(200,cups,0);
    cout<<count<<'\n';
return 0;
}

/* WHATTT??
THIS IS AN INSANELY DIFFICULT QUESTION
BUT I GOT GREEN ON FIRST TRY!

    though i should avoid global variables*/