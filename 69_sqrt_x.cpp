#include <iostream>
using namespace std;

class Solution {
public:
  int mySqrt(int x) {
    if (x == 0)
      return 0;
    if (x == 1)
      return 1;

    int left = 1;
    int right = x;

    int res = -1;

    // target应该是平方后小于等于x的，如果平方后大于x
    // target及之后的值都不符合条件【二分查找的思路】
    while (left <= right) {
      int median = left + ((right - left) / 2);
      if ((long long)median * median > x) {
        right = median - 1;
      } else if ((long long)median * median <= x) {
        // 继续探究左边是不是有值平方后小于x，但更接近x
        left = median + 1;
        res = left;
      }
    }
    // 返回的res是实际答案 + 1
    return res - 1;
  }
};

int main() {
  Solution *sol = new Solution();
  cout << sol->mySqrt(8) << endl;
  return 0;
}
