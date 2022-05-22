struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  void deleteNode(ListNode *node) {
    node->val = node->next->val;
    ListNode *tmp = node->next; // 被删除结点
    node->next = node->next->next;
    delete tmp;
  }
};
