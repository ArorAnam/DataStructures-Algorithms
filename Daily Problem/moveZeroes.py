class Solution:
  def moveZeros(self, nums):
      # stores index of the next available position
      k = 0

      # do for each element
      for i in nums:
          # if current element is non zero, put the element at
          # next free position on the list
        if i:
            nums[k] = i;
            k = k + 1

      # move all 0's to the end of the list (remaining indices)
      for i in range(k, len(nums)):
          nums[i] = 0



nums = [0, 0, 0, 2, 0, 1, 3, 4, 0, 0]
Solution().moveZeros(nums)
print(nums)
# [2, 1, 3, 4, 0, 0, 0, 0, 0, 0]
