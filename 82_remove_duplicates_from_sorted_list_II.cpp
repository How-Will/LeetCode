struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == nullptr)
      return nullptr;

    ListNode *dummy_head = new ListNode(-101, head); // 虚拟头结点

    // 双指针，遍历链表，寻找重复结点
    ListNode *pre = dummy_head;
    ListNode *cur = head;

    while (cur) {
      // 跳过重复结点，使得cur指向当前重复元素的最后一个位置
      while (cur->next && cur->val == cur->next->val)
        cur = cur->next;

      if (pre->next == cur) {
        pre = cur; // pre和cur之间没有重复元素，pre后移
      } else {
        pre->next = cur->next; // 跳过重复的元素
      }
      cur = cur->next;
    }

    return dummy_head->next;
  }
};

// 参考题解负雪明烛
class Solution2 {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !head->next) {
      return head;
    }
    if (head->val != head->next->val) {
      head->next = deleteDuplicates(head->next);
    } else {
      ListNode *move = head->next;
      while (move && head->val == move->val) {
        move = move->next;
      }
      return deleteDuplicates(move);
    }
    return head;
  }
};
