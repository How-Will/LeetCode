struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverseList(ListNode *head) {
    // 定义双指针
    ListNode *cur = head;
    ListNode *pre = nullptr;
    ListNode *node = nullptr; // 保存cur的下一个结点

    while (cur) { // 指针后移
      // 保存一下 cur的下一个节点，因为接下来要改变cur->next
      node = cur->next;

      cur->next = pre; // 指针反转

      pre = cur;
      cur = node;
    }
    // 退出迭代时，cur=nullptr, pre指向最后一个结点（目前的头结点）
    return pre;
  }
};

// 参考王尼玛递归图示
class Solution2 {
public:
  // 递归法
  ListNode *reverseList(ListNode *head) {
    // 边缘条件判断
    if (head == nullptr)
      return nullptr;
    if (head->next == nullptr)
      return head;

    // 递归调用，反转第二个结点开始往后的链表
    ListNode *last = reverseList(head->next);

    head->next->next = head;
    head->next = nullptr; // 为了防止循环指向
    return last;
  }
};
