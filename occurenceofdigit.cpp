#include<iostream>
using namespace std;
int main()
{
    int num,digit;
    cout<<"enter the number:";
    cin>>num;
    cout<<"enter the digit:";
    cin>>digit;
    int count=0;
    while (num>0)
    {
        int ld=num%10;
        if (ld==digit)
        {
            count++;
        }
        num=num/10;
    }
    cout<<"the "<<digit<<" comes "<<count<<" times.";
    return 0;
}