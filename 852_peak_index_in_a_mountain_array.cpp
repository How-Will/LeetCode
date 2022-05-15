#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  // i_ans 表示答案下标
  // 当i < i_ans时，arr[i] < arr[i + 1]恒成立
  // 当i > i_ans时，arr[i] > arr[i + 1]恒成立
  // 所以i_ans即为使得arr[i] < arr[i + 1]恒成立的最小下标i
  int peakIndexInMountainArray(vector<int> &arr) {
    int left = 0;
    int right = arr.size() - 1;

    int res = -2; //保存结果

    while (left <= right) {
      int middle = left + ((right - left) / 2);

      // note: 用right找最小，left找最大
      if (arr[middle] < arr[middle + 1]) {
        left = middle + 1;
      } else {
        right = middle - 1;
        res = right;
      }
    }

    // 返回的res是实际的res - 1，所以要加1返回
    return res + 1;
  }
};

int main() {
  Solution *sol = new Solution();
  vector<int> ivec{0, 10, 5, 2};

  int res = sol->peakIndexInMountainArray(ivec);

  cout << res << endl;

  return 0;
}
