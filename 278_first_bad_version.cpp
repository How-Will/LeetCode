// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
  int firstBadVersion(int n) {
    // 【二分查找】：找到第一个大于等于target的数字
    int left = 1;
    int right = n;

    // 当median < target时，isBadVersion(median)返回false
    // 当median >= target时，isBadVersion(median)返回true

    while (left <= right) {
      int median = left + ((right - left) / 2);
      if (isBadVersion(median) == false) {
        left = median + 1; // left及left左边的值都大于等于target
      } else {
        right = median - 1; // right右边的值都小于target
      }
    }

    return left;
  }
};
