/* Leetcode Q3: Max consecutive ones. */

#include <iostream>
#include <vector>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int maxSize = 0, size = 0, left = 0, right = 0;
    while (right < nums.size())
    {
        if (nums[right] == 1)
        {
            size++;
            right++;
            maxSize = (size > maxSize) ? size : maxSize;
        }
        else
        {
            size = 0;
            left = right;
            right++;
        }
    }
    return maxSize;
}