#include<iostream>
using namespace std;

int arraysum(int *a,int n)
{
    if (n==0) return 0;
    else
    {
        return a[0]+arraysum(a+1,n-1);
    }
}

int main()
{
    int a[]={1,2,3,4,5};
    int n=sizeof(a)/sizeof(int);
    cout<<arraysum(a,n)<<endl;
    return 0;
}