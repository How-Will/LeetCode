#include <algorithm>
#include <vector>
using namespace std;

// 1. 暴力解法
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
      nums[i] *= nums[i];
    }

    sort(nums.begin(), nums.end());

    return nums;
  }
};

// 2. 双指针
class Solution2 {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    vector<int> res(nums.size(), 0);

    int left = 0;
    int right = nums.size() - 1;
    int res_index = nums.size() - 1; // 用于将数字插入结果数组

    while (left <= right) {
      // 因为是非递减顺序的数组，所以每个数字平方后
      // 的最大值只会出现在原数组的左右两侧

      if (nums[left] * nums[left] > nums[right] * nums[right]) {
        res[res_index] = nums[left] * nums[left];
        left++; // 前指针向后移动
      } else {
        res[res_index] = nums[right] * nums[right];
        right--; // 后指针向前移动
      }
      res_index--;
    }

    return res;
  }
};
