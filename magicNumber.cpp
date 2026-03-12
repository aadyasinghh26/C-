#include<iostream>
using namespace std;

int magicNumber(int num)
{
    int sum=0 , mul=5;
    while (num > 0)
    {
        if ((num & 1) != 0)
        {
            sum=sum+mul;
        }
        mul=mul * 5;
        num=num>>1;
    }
    return sum;
}

int main()
{
    cout<<magicNumber(9)<<endl;

    return 0;
}