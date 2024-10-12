#include<iostream>
using namespace std;

int fact (int n)
{
    int ans=1;
    for (int i=1;i<=n;i++)
    {
        ans*=i;
    }
    return ans;
}

int factorial (int n,int r)
{
    int fact_n=fact(n);
    int fact_r=fact(r);
    int fact_nr=fact(n-r);
    return fact_n/(fact_r * fact_nr);
}

int main()
{
    int n;
    cin>>n;
    for (int i=0;i<=n-1;i++)
    {
        for (int j=0;j<=i;j++)
        {
            int term=factorial(i,j);
            cout<<term<<' ';
        }
        cout<<endl;
    }
    return 0;
}