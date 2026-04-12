/* Leetcode Q2: Shuffle the array. */

#include <iostream>
#include <vector>
using namespace std;

vector<int> shuffle(vector<int> &nums, int n)
{
    vector<int> ans(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); i++)
    {
        if (i % 2 == 0)
            ans[i] = nums[i / 2];
        else
            ans[i] = nums[(i + nums.size()) / 2];
    }
    return ans;
}