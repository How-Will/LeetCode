#include <iostream>
using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
  int guessNumber(int n) {
    int left = 1;
    int right = n;

    while (left <= right) {
      int median = left + ((right - left) / 2); // 猜的数字

      if (guess(median) == 1) {
        left = median + 1;
      } else if (guess(median) == -1) {
        right = median - 1;
      } else {
        return median;
      }
    }

    // 猜的数字不在1~n的范围里
    return -1;
  }
};
