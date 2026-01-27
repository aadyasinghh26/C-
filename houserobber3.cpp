//leetcode question

#include<iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Pair
{
    public:
    int rootchori_profit;
    int rootbinachori_profit;
};

class Solution
{
    public:

    Pair solve(TreeNode *root)
    {
        Pair p;
        
        //base case
        if (!root) return {0,0};

        //recursive case
        Pair left=solve(root->left);
        Pair right=solve(root->right);

        //main root node chori hua toh left aur right waala root node nahi chori hoga bc adjacent
        p.rootchori_profit = root->val + left.rootbinachori_profit + right.rootbinachori_profit;

        //main root node chori nahi hua
        p.rootbinachori_profit = max(left.rootchori_profit , left.rootbinachori_profit) + 
                                 max(right.rootchori_profit , right.rootbinachori_profit);

        return p;
    }
    
    int rob(TreeNode* root)
    {
        Pair ans=solve(root);
        return max(ans.rootchori_profit , ans.rootbinachori_profit);
    }
};

int main()
{
    return 0;
}