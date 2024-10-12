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
    int sum1=0;
    int ans1=0;
    for (int i=0;i<n;i++)
    {
        sum1+=arr[i];
        if (sum1<0)
        {
            sum1=0;
        }
        if (sum1>ans1)
        {
            ans1=sum1;
        }
        ans1=max(sum1,ans1);
    }
    int totalsum=0;
    for (int i=0;i<n;i++)
    {
        totalsum+=arr[i];
        arr[i]*=(-1);
    }
    int sum2=0;
    int ans2=0;
    for (int i=0;i<n;i++)
    {
        sum2+=arr[i];
        if (sum2<0)
        {
            sum2=0;
        }
        if (sum2>ans2)
        {
            ans2=sum2;
        }
        ans2=max(sum2,ans2);
    }
    int op1=ans1;
    int op2=totalsum+ans2;
    cout<<max(op1,op2)<<endl;
    return 0;
}