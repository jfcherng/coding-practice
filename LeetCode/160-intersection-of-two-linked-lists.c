#include "_leetcode_common.c"

int length(struct ListNode *head) {
  int res = 0;
  for (; head; head = head->next)
    ++res;
  return res;
}

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
  int lenA = length(headA), lenB = length(headB);

  // skip extra leading nodes, which are not possible to be the intersected node
  struct ListNode **longer = lenA > lenB ? &headA : &headB;
  for (int i = abs(lenA - lenB); i > 0; --i)
    (*longer) = (*longer)->next;

  // now headA and headB have the same length
  while (headA != headB) {
    headA = headA->next;
    headB = headB->next;
  }

  return headA;
}

// 把两个链表相同的部分记为c，相交节点记为*, 则第一个链表记为 a * c, 第二个链表记为b * c
// 两个虚拟链表AB, BA可以记为：
// a*cb*c
// b*ca*c
// a, b长度不一定同，但是第二个 * 之前两个链表的长度相同(a+b+*+c)，由此两个虚拟链表走相同步数可以到第二个 * 处
struct ListNode *getIntersectionNode2(struct ListNode *headA, struct ListNode *headB) {
  struct ListNode *pA = headA, *pB = headB;
  while (pA != pB) {
    pA = pA ? pA->next : headB;
    pB = pB ? pB->next : headA;
  }
  return pA;
}

int main(int argc, char *argv[]) {
  return 0;
}
