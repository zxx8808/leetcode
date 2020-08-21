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

```python
# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        carry = 0
        # dummy head
        head = curr = ListNode(0)
        while l1 or l2:
            val = carry
            if l1:
                val += l1.val
                l1 = l1.next
            if l2:
                val += l2.val
                l2 = l2.next
            curr.next = ListNode(val % 10)
            curr = curr.next
            carry = val / 10
        if carry > 0:
            curr.next = ListNode(carry)
        return head.next

if __name__ == '__main__':
    # begin
    s = Solution()
    print(s.addTwoNumbers([3,2,4], [5,4,6]))

```

### C++

#### 解法1

```java
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 /*
    这道题直接模拟就可以了，只要注意进位和链表长度这两点就行
 */

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1,*p2 = l2,*fa;
        int in = 0;
        while(p1 && p2) {
            p1->val += p2->val + in;
            in = 0;
            if(p1->val > 9) {
                p1->val %= 10;
                in=1;
            }
            fa = p1;
            p1 = p1->next;p2 = p2->next;
        }
        if(p2) {
            fa->next=p2;p1=p2;
        }
        while(in) {
            if(p1 == NULL) {
                p1= new ListNode(0);
                fa->next = p1;
            }
            p1->val += in;in = 0;
            if(p1->val > 9) {
                p1->val%=10;
                in = 1;
            }
            fa = p1;p1 = p1->next;
        }
        return l1;
    }
};
```

