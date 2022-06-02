struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    if (!list1 && !list2) // 当两个链表为空时
      return nullptr;
    if (list1 && !list2) // 当链表2为空时
      return list1;
    if (!list1 && list2) // 当链表1为空时
      return list2;

    ListNode *dummy_head = new ListNode(0, nullptr); // 虚拟头结点，存储有序链表
    ListNode *cur = dummy_head;

    while (list1 && list2) {
      // 比较结点大小，较小的结点加入有序链表
      if (list1->val <= list2->val) {
        cur->next = list1;
        list1 = list1->next; // 后移
      } else if (list1->val >= list2->val) {
        cur->next = list2;
        list2 = list2->next; // 后移
      }
      cur = cur->next;
    }

    if (list1 == nullptr) {
      cur->next = list2;
    } else if (list2 == nullptr) {
      cur->next = list1;
    }

    return dummy_head->next;
  }
};
