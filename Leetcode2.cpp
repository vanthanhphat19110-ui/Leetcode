/* Leetcode 2: Add two numbers. */

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

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    if (l1 == nullptr)
        return l2;
    if (l2 == nullptr)
        return l1;
    ListNode *head = nullptr, *tail = nullptr;
    ListNode *curr1 = l1, *curr2 = l2;
    int carry = 0;
    while (curr1 != nullptr || curr2 != nullptr || carry != 0)
    {
        int sum = carry;
        if (curr1 != nullptr)
            sum += curr1->val;
        if (curr2 != nullptr)
            sum += curr2->val;
        ListNode *newNode = new ListNode(sum % 10);
        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = tail->next;
        }
        carry = sum / 10;
        if (curr1 != nullptr)
            curr1 = curr1->next;
        if (curr2 != nullptr)
            curr2 = curr2->next;
    }
    return head;
}