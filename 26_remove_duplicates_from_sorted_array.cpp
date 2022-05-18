#include <vector>
using namespace std;

class Solution {
public:
  // 一个指针 right 进行数组遍历，另外一个指针 left 指向有效数组的最后一个位置。
  // 只有当 right 所指向的值和 left 不一致（不重复），才将 right 的值添加到 left
  // 的下一位置。
  int removeDuplicates(vector<int> &nums) {
    // 判断特殊情况
    if (nums.size() == 0)
      return 0;

    int left = 0;
    for (int right = left + 1; right < nums.size(); right++) {
      if (nums[right] != nums[left]) {
        nums[++left] = nums[right];
      }
    }

    return left + 1;
  }
};

// 参考：宫水三叶题解
class GeneralSolution {
public:
  int removeDuplicates(vector<int> &nums) { return process(nums, 1); }

  int process(vector<int> &nums, int k) {
    //设定变量 idx，指向待插入位置。idx 初始值为0,目标数组为[]
    int idx = 0;
    for (auto x : nums) {
      if (idx < k || nums[idx - k] != x) {
        nums[idx++] = x;
      }
    }
    return idx;
  }
};
