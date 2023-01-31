
#include <vector>
#include <algorithm>
#include <cassert>


/*
  462. Minimum Moves to Equal Array Elements II

  Given an integer array nums of size n, return the minimum number of moves required to make all
  array elements equal.
  In one move, you can increment or decrement an element of the array by 1.
  Test cases are designed so that the answer will fit in a 32-bit integer.

Example 1:
  Input: nums = [1,2,3]
  Output: 2
  Explanation:
  Only two moves are needed (remember each move increments or decrements one element):
  [1,2,3]  =>  [2,2,3]  =>  [2,2,2]

Example 2:
  Input: nums = [1,10,2,9]
  Output: 16

Constraints:
  n == nums.length
  1 <= nums.length <= 10^5
  -10^9 <= nums[i] <= 10^9
*/


class Solution {
public:
  int minMoves2(std::vector<int>& nums) {
    if (nums.empty())
      return 0;

    std::sort(nums.begin(), nums.end());

    int moves = 0;
    auto left = nums.begin();
    auto right = nums.end() - 1;

    while (left < right) {
      moves += *right - *left;
      ++left;
      --right;
    }

    return moves;
  }

};

int main(/*int argc, char** argv*/)
{
  Solution s;
  {
    std::vector<int> v = {1, 2, 3};
    assert( s.minMoves2(v) == 2 );
  }

  {
    std::vector<int> v = {1, 10, 2, 9};
    assert( s.minMoves2(v) == 16 );
  }

  {
    std::vector<int> v = {1, 0, 0, 8, 6};
    assert( s.minMoves2(v) == 14 );
  }

  return 0;
}

