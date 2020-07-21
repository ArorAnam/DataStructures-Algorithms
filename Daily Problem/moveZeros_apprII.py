class Solution:

    def moveZeros(self, nums):
        j = 0

        def swap(A, i, j):
            temp = A[i]
            A[i] = A[j]
            A[j] = temp


        # each time we encounter a nonzero, j is incrememted and
        # the element is placed before the pivot
        for i in range(len(nums)):
            if nums[i]:
                swap(nums, i, j)
                j += 1



nums = [0, 0, 0, 2, 0, 1, 3, 4, 0, 0]

if __name__ == '__main__':
    Solution().moveZeros(nums)
    print(nums)
    # [2, 1, 3, 4, 0, 0, 0, 0, 0, 0]
