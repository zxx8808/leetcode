### [1. 两数之和](https://leetcode-cn.com/problems/two-sum/)

给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

**示例:**

> 给定 nums = [2, 7, 11, 15], target = 9
>
> 因为 nums[0] + nums[1] = 2 + 7 = 9
> 所以返回 [0, 1]



### Python

#### 解法1

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # n^2
        ls = len(nums)
        for i in range(ls):
            for j in range(i + 1, ls):
                if nums[i] + nums[j] == target:
                    return [i, j]


if __name__ == '__main__':
    # begin
    s = Solution()
    print(s.twoSum([3, 2, 4], 6))
```

#### 解法2

```python
class Solution(object):
    def twoSum(self, nums, target):
        mapping = {}

        for index, val in enumerate(nums):
            diff = target - val
            if diff in mapping:
                return [index, mapping[diff]]
            else:
                mapping[val] = index


if __name__ == '__main__':
    # begin
    s = Solution()
    print(s.twoSum([3, 2, 4], 6))
```

#### 解法3

```python
class Solution(object):
    def twoSum(self, nums, target):
        # two point
        nums_index = [(v, index) for index, v in enumerate(nums)]
        nums_index.sort() // 这里实际上是字典比较大小吧？
        begin, end = 0, len(nums) - 1
        while begin < end:
            curr = nums_index[begin][0] + nums_index[end][0]
            if curr == target:
                return [nums_index[begin][1], nums_index[end][1]]
            elif curr < target:
                begin += 1
            else:
                end -= 1


if __name__ == '__main__':
    # begin
    s = Solution()
    print(s.twoSum([3, 2, 4], 6))
```

### Java

#### 解法1

```java
import java.util.HashMap;

/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
public class Solution1 {

    public int[] twoSum(int[] nums, int target) {

        for (int i = 0; i < nums.length; i++)
            for (int j = i + 1; j < nums.length; j++)
                if (nums[i] + nums[j] == target) {
                    int[] res = { i, j };
                    return res;
                }

        throw new IllegalStateException("the input has no solution");
    }

    private static void printArr(int[] nums) {
        for (int num : nums)
            System.out.print(num + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        int[] nums = { 0, 4, 3, 0 };
        int target = 0;
        printArr((new Solution1()).twoSum(nums, target));
    }
}
```

#### 解法2

```java
import java.util.HashMap;

/// Two-Pass Hash Table
/// Time Complexity: O(n)
/// Space Complexity: O(n)
public class Solution2 {

    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer> record = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++)
            record.put(nums[i], i);

        for (int i = 0; i < nums.length; i++) {
            Integer index = record.get(target - nums[i]);
            if (index != null && index != i) {
                int[] res = { i, index };
                return res;
            }

            record.put(nums[i], i);
        }

        throw new IllegalStateException("the input has no solution");
    }

    private static void printArr(int[] nums) {
        for (int num : nums)
            System.out.print(num + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        int[] nums = { 0, 4, 3, 0 };
        int target = 7;
        printArr((new Solution2()).twoSum(nums, target));
    }
}
```

#### 解法3

```java
import java.util.HashMap;

/// One-Pass Hash Table
/// Time Complexity: O(n)
/// Space Complexity: O(n)
public class Solution3 {

    public int[] twoSum(int[] nums, int target) {

        HashMap<Integer, Integer> record = new HashMap<Integer, Integer>();
        for (int i = 0; i < nums.length; i++) {
            int complement = target - nums[i];
            if (record.containsKey(complement)) {
                int[] res = { i, record.get(complement) };
                return res;
            }

            record.put(nums[i], i);
        }

        throw new IllegalStateException("the input has no solution");
    }

    private static void printArr(int[] nums) {
        for (int num : nums)
            System.out.print(num + " ");
        System.out.println();
    }

    public static void main(String[] args) {

        int[] nums = { 0, 4, 3, 0 };
        int target = 0;
        printArr((new Solution3()).twoSum(nums, target));
    }
}
```

### C++

#### 解法1

```c++
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

