/* Leetcode 226: Invert Binary Tree. */
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
    void swapTreeNode(TreeNode *&x, TreeNode *&y)
    {
        TreeNode *temp = x;
        x = y;
        y = temp;
    }

    void invertBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return;
        swapTreeNode(root->left, root->right);
        invertBinaryTree(root->left);
        invertBinaryTree(root->right);
    }

    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        invertBinaryTree(root);
        return root;
    }
};