#include<iostream>
using namespace std;

void subsequences(char *a,int i,char *b,int j)
{
    if (a[i]=='\0')
    {
        b[j]='\0';
        cout<<b<<endl;
        return;
    }
    
    //ith term ko nahi include karna
    subsequences(a,i+1,b,j);
    //ith term ko include karna
    b[j]=a[i];
    subsequences(a,i+1,b,j+1);
}

int main()
{
    char a[100]={"abc"},b[100];
    subsequences(a,0,b,0);
    return 0;
}