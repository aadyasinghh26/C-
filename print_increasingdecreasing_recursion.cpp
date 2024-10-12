#include<iostream>
using namespace std;

void printIncreasing(int n)
{
    if (n==0) 
    {
        return;
    }
    printIncreasing(n-1);
    cout<<n<<' ';
}

void printDecreasing(int n)
{
    if (n==0) 
    {
        return;
    }
    cout<<n<<' ';
    printDecreasing(n-1);
}

int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;

    printIncreasing(n);
    cout<<endl;

    printDecreasing(n);
    cout<<endl;
    
    return 0;
}