#include<iostream>
#include<cstring>
#include<vector>
using namespace std;

int solve(string &s1, int n, string &s2, int m)
{
    //base case
    if (n==0) return m;
    if (m==0) return n;

    //recursive case
    if (s1[n-1] != s2[m-1])
    {
        int op1=solve(s1,n,s2,m-1);
        int op2=solve(s1,n-1,s2,m-1);
        int op3=solve(s1,n-1,s2,m);

        return 1 + min(op1, min(op2,op3));
    }
    else
    {
        return solve(s1,n-1,s2,m-1);
    }
}

int topDown(string &s1, int n, string &s2, int m, int dp[][100])
{
    //base case
    if (n==0) return dp[n][m]=m;
    if (m==0) return dp[n][m]=n;

    //check
    if (dp[n][m]!=-1) return dp[n][m];

    //recursive case
    if (s1[n-1] != s2[m-1])
    {
        int op1=topDown(s1,n,s2,m-1,dp);
        int op2=topDown(s1,n-1,s2,m,dp);
        int op3=topDown(s1,n-1,s2,m-1,dp);

        return dp[n][m]=1+min(op1,min(op2,op3));
    }
    else
    {
        return dp[n][m]=topDown(s1,n-1,s2,m-1,dp);
    }
}

int bottomUp(string &s1, string &s2)
{
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1));

    for (int n=0;n<=s1.size();n++)
    {
        for (int m=0;m<=s2.size();m++)
        {
            if (n==0) dp[n][m]=m;
            else if (m==0) dp[n][m]=n;
            else if (s1[n-1] != s2[m-1])
            {
                dp[n][m] = 1 + min(dp[n][m-1] , min(dp[n-1][m-1] , dp[n-1][m]));
            }
            else
            {
                dp[n][m] = dp[n-1][m-1];
            }
        }
    }
    return dp[s1.size()][s2.size()];
}

int main()
{
    string s1="sunday";
    string s2="saturday";

    cout<<solve(s1,s1.size(),s2,s2.size())<<endl;;

    int dp[100][100];
    memset(dp,-1,sizeof dp);
    cout<<topDown(s1,s1.size(),s2,s2.size(),dp)<<endl;;

    cout<<bottomUp(s1,s2);

    return 0;
}