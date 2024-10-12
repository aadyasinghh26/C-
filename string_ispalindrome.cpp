#include<iostream>
#include<cstring>
using namespace std;

bool ispalindrome(char*a)
{
    int fi=0;
    int li=strlen(a)-1;
    while(fi<li)
    {
         if (a[fi]!=a[li])
         {
             return false;
         }
         fi++;
         li--;
         
    }
    return true;
}

int main()
{
    char a[]="abcba";
    if (ispalindrome(a))
    {
        cout<<"palindrome";
    }
    else
    {
        cout<<"not a palindrome";
    }
    return 0;
}

