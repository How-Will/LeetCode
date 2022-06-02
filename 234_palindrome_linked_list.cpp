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
  // 将链表转换为数组，在通过双指针判断是否为回文链表
  bool isPalindrome(ListNode *head) {
    std::vector<int> ivec;
    while (head) {
      ivec.emplace_back(head->val);
      head = head->next;
    }
    for (int i = 0, j = ivec.size() - 1; i < j; i++, j--) {
      if (ivec[i] != ivec[j]) // 不是回文链表
        return false;
    }

    return true;
  }
};