/// Brute Force
/// Time Complexity: O(n^2)
/// Space Complexity: O(1)
class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (int i = 0; i < nums.size(); i++)
            for (int j = i + 1; j < nums.size(); j++)
                if (nums[i] + nums[j] == target) {
                    int res[] = { i, j };
                    return vector<int>(res, res + 2);
                }

        throw invalid_argument("the input has no solution");
    }
};

void printVec(const vector<int> &vec)
{
    for (int e : vec)
        cout << e << " ";
    cout << endl;
}

int main()
{
    const int nums[] = { 0, 4, 3, 0 };
    vector<int> nums_vec(nums, nums + sizeof(nums) / sizeof(int));
    int target = 0;
    printVec(Solution().twoSum(nums_vec, target));
    getchar();
    return 0;
}
```

#### 解法2

```c++
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

/// Two-Pass Hash Table
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> record;
        for(int i = 0 ; i < nums.size() ; i ++)
            record[nums[i]] = i;

        for(int i = 0 ; i < nums.size() ; i ++){
            unordered_map<int,int>::iterator iter = record.find(target - nums[i]);
            if(iter != record.end() && iter->second != i){
                int res[] = {i, iter->second};
                return vector<int>(res, res + 2);
            }
        }

        throw invalid_argument("the input has no solution");
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    const int nums[] = {0,4,3,0};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );
    int target = 0;
    printVec(Solution().twoSum(nums_vec, target));
    getchar();
    return 0;
}
```

#### 解法3

```c++
#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_map>

using namespace std;

/// One-Pass Hash Table
/// Time Complexity: O(n)
/// Space Complexity: O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        unordered_map<int,int> record;
        for(int i = 0 ; i < nums.size() ; i ++){

            int complement = target - nums[i];
            if(record.find(complement) != record.end()){
                int res[] = {i, record[complement]};
                return vector<int>(res, res + 2);
            }

            record[nums[i]] = i;
        }

        throw invalid_argument("the input has no solution");
    }
};


void printVec(const vector<int>& vec){
    for(int e: vec)
        cout << e << " ";
    cout << endl;
}

int main() {

    const int nums[] = {0,4,3,0};
    vector<int> nums_vec( nums, nums + sizeof(nums)/sizeof(int) );
    int target = 0;
    printVec(Solution().twoSum(nums_vec, target));
    getchar();
    return 0;
}
```

### C语言

```C
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct object {
    int val;
    int index;
};

static int compare(const void *a, const void *b)
{
    return ((struct object *)a)->val - ((struct object *)b)->val;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize)
{
    int i, j;
    struct object *objs = malloc(numsSize * sizeof(*objs));
    int *res = (int *)malloc(2 * sizeof(int));
    for (i = 0; i < numsSize; i++) {
        objs[i].val = nums[i];
        objs[i].index = i;
    }
    qsort(objs, numsSize, sizeof(*objs), compare);

    i = 0;
    j = numsSize - 1;
    while (i < j) {
        int diff = target - objs[i].val;
        if (diff > objs[j].val) {
            while (++i < j && objs[i].val == objs[i - 1].val)
                ;
        } else if (diff < objs[j].val) {
            while (--j > i && objs[j].val == objs[j + 1].val)
                ;
        } else {
            res[0] = objs[i].index;
            res[1] = objs[j].index;
            *returnSize = 2;
            return res;
        }
    }
    *returnSize = 0;
    return res;
}

int main(void)
{
    int nums[] = { -1, -2, -3, -4, -5 };
    int target = -8;
    int count = sizeof(nums) / sizeof(*nums);
    int *results = NULL;
    int returnSize = 0;

    results = twoSum(nums, count, target, &returnSize);
    if (results && returnSize == 2) {
        printf("%d %d\n", results[0], results[1]);
    } else {
        printf("Not found\n");
    }
    system("pause");
    return 0;
}
```



