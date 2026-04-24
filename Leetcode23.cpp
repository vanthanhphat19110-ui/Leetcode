/* Leetcode 23: Merge k linked lists. */
// Difficulty: Hard.

#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    void minHeapifyUp(vector<ListNode *> &vec, int i)
    {
        while (i > 0)
        {
            int parent = (i - 1) / 2;
            if (vec[parent]->val <= vec[i]->val)
                break;
            swap(vec[parent], vec[i]);
            i = parent;
        }
    }

    void minHeapifyDown(vector<ListNode *> &vec, int i)
    {
        int n = vec.size();
        while (2 * i + 1 < n)
        {
            int left = 2 * i + 1, right = 2 * i + 2, lowest = i;
            if (left < n && vec[left]->val < vec[lowest]->val)
                lowest = left;
            if (right < n && vec[right]->val < vec[lowest]->val)
                lowest = right;
            if (lowest == i)
                break;
            swap(vec[i], vec[lowest]);
            i = lowest;
        }
    }

    void pushMinHeap(vector<ListNode *> &vec, ListNode *node)
    {
        vec.push_back(node);
        int n = vec.size();
        minHeapifyUp(vec, n - 1);
    }

    ListNode *popMinHeap(vector<ListNode *> &vec)
    {
        ListNode *temp = vec[0];
        vec[0] = vec.back();
        vec.pop_back();
        if (!vec.empty())
            minHeapifyDown(vec, 0);
        return temp;
    }

    void append(ListNode *&head, ListNode *&tail, ListNode *node)
    {
        if (head == nullptr)
        {
            head = node;
            tail = node;
        }
        else
        {
            tail->next = node;
            tail = node;
        }
    }

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *head = nullptr, *tail = nullptr;
        int n = lists.size();
        vector<ListNode *> minHeap;
        for (int i = 0; i < n; i++)
        {
            if (lists[i] != nullptr)
                pushMinHeap(minHeap, lists[i]);
        }
        while (!minHeap.empty())
        {
            ListNode *rootMinHeap = popMinHeap(minHeap);
            ListNode *next = rootMinHeap->next;
            rootMinHeap->next = nullptr;
            append(head, tail, rootMinHeap);
            if (next != nullptr)
                pushMinHeap(minHeap, next);
        }
        return head;
    }
};