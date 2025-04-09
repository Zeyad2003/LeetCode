class Solution(object):
    def minOperations(self, nums, k):
        distinctNums = set()
        distinctNums.add(k)

        minNum = nums[0]

        for i in range(len(nums)):
            minNum = min(minNum, nums[i])
            distinctNums.add(nums[i])

        if k > minNum:
            return -1
        
        return len(distinctNums) - 1
