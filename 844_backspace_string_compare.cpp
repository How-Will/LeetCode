#include <string>
using namespace std;

class solution {
public:
  bool backspaceCompare(string s, string t) { return build(s) == build(t); }

  // 重构字符串
  string build(string &str) {
    string ret; // 保存重构后的字符串
    for (auto s : str) {
      // 模拟栈
      if (s != '#') {
        ret.push_back(s);
      } else if (!ret.empty()) {
        ret.pop_back();
      }
    }
    return ret;
  }
};

// 解法2
// 一个字符是否会被删掉，只取决于该字符后面的退格符，而与该字符前面的退格符无关。
// 因此当我们逆序地遍历字符串，就可以立即确定当前字符是否会被删掉。

class solution2 {
public:
  bool backspaceCompare(string s, string t) {
    int i = s.length() - 1;
    int j = t.length() - 1;

    // 从后往前遍历字符串s的过程中
    // 1. 遇到字符#, 则skip_s + 1
    // 2. 遇到普通字符，且skip_s > 0, 则skip_s - 1
    // 3. 遇到普通字符，且skip_s == 0, 则不删掉当前字符，和t中的当前字符进行比较
    int skip_s = 0;
    int skip_t = 0;

    while (i >= 0 || j >= 0) {
      while (i >= 0) {
        if (s[i] == '#') {
          skip_s++, i--;
        } else if (skip_s > 0) {
          skip_s--, i--;
        } else {
          break;
        }
      }
      while (j >= 0) {
        if (t[j] == '#') {
          skip_t++, j--;
        } else if (skip_t > 0) {
          skip_t--, j--;
        } else {
          break;
        }
      }
      if (i >= 0 && j >= 0) {
        if (s[i] != t[j]) {
          return false;
        }
      } else {
        if (i >= 0 || j >= 0) {
          return false;
        }
      }
      i--, j--;
    }
    return true;
  }
};
