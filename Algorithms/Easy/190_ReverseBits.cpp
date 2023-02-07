
#include <stdint.h>
#include <cassert>

/*
  190. Reverse Bits

      Reverse bits of a given 32 bits unsigned integer.

  Note:
    Note that in some languages, such as Java, there is no unsigned integer type. In this case,
    both input and output will be given as a signed integer type. They should not affect your
    implementation, as the integer's internal binary representation is the same, whether it is
    signed or unsigned.
    In Java, the compiler represents the signed integers using 2's complement notation. Therefore,
    in Example 2 above, the input represents the signed integer -3 and the output represents the
    signed integer -1073741825.


  Example 1:
    Input:            n = 00000010100101000001111010011100
    Output:   964176192 = 00111001011110000010100101000000
    Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned
                 integer 43261596, so return 964176192 which its binary representation
                 is 00111001011110000010100101000000.

  Example 2:
    Input:             n = 11111111111111111111111111111101
    Output:   3221225471 = 10111111111111111111111111111111
    Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned
                 integer 4294967293, so return 3221225471 which its binary representation
                 is 10111111111111111111111111111111.


  Constraints:
    The input must be a binary string of length 32

  Follow up:
    If this function is called many times, how would you optimize it?
*/

class Solution {
public:
  /*
            ->
   mask_a: 0b10000000000000000000000000000000
             ^
           bit_a

                                            <-
   mask_b: 0b00000000000000000000000000000001
                                            ^
                                          bit_b
*/

  uint32_t reverseBits(uint32_t n) {
      uint32_t mask_a = 1 << 31;
      uint32_t mask_b = 1 << 0;
      for (int i = 0; i < 32/2; ++i) {
          const bool bit_a_is_set = (n & mask_a) > 0;
          const bool bit_b_is_set = (n & mask_b) > 0;

          if (bit_a_is_set != bit_b_is_set) {
              n ^= mask_a;  // invers bit_a
              n ^= mask_b;  // invers bit_b
          }

          mask_a = mask_a >> 1;
          mask_b = mask_b << 1;
      } // for

      return n;
  }
};

int main(/*int argc, char** argv*/)
{
  Solution s;
  assert( s.reverseBits(0b00000010100101000001111010011100) ==  0b00111001011110000010100101000000 );
  assert( s.reverseBits(0b11111111111111111111111111111101) ==  0b10111111111111111111111111111111 );

  return 0;
}

