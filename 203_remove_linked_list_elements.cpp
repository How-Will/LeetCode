// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeElements(ListNode *head, int val) {
    ListNode *dummy_head = new ListNode(0); // 虚拟头节点
    dummy_head->next = head; // 将虚拟头结点指向head，统一删除操作
    ListNode *cur = dummy_head;

    while (cur->next != nullptr) {
      // 遍历链表
      if (cur->next->val == val) {
        ListNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp; // 释放被删除结点的内存
      } else {
        cur = cur->next;
      }
    }

    head = dummy_head->next;
    delete dummy_head;
    return head;
  }
};
