#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack <int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    while (!s.empty())      //while (s.empty!=0)
    {
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}
