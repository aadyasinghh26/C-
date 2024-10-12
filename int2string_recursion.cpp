#include<iostream>
using namespace std;
string values[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

void intTostring(int n)
{
    if (n==0)
    {
        return;
    }
    int ld=n%10;
    intTostring(n/10);
    cout<<values[ld]<<' ';
}

int main()
{
    int n=2048;
    intTostring(n);
    cout<<endl;
    return 0;
}