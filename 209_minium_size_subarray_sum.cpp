#include <cstdint>
#include <vector>
using namespace std;

class Solution {
public:
  // 暴力遍历
  int minSubArrayLen(int target, vector<int> &nums) {
    int res = INT32_MAX;                    // 最终的结果
    int sum = 0;                            // 子序列的数值之和
    int sub_length = 0;                     // 子序列的长度
    for (int i = 0; i < nums.size(); i++) { // 设置子序列的起点为i
      sum = 0;
      for (int j = i; j < nums.size(); j++) { // 设置子序列的终点为j
        sum += nums[j];
        if (sum >= target) {
          // 一旦发现子序列和超过了target，更新result
          sub_length = j - i + 1; // 子序列的长度
          res = res < sub_length ? res : sub_length;
          // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
          break;
        }
      }
    }

    // 因为我们是找符合条件最短的子序列，所以一旦符合条件就break
    return res == INT32_MAX ? 0 : res;
  }
};

// 滑动窗口
class Solution2 {
public:
  int minSubArrayLen(int target, vector<int> &nums) {
    int res = INT32_MAX; // 结果
    int sum = 0;
    int i = 0;          // 滑动窗口起始位置
    int sub_length = 0; // 滑动窗口的长度
    for (int j = 0; j < nums.size(); j++) {
      sum += nums[j];

      while (sum >= target) {
        sub_length = (j - i + 1); // 取得子序列的长度
        res = res < sub_length ? res : sub_length;
        // 这里体现出滑动窗口的精髓之处，不断变更i（子序列的起始位置）
        sum -= nums[i];
        i += 1;
      }
    }

    // 如果res没有被赋值，就返回0，说明没有符合条件的子序列
    return res == INT32_MAX ? 0 : res;
  }
};
