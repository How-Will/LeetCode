class Solution {
public:
  int mySqrt(int x) {
    if (x == 0)
      return 0;

    int left = 1;  // 左边界
    int right = x; // 右边界

    // target应该是平方后小于等于x的，如果平方后大于x
    // 那么target及之后右边的值都不符合条件
    // 【二分查找】：找到第一个小于等于sqrt(x)的值
    while (left <= right) {
      int median = left + ((right - left) / 2);
      if ((long long)median * median <= x) {
        left = median + 1; // left左边的值都小于等于sqrt(x)
      } else {
        right = median - 1; // right右边的值都大于sqrt(x)
      }
    }

    // 应该返回left-1,但是循环终止时,right = left - 1
    // 所以返回right
    return right;
  }
};
