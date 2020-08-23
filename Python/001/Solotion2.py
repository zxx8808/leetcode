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
