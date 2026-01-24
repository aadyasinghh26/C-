#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int lcs(char *a,int n,char *b,int m)
{
    //base case
    if (n==0 || m==0) return 0;

    //recursive case
    if (a[n-1] != b[m-1])
    {
        return max(lcs(a,n,b,m-1) , lcs(a,n-1,b,m));
    }
    else
    {
        return 1 + lcs(a,n-1,b,m-1);
    }
}

int topDown(char *a,int n,char *b,int m,int dp[][100])
{
    //base case
    if (n==0 || m==0) return dp[n][m]=0;

    //check
    if (dp[n][m]!=-1) return dp[n][m];

    //recursive case
    if (a[n-1]!=b[m-1])
    {
        return dp[n][m]=max(topDown(a,n,b,m-1,dp) , topDown(a,n-1,b,m,dp));
    }
    else
    {
        return dp[n][m]=1 + topDown(a,n-1,b,m-1,dp);
    }
}

int bottomUp(char *a,int n,char *b,int m)
{
    int dp[100][100]={0};

    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            if (a[i-1]!=b[j-1])
            {
                dp[i][j]=max(dp[i-1][j] , dp[i][j-1]);
            }
            else
            {
                dp[i][j]=1 + dp[i-1][j-1];
            }
        }
    }


    for (int i=0;i<=n;i++)
    {
        for (int j=0;j<=m;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[n][m];
}

void printLCS(char *a,char *b,int dp[][100])
{
    int n=strlen(a);
    int m=strlen(b);

    string ans="";

    while (n>=0 and m>=0)     //n and m are number of characters
    {
        if (a[n-1]!=b[m-1])
        {
            if (dp[n-1][m] > dp[n][m-1]) n--;
            else m--; 
        }
        else
        {
            ans.push_back(a[n-1]);
            n--;
            m--;
        }
    }

    reverse(ans.begin() , ans.end());
    cout<<ans<<endl;
}

int main()
{
    char a[]="adeaf";
    char b[]="adea";

    cout<<lcs(a,strlen(a),b,strlen(b))<<endl;

    int dp[100][100];
    memset(dp,-1,sizeof dp);
    cout<<topDown(a,strlen(a),b,strlen(b),dp)<<endl;

    cout<<bottomUp(a,strlen(a),b,strlen(b))<<endl;;

    printLCS(a,b,dp);

    return 0;
}