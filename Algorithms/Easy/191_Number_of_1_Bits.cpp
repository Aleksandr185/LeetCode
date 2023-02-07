
#include <stdint.h>
#include <cassert>

/*
  191. Number of 1 Bits

  Write a function that takes an unsigned integer and returns the number of '1' bits it has (also
  known as the Hamming weight).

  Example 1:
          Input: n = 00000000000000000000000000001011
         Output: 3
    Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

  Example 2:
          Input: n = 00000000000000000000000010000000
         Output: 1
    Explanation: The input binary string 00000000000000000000000010000000 has a total of one '1' bit.

  Example 3:
          Input: n = 11111111111111111111111111111101
         Output: 31
    Explanation: The input binary string 11111111111111111111111111111101 has a total of thirty one '1' bits.


  Constraints:
    The input must be a binary string of length 32.

  Follow up:
    If this function is called many times, how would you optimize it?
*/

class Solution {
public:
  int hammingWeight(uint32_t n) {

      constexpr int size = sizeof(uint32_t) * 8;
      uint32_t mask = 1;
      int result = 0;

      for(int i = 0; i < size; ++i) {
        if (n & mask)
          ++result;

        mask = mask << 1;
      }  // for

      return result;

      // Easier and Faster (not my solution)
   /*
      int count = 0;
      while(n != 0) {
        ++count;
        n = n & (n - 1);
      }

      return count;
   */
  }

};

int main(/*int argc, char** argv*/)
{
  Solution s;
  assert( s.hammingWeight(0b00000000000000000000000000001011) ==  3 );
  assert( s.hammingWeight(0b00000000000000000000000010000000) ==  1 );
  assert( s.hammingWeight(0b11111111111111111111111111111101) == 31 );

  return 0;
}

