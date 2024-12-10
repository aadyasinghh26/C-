#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the size of the array:";
    cin>>n;
    int *arr=new int[n];
    for (int i=0;i<n;i++)
    {
        arr[i]=i+1;
        cout<<arr[i]<<' ';
    }

    // delete []arr;   //heap memory is free
    // arr=NULL;       //doesn't point to heap memory now     //if we try to access this, it will give segmentation fault
    return 0;
}