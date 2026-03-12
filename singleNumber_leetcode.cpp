#include<iostream>
using namespace std;

int singleNumber(int *a,int n)
{
    int ans=0;

    for (int i=0;i<n;i++)
    {
        ans=ans^a[i];
    }
    return ans;
}

int main()
{
    int a[]={2,1,4,1,2};
    int n=sizeof (a) / sizeof(int);
    
    cout<<singleNumber(a,n)<<endl;

    return 0;
}