#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    int first_position = getFirstPosition(nums, target);
    int last_position = getLastPosition(nums, target);

    // case 1: target不存在，且不在数组范围中
    // 大于数组的最大值或小于数组的最小值
    if (first_position == -2 || last_position == -2)
      return {-1, -1};

    // case 2: target存在
    if (last_position - first_position > 1)
      return {first_position + 1, last_position - 1};

    // case 3: target不存在，但在数组范围中
    return {-1, -1};
  }

private:
  // 找到目标范围的第一个位置
  int getFirstPosition(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    // 因为right的取值范围是[-1, nums.size()-1]
    // 而first_position要标记是否能找到目标范围的第一个位置
    // 所以first_position的取值范围不能是[-1, nums.size()-1]
    int first_position = -2;

    while (left <= right) {
      int middle = left + ((right - left) / 2);
      if (nums[middle] >= target) {
        right = middle - 1; // 不断使用二分法，根据right找到第一个位置
        first_position = right;
      } else {
        left = middle + 1;
      }
    }

    // 得到的first_position实际是第一个位置 - 1
    return first_position;
  }

  // 找到目标范围的最后一个位置
  int getLastPosition(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    // 因为left的取值范围是[0, nums.size()]
    // 而last_position要标记是否能找到目标范围的最后一个位置
    // 所以last_position的取值范围不能是[0, nums.size()]
    int last_position = -2;

    while (left <= right) {
      int middle = left + ((right - left) / 2);
      if (nums[middle] <= target) {
        left = middle + 1; // 不断使用二分法，根据left找到最后一个位置
        last_position = left;
      } else {
        right = middle - 1;
      }
    }

    // 得到的last_position实际是最后一个位置 + 1
    return last_position;
  }
};

int main() {
  vector<int> nums{5, 7, 7, 8, 8, 10};
  int target = 8;

  Solution *sol = new Solution();
  vector<int> res = sol->searchRange(nums, target);
  for (auto e : res) {
    cout << e << " ";
  }
  cout << endl;
  return 0;
}
