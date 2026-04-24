/* Leetcode 739: Daily temperature. */
// Difficulty: Medium.

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0), stack;
        for (int i = 0; i < n; i++)
        {
            while (!stack.empty() && temperatures[i] > temperatures[stack.back()])
            {
                int j = stack.back();
                ans[j] = i - j;
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return ans;
    }
};