#include<iostream>
#include<climits>
#include<cstring>
#include<vector>
using namespace std;

int solve(int n)
{
    //base case
    if (n==1) return 0;
    
    //recursive case
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;

    if (n%3==0)
    op1=solve(n/3);

    if (n%2==0)
    op2=solve(n/2);

    op3=solve(n-1);

    return min(op1,min(op2,op3))+1;   //min func takes only two arguments
}

int topDown(int n, int *dp)
{
    //base case
    if (n==1) return dp[n]=0;    //return se pehle store karo      //equals to operator vahi return karta jo rhs side likha hota h

    //check karo ki kahi n par value pehle se toh nahi
    if (dp[n]!=-1)
    return dp[n];

    //recursive case
    int op1,op2,op3;
    op1=op2=op3=INT_MAX;

    if (n%3==0)
    op1=topDown(n/3,dp);

    if (n%2==0)
    op2=topDown(n/2,dp);

    op3=topDown(n-1,dp);

    return dp[n]=min(op1,min(op2,op3))+1;
}

int bottomUp(int n)
{
    vector<int> dp(n+1,-1);

    dp[1]=0;

    for (int i=2;i<=n;i++)
    {
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;

        op1=dp[i-1];
        if (i%3==0)
        op2=dp[i/3];
        if (i%2==0)
        op3=dp[i/2];

        dp[i]=min(op1,min(op2,op3))+1;
    }

    for (int i=1;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;
    return dp[n];
}


int main()
{
    int n;
    cin>>n;
    int dp[10000];
    memset(dp,-1,sizeof dp);

    cout<<solve(n)<<endl;
    cout<<topDown(n,dp)<<endl;
    cout<<bottomUp(n)<<endl;

    return 0;
}