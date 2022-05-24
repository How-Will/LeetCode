// 结点类
class Listnode {
public:
  Listnode() : val(0), next(nullptr) {}
  Listnode(int v) : val(v), next(nullptr) {}
  Listnode(int v, struct Listnode *x) : val(v), next(x) {}

  int val;
  struct Listnode *next;
};

class MyLinkedList {
public:
  MyLinkedList() {
    m_dummy_head =
        new Listnode(0); // 这是一个虚拟头结点，而不是真正的链表头结点
    m_size = 0;
  }

  int get(int index) {
    if (index > m_size - 1 || index < 0) {
      return -1;
    }
    Listnode *cur = m_dummy_head->next;
    while (index) {
      cur = cur->next; // 遍历到第index个结点
      index--;
    }
    return cur->val;
  }

  void addAtHead(int val) {
    Listnode *node = new Listnode(val); // 创建待插入结点
    node->next = m_dummy_head->next;
    m_dummy_head->next = node;
    m_size++;
  }

  void addAtTail(int val) {
    Listnode *node = new Listnode(val); // 创建待插入结点

    Listnode *cur = m_dummy_head; // 可能是空链表，此时插入尾部等于插入头部
    while (cur->next) {
      cur = cur->next; // 遍历得到尾部结点
    }
    cur->next = node;
    m_size++;
  }

  void addAtIndex(int index, int val) {
    if (index > m_size)
      return;
    Listnode *node = new Listnode(val); // 创建待插入结点

    Listnode *cur = m_dummy_head;
    // index < 0 时，不进入循环，直接在虚拟头结点后面插入
    while (index) {
      cur = cur->next;
      index--;
    }

    node->next = cur->next;
    cur->next = node;
    m_size++;
  }

  void deleteAtIndex(int index) {
    if (index > m_size - 1 || index < 0) { // index无效
      return;
    }
    Listnode *cur = m_dummy_head;
    while (index--) {
      cur = cur->next;
    }
    Listnode *tmp = cur->next;
    cur->next = cur->next->next;
    delete tmp;
    m_size--;
  }

private:
  int m_size;
  Listnode *m_dummy_head;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
