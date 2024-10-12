#include<iostream>
using namespace std;

void oddeven(int z)
{
    if (z%2==0)
    {
        cout<<"even"<<endl;
    }
    else
    {
        cout<<"odd"<<endl;
    }
}

int multiply(int x,int y)
{
    int ans=x*y;
    return ans;
}

void printtable(int initialval,int finalval,int step)
{
    int fah,cel;
    initialval=fah;
    while (fah<=finalval)
    {
        cel=((fah-32)*5)/9;
        cout<<fah<<' '<<cel<<endl;
        fah=fah+step;
    }
}

int fact(int num)
{
    int ans=1;
    for (int i=1;i<=num;i++)
    {
        ans*=i;
    }
    return ans;
}
int ncr(int n,int r)
{
    int fact_n=fact(n);
    int fact_r=fact(r);
    int fact_nr=fact(n-r);
    return fact_n/(fact_r*fact_nr);
}

int main()
{
    int n=21;
    oddeven(n);
    oddeven(10);
    int product=multiply(13,10);
    cout<<product<<endl;
    printtable(0,300,20);
    int ans1=fact(5);
    cout<<ans1<<endl;
    int ans=ncr(5,2);
    cout<<"ncr is:"<<ans<<endl;
    return 0;
}