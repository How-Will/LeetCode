#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  int findKthPositive(vector<int> &arr, int k) {
    // 第一个数比缺失的数要大的话，直接返回k
    if (arr[0] > k) {
      return k;
    }

    // 以[2, 3, 4, 7, 11] , k = 5为例
    // 第0个位置应该为1，这里却是2，之前缺失了1个元素==> 2 - 0 - 1 = 1
    // 第1个位置应该为2，这里却是3，之前缺失了1个元素==> 3 - 1 - 1 = 1
    // 第2个位置应该为3，这里却是4，之前缺失了1个元素==> 3 - 2 - 1 = 1
    // 第3个位置应该为4，这里却是7，之前缺失了3个元素==> 7 - 3 - 1 = 3
    // 第4个位置应该为5，这里却是11，之前缺失了6个元素==> 11 - 4 - 1 = 6
    // 故对应的缺失数组[1, 1, 1, 3, 6]
    // 只需要找到小于k，但最接近k的缺失值t对应的数组元素+(k-t),就是对应的答案

    int left = 0;
    int right = arr.size() - 1;

    int res = -1; // 保存结果

    while (left <= right) {
      int middle = left + ((right - left) / 2);

      if (arr[middle] - middle - 1 < k) {
        left = middle + 1;
        res = left;
      } else {
        right = middle - 1;
      }
    }

    return arr[res - 1] + (k - (arr[res - 1] - (res - 1) - 1));
  }
};

int main() {
  vector<int> ivec{1, 3};
  int k = 1;

  Solution *sol = new Solution();
  cout << sol->findKthPositive(ivec, k) << endl;

  return 0;
}
