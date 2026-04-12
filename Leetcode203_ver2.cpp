/* Leetcode 203: Remove linked list elements. */

#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    if (head == nullptr)
        return nullptr;
    head->next = removeElements(head->next, val);
    if (head->val == val)
        return head->next;
    else
        return head;
}