#include <unordered_set>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    std::unordered_set<ListNode *> seen; // hash表，记录已经访问过的指针地址
    ListNode *cur = head;
    while (cur) {
      if (seen.count(cur)) {
        return true; // 该指针已经出现过了，说明出现了环
      }
      seen.insert(cur);
      cur = cur->next;
    }

    return false; // 说明没有找到环
  }
};

class Solution2 {
public:
  // 龟兔赛跑算法
  bool hasCycle(ListNode *head) {
    if (!head || !head->next)
      return false; //  排除特殊情况，空链表和只有1个结点

    // 不让只有两个结点，无环的时候，rabbit的移动将会报错
    ListNode *dummy_head = new ListNode(0); //虚拟头结点
    dummy_head->next = head;

    ListNode *turtle = dummy_head;
    ListNode *rabbit = head;

    while (turtle != rabbit) {
      if (!rabbit || !rabbit->next) { // 有环
        return false;
      }
      turtle = turtle->next;       // 乌龟移动一步
      rabbit = rabbit->next->next; // 兔子移动两步
    }

    return true; // 有环
  }
};
