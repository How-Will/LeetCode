#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int searchInsert(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // target的搜索范围为[left, right]

    while (left <= right) {
      int middle = (right + left) / 2;
      if (nums[middle] > target) {
        // 改变搜索范围 [left, middle - 1]
        right = middle - 1;
      } else if (nums[middle] < target) {
        // 改变搜索范围 [middle + 1, right]
        left = middle + 1;
      } else {
        // 找到了目标
        return middle;
      }
    }
    // target 在数组中，return middle
    // target 不在数组中, 返回插入位置
    // case 1：target 小于数组中的所有数，此时搜索范围：[0,-1]，return right + 1
    // case 2：target 大于数组中的所有数，此时搜索范围：[nums.size(),
    // nums.size()-1], return right + 1 case 3：target
    // 取值介于数组中的最小值与最大值之间，此时搜索范围：[left, right], return
    // right + 1

    return right + 1;
  }
};

int main() {
  vector<int> ivec{1, 3, 5, 6};
  int target = 7;

  Solution *sol = new Solution();

  int res = sol->searchInsert(ivec, target);

  cout << res << endl;

  return 0;
}
