#include <vector>
using namespace std;

class Solution {
public:
  // 双指针
  int removeElement(vector<int> &nums, int val) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
      // 找左边等于val的元素
      while (left <= right && nums[left] != val)
        left++;

      // 找右边不等于val的元素
      while (left <= right && nums[right] == val)
        right--;

      // 将右边不等于val的元素覆盖左边等于val的元素
      if (left < right) {
        nums[left] = nums[right];
        left++;
        right--;
      }
    }
    return left; // // left一定指向了最终数组末尾的下一个元素
  }
};

class Solution2 {
public:
  int removeElement(vector<int> &nums, int val) {
    int idx = 0; // 指向待插入位置。idx 初始值为 0
    for (auto x : nums) {
      // 如果当前元素 x 与移除元素 val 相同，那么跳过该元素。
      // 否则将其放到下标 idx 的位置，并让 idx 自增右移。
      // 返回的idx即为答案
      if (x != val) {
        nums[idx++] = x;
      }
    }
    return idx;
  }
};
