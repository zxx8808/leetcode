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

```c++
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

#### 解法2

```c++
// Source : https://oj.leetcode.com/problems/add-two-numbers/
// Author : Hao Chen
// Date   : 2014-06-18

/********************************************************************************** 
* 
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
*               
**********************************************************************************/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int x=0, y=0, carry=0, sum=0;
        ListNode *h=NULL, **t=&h;
        
        while (l1!=NULL || l2!=NULL){
            x = getValueAndMoveNext(l1);
            y = getValueAndMoveNext(l2);
            
            sum = carry + x + y;
            
            ListNode *node = new ListNode(sum%10);
            *t = node;
            t = (&node->next);
            
            carry = sum/10;
        }
        
        if (carry > 0) {
            ListNode *node = new ListNode(carry%10);
            *t = node;
        }
        
        return h;
    }
private:
    int getValueAndMoveNext(ListNode* &l){
        int x = 0;
        if (l != NULL){
            x = l->val;
            l = l->next;
        }
        return x;
    }
};
```

#### 解法3

```c++
// Time:  O(n)
// Space: O(1)

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy{0};
        auto curr = &dummy;

        auto carry = 0;
        while (l1 || l2 || carry) {
            auto a = l1? l1->val : 0, b = l2? l2->val : 0;
            auto val = carry + a + b;
            curr->next = new ListNode(val % 10);
            carry = val / 10;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
            curr = curr->next;
        }

        return dummy.next;
    }
};
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
public class Solution {
    // example in leetcode book
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    	ListNode dummyHead = new ListNode(0);
    	ListNode p = l1, q= l2, curr = dummyHead;
    	int carry = 0;
    	while (p != null || q!= null) {
    		int x = (p != null) ? p.val : 0;
    		int y = (q != null) ? q.val : 0;
    		int digit = carry + x + y;
    		carry = digit / 10;
    		curr.next = new ListNode(digit % 10);
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



