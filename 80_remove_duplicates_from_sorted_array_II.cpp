#include <vector>
using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int> &nums) { return process(nums, 2); }

  int process(vector<int> &nums, int k) {
    int idx = 0; // 指向插入位置
    for (auto x : nums) {
      // 前k个元素，可以直接保留
      // 因为数组的前提是有序的，nums[idx - k] != x
      // 其实就是一个大小为2的窗口，不断移动，去找到符合条件的数
      if (idx < k || nums[idx - k] != x) {
        nums[idx++] = x;
      }
    }
    return idx;
  }
};
