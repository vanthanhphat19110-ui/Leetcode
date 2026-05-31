/* Leetcode 15: Three sum. */
// Difficulty: Medium.

#include <vector>
using namespace std;

class Solution
{
public:
    void heapify(vector<int> &nums, int node, int size)
    {
        while (2 * node + 1 < size)
        {
            int left = 2 * node + 1, right = 2 * node + 2, largest = node;
            if (left < size && nums[largest] < nums[left])
                largest = left;
            if (right < size && nums[largest] < nums[right])
                largest = right;
            if (largest == node)
                break;
            swap(nums[node], nums[largest]);
            node = largest;
        }
    }

    void heapSort(vector<int> &nums, int size)
    {
        for (int i = size / 2 - 1; i >= 0; i--)
            heapify(nums, i, size);
        for (int i = size - 1; i > 0; i--)
        {
            swap(nums[0], nums[i]);
            heapify(nums, 0, i);
        }
    }

    void heapSort(vector<int> &nums)
    {
        heapSort(nums, nums.size());
    }

    vector<vector<int>> threeSum(vector<int> &nums)
    {
        heapSort(nums);
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum < -nums[i])
                    left++;
                else if (sum > -nums[i])
                    right--;
                else // sum == -nums[i]
                {
                    ans.push_back({nums[i], nums[left++], nums[right--]});
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                    while (left < right && nums[right] == nums[right + 1])
                        right--;
                }
            }
        }
        return ans;
    }
};