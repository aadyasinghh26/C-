#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[]="Akshat###$$@@!!Aniket@@((**&&&##Ashwin!!@@^^";

    char *p=strtok(a,"#$@!(*&^");
    while (p!=NULL)
    {
        cout<<p<<endl;
        p=strtok(NULL,"#$@!(*&^");
        //NULL is written because agar 'a' likha hota toh phirse starting se start hua hota
    }
    return 0;
}