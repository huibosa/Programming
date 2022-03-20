#include <iostream>
#include <memory>

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *mergeTwoLists1(ListNode *l1, ListNode *l2) {
    auto dummy = new ListNode(-1);
    auto prev = dummy;

    while (l1 != nullptr && l2 != nullptr) {
      if (l1->val < l2->val) {
        prev->next = l1;
        l1 = l1->next;
      } else {
        prev->next = l2;
        l2 = l2->next;
      }
      prev = prev->next;
    }

    prev->next = (l1 != nullptr ? l1 : l2);
    return dummy->next;
  }

  ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
    /* return (l1 == nullptr ? l2 : l1); */

    if (l1 == nullptr) {
      return l2;
    } else if (l2 == nullptr) {
      return l1;
    }

    if (l1->val < l2->val) {
      auto temp1 = l1->next;
      auto temp2 = l2->next;

      l1->next = l2;
      l2->next = mergeTwoLists2(temp1, temp2);
      return l1;
    } else {
      auto temp1 = l1->next;
      auto temp2 = l2->next;

      l2->next = l1;
      l1->next = mergeTwoLists2(temp1, temp2);
      return l2;
    }
  }

  ListNode *mergeTwoLists3(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr) {
      return l2;
    } else if (l2 == nullptr) {
      return l1;
    }

    if (l1->val < l2->val) {
      l1->next = mergeTwoLists3(l1->next, l2);
      return l1;
    } else {
      l2->next = mergeTwoLists3(l1, l2->next);
      return l2;
    }
  }
};

int main() {
  auto l1 = new ListNode(1);
  auto p2 = new ListNode(2);
  auto p3 = new ListNode(4);
  p2->next = p3;
  l1->next = p2;

  auto cur = l1;
  while (cur != nullptr) {
    std::cout << cur->val << " ";
    cur = cur->next;
  }
  std::cout << "\n";

  auto l2 = new ListNode(1);
  auto q2 = new ListNode(3);
  auto q3 = new ListNode(4);
  q2->next = q3;
  l2->next = q2;

  cur = l2;
  while (cur != nullptr) {
    std::cout << cur->val << " ";
    cur = cur->next;
  }
  std::cout << "\n";

  Solution sln;
  auto pnew = sln.mergeTwoLists2(l1, l2);

  while (pnew != nullptr) {
    std::cout << pnew->val << " ";
    pnew = pnew->next;
  }
  std::cout << "\n";

  delete pnew;

  return 0;
}
