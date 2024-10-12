#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;
    int arr[1000];
    int ans=INT_MIN;
    int i=0;
    while (i<n)
    {
        cin>>arr[i];
        i++;
    }
    for (int i=0;i<n;i++)
    {
        int sum=0;
        for (int j=i;j<n;j++)
        {
            sum+=arr[j];
            //int sum=0;
            //for (int k=i;k<=j;k++)
            //{
              //  sum+=arr[k];
            //}
        }
            ans=max(ans,sum);
        
    }
    cout<<"the answer is:"<<ans;
    return 0;
}