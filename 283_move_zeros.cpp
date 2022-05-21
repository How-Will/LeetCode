#include <vector>
using namespace std;

class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    // idx，指向待插入位置，初始插入数组为[]
    int idx = 0;
    for (auto num : nums) {
      if (num != 0) {
        nums[idx] = num;
        idx++;
      }
    }

    for (int i = idx; i < nums.size(); i++) {
      nums[i] = 0; // 将剩余元素置为0
    }
  }
};

// 解法2：双指针
class Solution2 {
public:
  void moveZeroes(vector<int> &nums) {
    int left = 0;  // left指向待插入位置
    int right = 0; // right用于遍历数组，找到非0元素

    while (right < nums.size()) {
      if (nums[right] != 0) {
        swap(nums[right], nums[left]); // 交换元素
        left++;
      }
      right++;
    }
  }
};
