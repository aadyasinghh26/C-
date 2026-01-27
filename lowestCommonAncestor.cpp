//leetcode question

#include<iostream>
using namespace std;

struct TreeNode {
int val;
TreeNode *left;
TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *solve(TreeNode* root, TreeNode* p, TreeNode* q)
{
    //base case
    if (!root) return root;

    if (root == p || root == q) return root;

    //recursive case
    TreeNode *left = solve(root->left,p,q);
    TreeNode *right = solve(root->right,p,q);

    if (left and right) return root;
    if (left and !right) return left;
    return right;
}

class Solution
{
    public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        return solve(root,p,q);
    }
};

int main()
{
    return 0;
}