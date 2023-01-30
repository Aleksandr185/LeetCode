
#include <vector>
#include <algorithm>
#include <cassert>

/*
  453. Minimum Moves to Equal Array Elements

  Given an integer array nums of size n, return the minimum number of moves required to make all
  array elements equal.
  In one move, you can increment n - 1 elements of the array by 1.

  Example 1:
          Input: nums = [1,2,3]
         Output: 3
    Explanation: Only three moves are needed (remember each move increments two elements):
                 [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]

  Example 2:
         Input: nums = [1,1,1]
        Output: 0

  Constraints:
    n == nums.length
    1 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9

  The answer is guaranteed to fit in a 32-bit integer.
*/


class Solution {
public:
  int minMoves(std::vector<int>& nums) {
    if (nums.empty())
      return 0;

    const int min_element = *( std::min_element(nums.begin(), nums.end()) );

    int moves = 0;
    for(size_t i = 0; i < nums.size(); ++i) {
      moves += nums[i] - min_element;
    }

    return moves;
  }

};

int main(/*int argc, char** argv*/)
{
  Solution s;

  {
    std::vector<int> v = {1, 2, 3};
    assert( s.minMoves(v) == 3 );
  }

  {
    std::vector<int> v = {1, 1, 1};
    assert( s.minMoves(v) == 0 );
  }

  {
    std::vector<int> v = {1, 1000000000};
    assert( s.minMoves(v) == 999999999 );
  }

  {
    std::vector<int> v = {1, 1, 1000000000};
    assert( s.minMoves(v) == 999999999 );
  }

  return 0;
}

