struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  // 如果两个链表相交，那么相交点之后的长度是相同的
  // 思路：让两个链表从同距离末尾同等距离的位置开始遍历[消除长度差]
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // 双指针：参考Krahets题解
    ListNode *p_a = headA;
    ListNode *p_b = headB;

    while (p_a != p_b) {
      p_a = (p_a != nullptr ? p_a->next : headB);
      p_b = (p_b != nullptr ? p_b->next : headA);
    }
    return p_a;
  }
};

class Solution2 {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *p_a = headA;
    ListNode *p_b = headB;

    align(p_a, p_b); // 对齐指针

    while (p_a) {
      if (p_a == p_b) // 得到了相交结点
        return p_a;
      p_a = p_a->next;
      p_b = p_b->next;
    }
    return nullptr; // 没有相交结点
  }

  // 获取链表长度
  int getLen(ListNode *head) {
    int len = 0;
    ListNode *cur = head;
    while (cur) {
      len++; // 长度加1
      cur = cur->next;
    }

    return len;
  }

  // 指针对齐
  void align(ListNode *&p1, ListNode *&p2) {
    int len1 = getLen(p1);
    int len2 = getLen(p2);

    int dist = abs(len1 - len2); // 两个链表之间的结点差
    while (dist > 0) {
      if (len1 > len2)
        p1 = p1->next;
      else
        p2 = p2->next;
      dist--;
    }
  }
};
