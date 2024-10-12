#include<iostream>
#include<cstring>
using namespace std;

void rotate(char*a,int r)
{
    int len=strlen(a);
    r=r%len;
    int i=len-1;
    while (i>=0)
    {
        a[i+r]=a[i];
        i--;
    }
    i=len;
    int j=0;
    while (j<r)
    {
        a[j]=a[i];
        i++;
        j++;
    }
    a[len]='\0';
    
}
int main()
{
    char a[100]="coding";
    rotate(a,120);
    cout<<a<<endl;
    return 0;


}