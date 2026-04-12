/* Leetcode 24: Swap nodes in pairs. */

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

ListNode *swapPairs(ListNode *head)
{
    ListNode *dummy = new ListNode();
    dummy->next = head;
    ListNode *prev = dummy;
    while (prev->next != nullptr && prev->next->next != nullptr)
    {
        ListNode *first = prev->next;
        ListNode *second = first->next;
        first->next = second->next;
        second->next = first;
        prev->next = second;
        prev = first;
    }
    head = dummy->next;
    delete dummy;
    return head;
}