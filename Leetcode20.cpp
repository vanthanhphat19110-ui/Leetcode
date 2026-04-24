/* Leetcode 20: Valid parentheses. */
// Difficulty: Easy.

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        vector<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stack.push_back(s[i]);
            else if (s[i] == ')' && !stack.empty() && stack.back() == '(')
                stack.pop_back();
            else if (s[i] == ']' && !stack.empty() && stack.back() == '[')
                stack.pop_back();
            else if (s[i] == '}' && !stack.empty() && stack.back() == '{')
                stack.pop_back();
            else
                return false;
        }
        return stack.size() == 0;
    }
};