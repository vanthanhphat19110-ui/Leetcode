/* Leetcode 98: Validate Binary Search Tree. */
// Difficulty: Medium.

#include <climits>

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool isValidBST(TreeNode *root, long long low, long long high)
    {
        if (root == nullptr)
            return true;
        if (low < root->val && root->val < high)
        {
            bool isLeftValid = isValidBST(root->left, low, root->val);
            bool isRightValid = isValidBST(root->right, root->val, high);
            return isLeftValid && isRightValid;
        }
        else
            return false;
    }

    bool isValidBST(TreeNode *root)
    {
        return isValidBST(root, LLONG_MIN, LLONG_MAX);
    }
};