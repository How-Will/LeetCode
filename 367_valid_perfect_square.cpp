#include <iostream>
using namespace std;

class Solution {
public:
  bool isPerfectSquare(int num) {
    if (num == 0)
      return true;
    if (num == 1)
      return true;

    // 采用二分查找的思路
    // 从4开始，平方根都不会超过该数的1/2
    // 所以从1~num/2开始寻找target，使得target的平方等于num
    // 没有找到，表示num不是有效完全平方数

    int left = 1;
    int right = num / 2;

    while (left <= right) {
      int median = left + ((right - left) / 2);

      if ((long long)median * median > num) {
        right = median - 1;
      } else if ((long long)median * median < num) {
        left = median + 1;
      } else {
        return true;
      }
    }

    // 没有找到target,使得target的平方等于num
    return false;
  }
};

int main() {
  Solution *sol = new Solution();
  cout << sol->isPerfectSquare(16) << endl;
  return 0;
}
