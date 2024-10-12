#include<iostream>
#include<cstring>
using namespace std;

void rotate(char*a)
{
    int len=strlen(a);
    char ch=a[len-1];
    int i=len-2;
    while (i>=0)
    {
        a[i+1]=a[i];
        i--;
    }
    a[0]=ch;
    

}
int main()
{
    char a[7]="CODING";
    int len=strlen(a);
    int r;
    cout<<"enter the number of times you want to rotate:";
    cin>>r;
    r=r%len;
    for (int i=0;i<r;i++)
    {
        rotate(a);
    }
    cout<<a<<endl;
    return 0;
}