#include <vector>
#include <algorithm>
#include <cassert>

#include <iostream>

/*
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

Example 1:
    Input: nums = [-1,0,1,2,-1,-4]
    Output: [[-1,-1,2],[-1,0,1]]
    Explanation:
        nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
        nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
        nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
        The distinct triplets are [-1,0,1] and [-1,-1,2].
        Notice that the order of the output and the order of the triplets does not matter.

Example 2:
    Input: nums = [0,1,1]
    Output: []
    Explanation:
        The only possible triplet does not sum up to 0.

Example 3:
    Input: nums = [0,0,0]
    Output: [[0,0,0]]
    Explanation:
        The only possible triplet sums up to 0.

Constraints:

    3 <= nums.length <= 3000
    -10^5 <= nums[i] <= 10^5

*/

class Solution {
public:
  std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
    std::vector<std::vector<int>> result;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; ++i) {
      const int value_i = nums[i];

      if (value_i > 0)
        break;

      if (i > 0 && value_i == nums[i - 1])
        continue;

      int left = i + 1;
      int right = nums.size() - 1;

      while (left < right) {
        const int value_j = nums[left];

        if ((i != left - 1) && value_j == nums[left - 1]) {
          ++left;
          continue;
        }

        const int value_k = nums[right];

        if (std::abs(value_i + value_j) < value_k) {
          --right;
          continue;
        }

        if ( (value_i + value_j + value_k) == 0) {
          result.push_back(std::vector<int>{value_i, value_j, value_k});
        }

        ++left;
      } // while
    }  // for i

    return result;
  }
};

int main(int argc, char** argv)
{
  Solution s;

  {
    // Example 1
    std::vector<int> v = {-1, 0, 1, 2, -1, -4};
    auto three_sum = s.threeSum(v);
    assert("Example 1" && three_sum.size() == 2);
    assert("Example 1" &&  (three_sum[0].size() == 3));
    assert("Example 1" &&  (three_sum[1].size() == 3));
    assert("Example 1" && (three_sum[0][0] + three_sum[0][1] + three_sum[0][2] == 0) );
    assert("Example 1" && (three_sum[1][0] + three_sum[1][1] + three_sum[1][2] == 0) );
  }

  {
    // Example 2
    std::vector<int> v = {0, 1, 1};
    assert("Example 2" && s.threeSum(v).empty());
  }

  {
    // Example 3
    std::vector<int> v = {0, 0, 0};
    auto three_sum = s.threeSum(v);
    assert("Example 3" && three_sum.size() == 1);
    assert("Example 3" &&  (three_sum[0].size() == 3));
    assert("Example 3" && (three_sum[0][0] + three_sum[0][1] + three_sum[0][2] == 0) );
  }

  {
    // Example 4
    std::vector<int> v = {-4,-2,-2,-2,0,1,2,2,2,3,3,4,4,6,6};
    auto three_sum = s.threeSum(v);
    assert("Example 4" && three_sum.size() == 6);
  }


  {
    // Example 5
    std::vector<int> v = {-1,0,1,2,-1,-4,-2,-3,3,0,4};
    auto three_sum = s.threeSum(v);
    assert("Example 5" && three_sum.size() == 9);
  }

  return 0;
}
