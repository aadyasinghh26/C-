#include<iostream>
using namespace std;

int countSetBits(int num)
{
    int count=0;
    while (num > 0)
    {
        if ((num & 1) != 0) count++;

        num=num>>1;
    }
    return count;
}

int optimisedApproach(int num)
{
    int count=0;
    while (num > 0)
    {
        num = (num & (num-1));
        count++;
    }
    return count;
}

int main()
{
    cout<<countSetBits(84)<<endl;

    cout<<optimisedApproach(84)<<endl;

    return 0;
}