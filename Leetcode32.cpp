/* Leetcode 32: Longest valid parentheses. */
// Difficulty: Hard.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        vector<int> stack;
        stack.push_back(-1);
        int maxLength = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
                stack.push_back(i);
            else // s[i] == ')'
            {
                stack.pop_back();
                if (stack.empty())
                    stack.push_back(i);
                else // stack is not empty.
                {
                    int top = stack.back();
                    int length = i - top;
                    maxLength = (length > maxLength) ? length : maxLength;
                }
            }
        }
        return maxLength;
    }
};