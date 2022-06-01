#include <unordered_set>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  // 哈希表
  ListNode *detectCycle(ListNode *head) {
    std::unordered_set<ListNode *> seen; // 表示已经遍历过的结点
    ListNode *cur = head;
    while (cur) {
      if (seen.count(cur)) { // 表示该结点已经遍历过了
        return cur;
      }
      seen.insert(cur);
      cur = cur->next;
    }

    return nullptr; // 表示链表无环
  }
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution2 {
public:
  // 龟兔赛跑算法
  // 假设链表结点到入环点的节点数为a,龟兔在入环点开始的
  // 第b个结点相遇，环中剩下的结点数为c个,龟兔相遇时
  // 兔子的路程为：a + b + n*(b+c)
  // 乌龟的路程为：a + b
  // 兔子的路程是乌龟的两倍：a + b + n * (b + c) = 2(a + b)
  // -> (n - 1)(b + c) + c = a

  // 龟兔相遇时路程的确定，参考代码随想录题解
  ListNode *detectCycle(ListNode *head) {
    ListNode *rabbit = head;
    ListNode *turtle = head;
    // 判断条件决定了使用do-while循环
    do {
      if (!rabbit || !rabbit->next)
        return nullptr; // 说明没有环
      rabbit = rabbit->next->next;
      turtle = turtle->next;
    } while (rabbit != turtle);

    // 表示有环，此时rabbit和turtle在环中相遇
    // 根据公式(n-1)(b+c)+c = a
    // 定义一个链表头部指针，每次移动一个结点
    // 最终它会和turtle在环入口相遇
    ListNode *temp = head;
    while (temp != turtle) {
      temp = temp->next;
      turtle = turtle->next;
    }

    return turtle; // 此时turtle和temp在入环点相遇
  }
};
