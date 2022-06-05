struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    // 因为头节点有可能发生变化，使用虚拟头节点可以避免复杂的分类讨论
    ListNode *dummy_head = new ListNode(-1, head);

    ListNode *pre = dummy_head;
    // 第 1 步：从虚拟头节点走 left - 1 步，来到 left 节点的前一个节点
    for (int i = 0; i < left - 1; i++) {
      pre = pre->next;
    }

    // 第 2 步：从 pre 再走 right - left + 1 步，来到 right 节点
    ListNode *rightNode = pre;
    for (int i = 0; i < right - left + 1; i++) {
      rightNode = rightNode->next;
    }

    // 第 3 步：切断出一个子链表（截取链表）
    ListNode *leftNode = pre->next;
    ListNode *curr = rightNode->next;

    // 注意：切断链接
    pre->next = nullptr;
    rightNode->next = nullptr;

    // 第 4 步：同第 206 题，反转链表的子区间
    reverseList(leftNode);

    // 第 5 步：接回到原来的链表中
    pre->next = rightNode;
    leftNode->next = curr;

    return dummy_head->next;
  }

  void reverseList(ListNode *head) {
    ListNode *pre = nullptr;
    ListNode *cur = head;

    ListNode *temp = nullptr;
    while (cur) {
      temp = cur->next; // 防止反转过程中链表中断

      cur->next = pre; // 反转链表

      pre = cur;
      cur = temp;
    }
  }
};
