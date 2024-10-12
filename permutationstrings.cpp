#include<iostream>
#include <cstring>
using namespace std;
int main()
{
    char a[]="abcc";
    char b[]="dbac";
    int freq[26]={0};
    for (int i=0;a[i]!='\0';i++)
    {
        int index= (a[i]-'a');
        freq[index]++;
    }

    for (int i=0;b[i]!='\0';i++)
    {
        int index= (b[i]-'a');
        freq[index]--;
    }

    bool isPermutation=true;
    for (int i=0;i<26;i++)
    {
        if (freq[i]!=0)
        {
            isPermutation=false;
        }
    }

    if (isPermutation)
    {
        cout<<"Strings are Permutable"; 
    }
    else
    {
        cout<<"Strings are not Permutable";
    }

    return 0;
}