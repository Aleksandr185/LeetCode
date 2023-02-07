#include <vector>
#include <unordered_map>
#include <cassert>

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that
they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same
element twice.

You can return the answer in any order.

Example 1:
  Input: nums = [2,7,11,15], target = 9
  Output: [0,1]
  Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
  Input: nums = [3,2,4], target = 6
  Output: [1,2]

Example 3:
  Input: nums = [3,3], target = 6
  Output: [0,1]

Constraints:

    2 <= nums.length <= 10^4
    -10^9 <= nums[i] <= 10^9
    -10^9 <= target <= 10^9

Only one valid answer exists.

*/

class Solution {
public:
  std::vector<int> twoSum(const std::vector<int>& nums, int target) {
      std::unordered_map<int, int> map;
      map.reserve(nums.size());
      for (int i = 0; i < nums.size(); ++i) {
        const int value = nums[i];

        std::unordered_map<int, int>::const_iterator search = map.find(value);
        if (search != map.end())
          return std::vector<int>{search->second, i};

        const int difference = target - value;
        map[difference] = i;
      }  // for

      return std::vector<int>();
  }
};



int main(int argc, char** argv)
{
  Solution s;

  {
    // Example 1
    std::vector<int> v = {2, 7, 11, 15};
    auto two_sum = s.twoSum(v, 9);
    assert("Example 1" && two_sum.size() == 2);
    assert("Example 1" &&  ( (two_sum[0] == 0 && two_sum[1] == 1) || (two_sum[0] == 1 && two_sum[1] == 0) ));
  }

  {
    // Example 2
    std::vector<int> v = {3, 2, 4};
    auto two_sum = s.twoSum(v, 6);
    assert("Example 2" && two_sum.size() == 2);
    assert("Example 2" &&  ( (two_sum[0] == 1 && two_sum[1] == 2) || (two_sum[0] == 2 && two_sum[1] == 1) ));
  }

  {
    // Example 3
    std::vector<int> v = {3, 3};
    auto two_sum = s.twoSum(v, 6);
    assert("Example 3" && two_sum.size() == 2);
    assert("Example 3" &&  ( (two_sum[0] == 0 && two_sum[1] == 1) || (two_sum[0] == 1 && two_sum[1] == 0) ));
  }

  return 0;
}
