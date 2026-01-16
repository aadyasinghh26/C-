#include<iostream>
#include<climits>
#include<vector>
#include<cstring>
using namespace std;

int solve(int amount,int *deno,int n)
{
    //base case
    if (amount==0) return 0;

    //recursive case
    int ans=INT_MAX;
    for (int i=0;i<n;i++)
    {
        if (amount>=deno[i])
        {
            int chhotiprob=amount-deno[i];
            int x=solve(chhotiprob,deno,n);
            if (x!=INT_MAX)
            {
                ans=min(ans,x+1);
            }
        }
    }
    return ans;
}

int topDown(int amount,int *deno,int n,int *dp)
{
    //base case
    if (amount==0) return dp[amount]=0;

    //check
    if (dp[amount]!=-1) return dp[amount];

    //recursive case
    int ans=INT_MAX;
    for (int i=0;i<n;i++)
    {
        if (amount>=deno[i])
        {
            int chhotiprob=amount-deno[i];
            int x=topDown(chhotiprob,deno,n,dp);
            if (x!=INT_MAX)
            {
                ans=min(ans,x+1);
            }
        }
    }
    return dp[amount]=ans;
}

int bottomUp(int amount,int *deno,int n)
{
    vector<int> dp(amount+1,INT_MAX);

    dp[0]=0;

    for (int amt=1;amt<=amount;amt++)
    {
        int ans=INT_MAX;
        for (int i=0;i<n;i++)
        {
            if (amt>=deno[i])
            {
                int x=dp[amt-deno[i]];
                if (x!=INT_MAX)
                {
                    dp[amt]=min(dp[amt],x+1);
                }
            }
        }
    }
    return dp[amount];    //cause we want to know the min number of coins for the AMOUNT
}

int main()
{
    int deno []={1,7,10};
    int n=sizeof (deno)/ sizeof (int);

    int dp[100000];
    memset(dp,-1,sizeof dp);

    int amount;
    cin>>amount;

    //cout<<solve(amount,deno,n)<<endl;
    cout<<topDown(amount,deno,n,dp)<<endl;
    cout<<bottomUp(amount,deno,n)<<endl;
    
    return 0;
}