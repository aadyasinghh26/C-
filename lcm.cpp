#include<iostream>
using namespace std;
int main()
{
    int a,b;
    cin>>a>>b;
    int x=max(a,b);
    while (x%a!=0 || x%b!=0)
    {
        x++;
    }
    cout<<x;
    
    return 0;
}