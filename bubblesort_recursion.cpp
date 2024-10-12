#include<iostream>
using namespace std;

void bubbleSort(int *a,int n,int i)
{
    if (i==n-1) return;
    for (int j=0;j<n-1-i;j++)
    {
        if (a[j]>a[j+1])
        {
            swap(a[j],a[j+1]);
        }
    }
    bubbleSort(a,n,i+1);
}

void bubbleSort1(int *a,int n,int i,int j)
{
    if (i==n-1) return;
    if (j<n-1-i)
    {
        if (a[j]>a[j+1])
        {
            swap (a[j],a[j+1]);
        }
        bubbleSort1(a,n,i,j+1);
    }
    else
    {
        bubbleSort1(a,n,i+1,j);
    }
}

int main()
{
    int a[]={5,4,3,2,1};
    int n=sizeof(a)/sizeof(int);
    int i=0;
    int j=0;
    bubbleSort(a,n,i);
    for (int k=0;k<n;k++)
    {
        cout<<a[k]<<' ';
    }
    cout<<endl;

    bubbleSort1(a,n,i,j);
    for (int k=0;k<n;k++)
    {
        cout<<a[k]<<' ';
    }
    cout<<endl;

    return 0;
}