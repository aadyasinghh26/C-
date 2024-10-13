#include<iostream>
using namespace std;

int stringToint(char *a,int n)
{
    if (n==0) return 0;
    int ld=a[n-1]-'0';
    return (stringToint(a,n-1) * 10) + ld; 
}

int main()
{
    char a[]="1234";
    int n=4;
    cout<<stringToint(a,n)<<endl;
    return 0;
}