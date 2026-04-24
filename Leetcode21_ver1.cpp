/* Leetcode 21: Merge two lists. */
// Difficulty: Easy.

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

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == nullptr)
            return list2;
        if (list2 == nullptr)
            return list1;
        ListNode *dummy = new ListNode();
        ListNode *curr = dummy;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                ListNode *temp = list1;
                list1 = list1->next;
                curr->next = temp;
                curr = curr->next;
            }
            else
            {
                ListNode *temp = list2;
                list2 = list2->next;
                curr->next = temp;
                curr = curr->next;
            }
        }
        if (list1 != nullptr)
        {
            curr->next = list1;
            list1 = nullptr;
        }
        if (list2 != nullptr)
        {
            curr->next = list2;
            list2 = nullptr;
        }
        curr = dummy->next;
        delete dummy;
        return curr;
    }
};