a 3 4 B 4 @ r S 2 ! $
4
4
10
2

#include<iostream>
using namespace std;
int main()
{
    char ch;
    int digits=0;
    int alphabets=0;
    int whitespaces=0;
    int special=0;
    ch=cin.get();
    while (ch!='$')
    {
        if (ch>='A' and ch<='Z' || ch>='a' and ch<='z')
        {
            alphabets++;
        }
        else if (ch>='0' and ch<='9')
        {
            digits++;
        }
        else if (ch==' ' || ch=='\t' || ch=='\n')
        {
            whitespaces++;
        }
        else
        {
            special++;
        }
        ch=cin.get();
    }
    cout << alphabets << endl << digits << endl << whitespaces << endl << special << endl;
    return 0;
}