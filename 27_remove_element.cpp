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
