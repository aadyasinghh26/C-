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
    for (int i=0;i<n;i++)
    {
        int min=i;
        for (int j=i;j<n;j++)
        {
            if (arr[j]<arr[min])
            {
                min=j;
            }
        }
        swap(arr[min],arr[i]);
    }
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<' ';
    }
    return 0;
}