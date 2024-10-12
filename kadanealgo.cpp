#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;
    int arr[1000];
    int i=0;
    int sum=0;
    int ans=INT_MIN;
    while (i<n)
    {
        cin>>arr[i];
        i++;
    }
    for (int i=0;i<n;i++)
    {
        sum+=arr[i];
        if (sum>ans)
        {
            ans=sum;
        }
        if (sum<0)
        {
            sum=0;
        }
    }
    cout << ans << endl;
    return 0;
}