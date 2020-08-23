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
