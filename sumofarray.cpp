#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;
    int a[1000];
    int i=0;
    while (i<n)
    {
        cin>>a[i];
        i++;
    }
    int sum=0;
    for (int i=0;i<n;i++)
    {
        sum+=a[i];
    }
    cout<<"the sum of elements is:"<<sum;
    return 0;
}