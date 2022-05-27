struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  // 思路：双指针，一前一后指针遍历数组，因为数组是升序排列的
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr)
      return nullptr; // 空链表，返回空指针

    ListNode *pre = head;
    ListNode *cur = head->next;
    ListNode *temp = nullptr;

    while (cur) {
      if (cur->val == pre->val) {
        temp = cur; // 临时存储重复结点
        cur = cur->next;
        pre->next = cur; // 删除重复结点
        delete temp;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
    return head;
  }
};
