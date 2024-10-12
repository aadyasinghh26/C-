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
    int largest=a[0];
    for (int i=0;i<n;i++)
    {
        if (a[i]>largest)
        {
            largest=a[i];
        }
    }
    cout<<"largest element is:"<<largest;
    return 0;
}