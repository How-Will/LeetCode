#include <stack>
#include <vector>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  std::vector<int> nextLargerNodes(ListNode *head) {
    if (!head->next)
      return {0}; // 只有1个结点的链表

    std::vector<int> res; // 存储结果
    ListNode *cur = head;
    ListNode *scan = nullptr; // 以该指针向前搜索第一个大于当前结点的结点

    while (cur) {
      scan = cur->next;
      while (scan) {
        if (scan->val > cur->val) {
          res.push_back(scan->val);
          break;
        }
        scan = scan->next; // 指针前移，搜索
      }
      if (!scan) // 表示没有找到比当前结点大的结点
        res.push_back(0);
      cur = cur->next;
    }

    return res;
  }
};

// 参考花花酱题解
class Solution2 {
public:
  std::vector<int> nextLargerNodes(ListNode *head) {
    std::vector<int> nums;

    while (head) {
      nums.push_back(head->val);
      head = head->next;
    }

    std::stack<int> s;                           // 单调栈
    std::vector<int> res(nums.size());           // 存储结果
    for (int i = nums.size() - 1; i >= 0; i--) { // 从右到左遍历
      while (!s.empty() && s.top() <= nums[i])
        s.pop(); // 如果当前元素>栈顶元素，这栈顶元素也不会是之后元素的答案，pop掉
      res[i] = s.empty() ? 0 : s.top();
      s.push(nums[i]);
    }

    return res;
  }
};
