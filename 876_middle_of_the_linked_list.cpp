struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 朴素解法
class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    if (!head || !head->next) {
      return head; // 特殊情况处理
    }

    ListNode *cur = head;
    int len = getLen(head);
    int res_index = len / 2 + 1; // 返回结点的位置
    while (res_index > 1) { // 因为要返回的序列中，包含中间结点，所以>1
      cur = cur->next;
      res_index--;
    }

    return cur;
  }

  // 获取链表的长度
  int getLen(ListNode *head) {
    int len = 0;
    ListNode *cur = head;
    while (cur) {
      len++;
      cur = cur->next;
    }

    return len;
  }
};
