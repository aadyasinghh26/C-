#include<iostream>
using namespace std;

int main()
{
    int num=84;
    int idx=3;
    int mask=(1>>idx);

    if ((num & mask) == 0) cout<<"unset bit";

    else cout<<"set bit";

    return 0;
}