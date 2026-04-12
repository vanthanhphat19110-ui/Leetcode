/* Leetcode 1: Two sum. */

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> twoSum(vector<int> &nums, int target)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        if (map.count(nums[i]) == 1)
            return {map[nums[i]], i};
        int needed = target - nums[i];
        map[needed] = i;
    }
    return {};
}