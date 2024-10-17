#include<iostream>
using namespace std;

void balancedParenthesis(int n,int i,char *a,int open,int close)
{
    if (i==2*n)
    {
        a[i]='\0';
        cout<<a<<endl;
        return;
    }

    if (open<n)
    {
        a[i]='(';
        balancedParenthesis(n,i+1,a,open+1,close);
    }

    if (open>close)
    {
        a[i]=')';
        balancedParenthesis(n,i+1,a,open,close+1);
    }

}

int main()
{
    int n;
    cout<<"enter the number:";
    cin>>n;
    char a[1000];
    balancedParenthesis(n,0,a,0,0);
    return 0;
}