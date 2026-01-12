//this is a top down approach


#include<iostream>
#include<cstring>   //generally use for writing -1
using namespace std;

int fibo(int n)
{
    if (n==0 or n==1) return n;
    else return fibo(n-1)+fibo(n-2);
}

int solve(int n, int *dp)
{
    if (n==0 or n==1)
    {
        dp[n]=n;       //return karne se pehle store karna
        return n;
    }

    //check dp array if the value of n already exists or not (dp ke array ko check karo ki kahi ans already h toh nahi)
    if (dp[n]!=-1)
    {
        return dp[n];
    }

    return dp[n]=solve(n-1,dp)+solve(n-2,dp);  
    
}

int main()
{
    int n;
    cin>>n;
    int dp[1000];

    memset(dp,-1,sizeof dp);   //array ke harr bucket par -1 daal dega
    
    cout<<solve(n,dp)<<endl;
    for (int i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }

    cout<<endl;
    cout<<fibo(n)<<endl;

    return 0;
}