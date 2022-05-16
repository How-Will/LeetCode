#include <iostream>
using namespace std;

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  // 题目的原意是从数组中找出等于target的数
  int firstBadVersion(int n) {
    int left = 1;
    int right = n;

    int res = -2; // 保存结果

    while (left <= right) {
      int median = left + ((right - left) / 2);

      // 当median < target时，isBadVersion(median)返回false
      // 当median >= target时，isBadVersion(median)返回true
      if (isBadVersion(median) == false) {
        left = median + 1;
      } else {
        right = median - 1;
        res = right; // res会返回第一个小于target的数
      }
    }
    if (res == -2)
      return -1; // 说明没有错误版本
    return right + 1;
  }
};
