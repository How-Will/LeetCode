#include <iostream>
using namespace std;

class Solution {
public:
  int arrangeCoins(int n) {
    // 等差数列求和公式：前k行所需的硬币数量total = k * (k + 1) / 2

    // case 1: n = 1时，return 1
    // case 2: n > 1时，寻找1个最大的数target，使得target * (target + 1) / 2 <=
    // total
    if (n == 1)
      return 1;

    int left = 1; // 1 <= n，所以起始点为1
    int right = n;

    int res = -1; //保存答案

    while (left <= right) {
      int median = left + ((right - left) / 2);

      if ((long long)median * (median + 1) / 2 > n) {
        right = median - 1;
      } else {
        left = median + 1;
        res = left;
      }
    }

    // 返回的res是真实的res + 1，所以结果要减掉1
    return res - 1;
  }
};

int main() {
  Solution *sol = new Solution();
  int res = sol->arrangeCoins(10);
  cout << "res = " << res << endl;

  return 0;
}
