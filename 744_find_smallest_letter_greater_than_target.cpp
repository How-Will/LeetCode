#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    // 如果letters中的所有元素都大于target，返回letters[0]
    if (target >= letters.back())
      return letters[0];

    int left = 0;
    int right = letters.size() - 1;

    while (left <= right) {
      // 每次比较当前下标的字母和target
      // letters[middle] < target, 修改搜索范围为[middle + 1, right]
      // letters[middle] > target, 修改搜索范围为[left, middle - 1]
      // letters[middle] == target, 因为题目要找的是比target大的最小字母，故
      // 移动left，修改搜索范围为[middle + 1, right]
      int middle = left + ((right - left) / 2);

      if (letters[middle] <= target) {
        left = middle + 1;
      } else {
        right = middle - 1;
      }
    }

    return letters[left];
  }
};

int main() {
  vector<char> letters{'c', 'f', 'j'};
  char target = 'd';

  Solution *sol = new Solution();

  cout << sol->nextGreatestLetter(letters, target) << endl;

  return 0;
}
