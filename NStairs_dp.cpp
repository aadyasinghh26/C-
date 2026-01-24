#include<iostream>
#include<vector>
using namespace std;

#define vvi(a,n,m,val) vector<vector<int>> a(n+1 , vector<int> m+1 , val);
#define vi(a,n,val) vector<int> a(n+1 , val);

int topDown(int n, int k, vector<int> &dp)
{
    if (n==0) dp[n]=1;
    if (n<0) return 0;

    if (dp[n] != -1) return dp[n];

    int ans=0;
    for (int i=1;i<=k;i++)
    {
        ans+=topDown(n-i,k,dp);
    }
    return dp[n]=ans;
}

int bottomUp(int n, int k)
{
    vi(dp,n,0);

    dp[0]=1;

    int ans=0;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=k;j++)
        {
            if (i-j < 0) break;
            dp[i]+=dp[i-j];
        }
    }

    for (int i=0;i<=n;i++)
    {
        cout<<dp[i]<<" ";
    }
    cout<<endl;

    return dp[n];
}

int nStairs(int n, int k)  //optimised version
{
    vi(dp,100,0);

    dp[0] = dp[1] = 1;

    for (int i=2;i<=n;i++)
    {
        dp[i] = 2 * dp[i-1] - (i-1-k >= 0 ? dp[i-1-k]:0);
    }
    return dp[n];
}

int main()
{
    vi(dp,100,-1);

    cout<<topDown(5,3,dp)<<endl;

    cout<<bottomUp(6,4)<<endl;

    cout<<nStairs(5,3)<<endl;

    return 0;
}