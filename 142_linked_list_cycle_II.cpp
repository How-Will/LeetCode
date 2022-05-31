#include <unordered_set>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  // 哈希表
  ListNode *detectCycle(ListNode *head) {
    std::unordered_set<ListNode *> seen; // 表示已经遍历过的结点
    ListNode *cur = head;
    while (cur) {
      if (seen.count(cur)) { // 表示该结点已经遍历过了
        return cur;
      }
      seen.insert(cur);
      cur = cur->next;
    }

    return nullptr; // 表示链表无环
  }
};
