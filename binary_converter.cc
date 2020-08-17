/* binary_converter.cc Copyright 2020
*  Written by: Alexus Gore
*
* Converts the decimal number into binary with however
* many number of bits the user wants.
*
*/

#include <cmath>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  // declares the integer values used for the input stream
  int bit_num, decimal_num;
  // delcares the upper and lower bounds for the number of bits
  int upperBit = 31, lowerBit = 1;
  // declares the upper and lower bounds
    // for the number to be converted to binary
  int lower_bound = 0; /*upper_bound = (2^(31)-1), */
  cout << "Enter the number of bits." << endl;
  cin >> bit_num;
  cout << "Enter the number you want converted." << endl;
  cin >> decimal_num; // input stream

  if (bit_num >= lowerBit && bit_num <= upperBit && decimal_num >= 0) {
    for (int i = upperBit-1; i >= 0; --i) {
      // calculates decrementing product of 2^(i)
      int exp_bit = pow(2, i);

      // checks to see if the upperBit is equal to the requested bits
      if (i <= bit_num-1) {  // if less than or equal print the values
          if (exp_bit > decimal_num) {
          // does the math to place a zero if the exp_bit is > decimal_num
            cout << 0;

        } else if (exp_bit <= decimal_num) {
            // does the math to place a 1
            decimal_num = (decimal_num - exp_bit);

            cout << 1;
        } else {
            return 0;
        }
      // else if checks to see if the upperBit is greater than requested bits
    } else if (i > bit_num-1) {  // if greater than it does not print
          if (exp_bit <= decimal_num) {
          // does the math to place a 1 if we were to see it
            decimal_num = (decimal_num - exp_bit);
        } else {
          // does the math to place a zero if we were to see it
              decimal_num = (decimal_num + 0);
        }
      }
    }
} else if (bit_num > upperBit || bit_num < lowerBit) {
    exit(1);
} else if (decimal_num < lower_bound) {
    exit(2);
} else {
    return 0;
}


  return 0;
}
