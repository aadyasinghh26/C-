#include<iostream>
using namespace std;
int main()
{
    int *a=new int;
    *a=12;
    cout<<*a<<endl;

    float*f=new float;
    *f=1.11;
    cout<<*f<<endl;

    // delete a;  // deletes the memory created in heap
    // a=NULL;   //so that it dies't point to any garbage value

    return 0;
}