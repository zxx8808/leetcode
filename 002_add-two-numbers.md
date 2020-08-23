## [2. 两数相加](https://leetcode-cn.com/problems/add-two-numbers/)

给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

> 示例：
>
> 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
> 输出：7 -> 0 -> 8
> 原因：342 + 465 = 807



### Python

#### 解法1

```python
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        dummy = p = ListNode(None)
        s = 0
        while l1 or l2 or s:
            s += (l1.val if l1 else 0) + (l2.val if l2 else 0)
            p.next = ListNode(s % 10)
            p = p.next
            s //= 10
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        return dummy.next
```

### Java

#### 解法1

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */

class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode dummyHead = new ListNode(0);
        ListNode p = l1, q = l2, curr = dummyHead;
        int carry = 0;
        while (p != null || q != null) {
            int x = (p != null) ? p.val : 0;
            int y = (q != null) ? q.val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr.next = new ListNode(sum % 10);
            curr = curr.next;
            if (p != null) p = p.next;
            if (q != null) q = q.next;
        }
        if (carry > 0) {
            curr.next = new ListNode(carry);
        }
        return dummyHead.next;
    }
}
```

### C++

#### 解法1

**整体思路：**
将长度较短的链表在末尾补零使得两个连表长度相等，再一个一个元素对其相加（考虑进位）

**具体步骤：**
获取两个链表所对应的长度
在较短的链表末尾补零
对齐相加考虑进位

```c++
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int len1 = 1;  //记录l1的长度
        int len2 = 1;  //记录l2的长度
        ListNode *p = l1;
        ListNode *q = l2;
        while (p->next != NULL)  //获取l1的长度
        {
            len1++;
            p = p->next;
        }
        while (q->next != NULL)  //获取l2的长度
        {
            len2++;
            q = q->next;
        }
        if (len1 > len2)  // l1较长，在l2末尾补零
        {
            for (int i = 1; i <= len1 - len2; i++) {
                q->next = new ListNode(0);
                q = q->next;
            }
        } else  // l2较长，在l1末尾补零
        {
            for (int i = 1; i <= len2 - len1; i++) {
                p->next = new ListNode(0);
                p = p->next;
            }
        }
        p = l1;
        q = l2;
        bool count = false;               //记录进位
        ListNode *l3 = new ListNode(-1);  //存放结果的链表
        ListNode *w = l3;                 // l3的移动指针
        int i = 0;                        //记录相加结果
        while (p != NULL && q != NULL) {
            i = count + p->val + q->val;
            w->next = new ListNode(i % 10);
            count = i >= 10 ? true : false;
            w = w->next;
            p = p->next;
            q = q->next;
        }
        if (count)  //若最后还有进位
        {
            w->next = new ListNode(1);
            w = w->next;
        }
        return l3->next;
    }
};
```

#### 解法2

**整体思路：**

不对齐补零，若链表不为空则用sum(代表每个位的和的结果)加上，考虑进位。

```c++
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *head = new ListNode(-1);  //存放结果的链表
        ListNode *h = head;                 //移动指针
        int sum = 0;                        //每个位的加和结果
        bool carry = false;                 //进位标志
        while (l1 != NULL || l2 != NULL) {
            sum = 0;
            if (l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            if (carry)
                sum++;
            h->next = new ListNode(sum % 10);
            h = h->next;
            carry = sum >= 10 ? true : false;
        }
        if (carry) {
            h->next = new ListNode(1);
        }
        return head->next;
    }
};
```

### C语言

```c
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *addTwoNumbers(struct ListNode *l1, struct ListNode *l2)
{
    int x, y, num, flag = 0;
    struct ListNode *p = l1, *q = l2;
    struct ListNode *cur = (struct ListNode *)malloc(sizeof(struct ListNode));
    cur->next = NULL;
    struct ListNode *ret = cur;
    while (p != NULL || q != NULL) {
        x = (p != NULL) ? p->val : 0;
        y = (q != NULL) ? q->val : 0;
        num = x + y + flag;
        flag = num / 10;
        cur->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = num % 10;
        cur->next = NULL;
        if (p != NULL)
            p = p->next;
        if (q != NULL)
            q = q->next;
    }
    if (flag > 0) {
        cur->next = (struct ListNode *)malloc(sizeof(struct ListNode));
        cur = cur->next;
        cur->val = 1;
        cur->next = NULL;
    }
    return ret->next;
}
```



