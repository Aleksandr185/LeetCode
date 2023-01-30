#include <cassert>

/*
  461. Hamming Distance

  The Hamming distance between two integers is the number of positions at which the corresponding
  bits are different.
  Given two integers x and y, return the Hamming distance between them.

Example 1:
  Input: x = 1, y = 4
  Output: 2
  Explanation:
    1   (0 0 0 1)
    4   (0 1 0 0)
           ↑   ↑
    The above arrows point to positions where the corresponding bits are different.

Example 2:
  Input: x = 3, y = 1
  Output: 1

Constraints:
  0 <= x, y <= 2^31 - 1

*/


class Solution {
public:
    int hammingDistance(int x, int y) {

        x ^= y;
        y = 0;

        unsigned int mask = 1;
        unsigned int invers_mask = ~mask;
        constexpr int size = sizeof(int) * 8;

        for(int i = 0; i < size; ++i) {
          if (x & mask)
            ++y;

          if ( !(x & invers_mask) )
            break;

          mask = mask << 1;
          invers_mask = invers_mask << 1;
        }  // for

        return y;
    }
};

int main(/*int argc, char** argv*/)
{
  Solution s;
  assert( s.hammingDistance(1, 4) == 2 );
  assert( s.hammingDistance(3, 1) == 1 );
  return 0;
}

