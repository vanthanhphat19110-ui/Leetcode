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
    struct QueueNode
    {
        TreeNode *data;
        QueueNode *next;
        QueueNode(TreeNode *value) : data(value), next(nullptr) {};
    };

    struct Queue
    {
        QueueNode *front;
        QueueNode *back;
    };

    void init(Queue &q)
    {
        q.front = nullptr;
        q.back = nullptr;
    }

    bool isEmpty(Queue &q)
    {
        return q.front == nullptr;
    }

    void enqueue(Queue &q, TreeNode *value)
    {
        QueueNode *p = new QueueNode(value);
        if (q.front == nullptr)
        {
            q.front = p;
            q.back = p;
        }
        else // q.front != nullptr
        {
            q.back->next = p;
            q.back = p;
        }
    }

    void dequeue(Queue &q)
    {
        if (q.front == nullptr)
            return;
        QueueNode *temp = q.front;
        q.front = q.front->next;
        if (q.front == nullptr)
            q.back = nullptr;
        delete temp;
    }

    TreeNode *front(Queue &q)
    {
        if (q.front == nullptr)
            return nullptr;
        return q.front->data;
    }

    void swapTreeNode(TreeNode *&x, TreeNode *&y)
    {
        TreeNode *temp = x;
        x = y;
        y = temp;
    }

    TreeNode *invertTree(TreeNode *root)
    {
        if (root == nullptr)
            return nullptr;
        Queue q;
        init(q);
        enqueue(q, root);
        while (!isEmpty(q))
        {
            TreeNode *curr = front(q);
            dequeue(q);
            swapTreeNode(curr->left, curr->right);
            if (curr->left != nullptr)
                enqueue(q, curr->left);
            if (curr->right != nullptr)
                enqueue(q, curr->right);
        }
        return root;
    }
};
