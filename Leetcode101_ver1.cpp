/* Leetcode 101: Symmetric Tree. */
// Difficulty: Easy.

#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {};
};

class Solution
{
public:
    bool isSymmetric(TreeNode *p, TreeNode *q)
    {
        if (p == nullptr && q == nullptr)
            return true;
        if (p == nullptr || q == nullptr)
            return false;
        if (p->val == q->val)
        {
            bool isOuterSymmetric = isSymmetric(p->left, q->right);
            bool isInnerSymmetric = isSymmetric(p->right, q->left);
            return isOuterSymmetric && isInnerSymmetric;
        }
        else
            return false;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        return isSymmetric(root->left, root->right);
    }
};