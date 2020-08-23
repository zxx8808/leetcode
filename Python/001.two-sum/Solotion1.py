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
