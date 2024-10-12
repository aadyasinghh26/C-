#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;
    int arr[1000];
    int i=0;
    while (i<n)
    {
        cin>>arr[i];
        i++;
    }
    for (int i=1;i<n;i++)
    {
        int key=arr[i];
        int pos=i-1;
        while (pos>=0 && arr[pos]>key)
        {
            arr[pos+1]=arr[pos];
            pos--;
        }
        arr[pos+1]=key;
    }
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}