#include<iostream>
using namespace std;

int binarysearch(int a[],int n,int key)
{
    int s=0;
    int e=n-1;
    while (s<=e)
    {
        int m=(s+e)/2;
        if (a[m]==key)
        {
            return m;
        }
        else if (a[m]>key)
        {
            e=m-1;
        }
        else
        {
            s=m+1;
        }
    }
    return -1;
}

int main()
{
    int a[]={1,2,3,4,5,6,7};
    int n=sizeof(a) / sizeof(int);
    cout<<binarysearch(a,n,7)<<endl;
    return 0;
}