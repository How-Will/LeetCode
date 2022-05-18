#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1; // 初始搜索范围[left, right]

    while (left <= right) {
      int middle = left + ((right - left) / 2); // 防止left + right时溢出
      if (nums[middle] < target) {
        // middle左侧的元素都小于target
        // 调整搜索范围[middle + 1, right]
        left = middle + 1;
      } else if (nums[middle] > target) {
        // middle右侧的元素都大于target
        // 调整搜索范围[left, middle - 1]
        right = middle - 1;
      } else {
        // 找到了target，返回下标
        return middle;
      }
    }

    return -1; // 数组中不存在target
  }
};

int main() {
  vector<int> ivec{-1, 0, 3, 5, 9, 12};
  int target = 9;
  Solution *sol = new Solution();

  int res = sol->search(ivec, target);

  cout << "res = " << res << endl;

  return 0;
}
