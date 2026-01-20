//leetcode question

#define node ListNode
#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
    public:

    node *addTwoNumbers(node *l1, node *l2)
    {
        node *nH, *nT;
        int c=0;

        while (l1 || l2 || c)
        {
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+c;
            int x=sum%10;
            c=sum/10;
            node *n=new node(x);
            nT->next=n;
            nT=n;

            l1=l1?l1->next:l1;
            l2=l2?l2->next:l2;
        }
        return nH->next;
    }
};

int main()
{
    return 0;
}