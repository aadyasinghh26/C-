REVERSE A STRING

#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[]="Hello World";
    int i=0;
    int j=strlen(a)-1;
    while (i<j)
    {
        swap (a[i],a[j]);
        i++;
        j--;
    }
    cout<<a;
    return 0;
}

