1	*	*	*	*	*	*	
1	2	*	*	*	*	*	
1	2	3	*	*	*	*	
1	2	3	4	*	*	*	
1	2	3	4	5	*	*	
1	2	3	4	5	6	*	
1	2	3	4	5	6	7


#include<iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int i=1;
    while (i<=n)
    {
        int j=1;
        while (j<=i)
        {
            cout << j << "\t";
            j=j+1;
        }
        int k=1;
        while (k<=n-i)
        {
            cout << '*' << "\t";
            k=k+1;
        }
        cout << endl;
        i++;
    }
    return 0;
}