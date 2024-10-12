#include<iostream>
using namespace std;

int functionPower(int x,int n)
{
    if (n==0)
    {
        return true;
    }
    return x * functionPower(x,n-1);
}

int main()
{
    int x;
    cout<<"enter the base:";
    cin>>x;
    int n;
    cout<<"enter the power:";
    cin>>n;

    cout<<functionPower(x,n);

    return 0;
}