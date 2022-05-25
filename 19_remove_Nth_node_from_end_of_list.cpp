struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    // 第一遍遍历取得链表的长度
    int len = getLength(head);
    int rm_index = len - n + 1; // 删除节点的正序位置

    // 第二遍遍历删除节点
    ListNode *dummy_head = new ListNode(0, head); // 虚拟头结点
    ListNode *pre = nullptr, *cur = dummy_head;

    while (rm_index > 0) { // 找到节点并删除
      pre = cur;
      cur = cur->next;
      rm_index--;
    }
    ListNode *temp = cur;
    pre->next = cur->next; // 删除节点
    delete temp;

    return dummy_head->next;
  }

  // 获取链表的长度
  int getLength(ListNode *head) {
    int len = 0;
    ListNode *cur = head;
    while (cur) {
      len++;
      cur = cur->next;
    }
    return len;
  }
};

class Solution2 {
public:
  // 双指针
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dummy_head = new ListNode(0, head);

    ListNode *fast = dummy_head, *slow = dummy_head;
    // 首先移动fast，让fast和slow之间相隔n个元素后停止移动
    for (int i = 0; i < n + 1; i++) {
      fast = fast->next;
    }

    // 然后同步移动slow和fast，直到fast到达nullptr
    while (fast) {
      slow = slow->next;
      fast = fast->next;
    }

    // 此时将slow->next = slow->next->next就得到正解
    slow->next = slow->next->next;

    return dummy_head->next;
  }
};
