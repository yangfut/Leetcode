class Solution:
    def searchInsert(self, nums, target):
        def binarySearch(nums, target):
            if target <= nums[0]:
                return 0
            if target > nums[-1]:
                return len(nums)
            st, ed = 0, len(nums)-1
            mid = (ed+st) // 2
            while(ed-st > 1):
                if target == nums[mid]:
                    return mid
                if target > nums[mid]:
                    st = mid
                    mid = ((ed+st) // 2)
                if target < nums[mid]:
                    ed = mid
                    mid = (ed+st)//2
            return ed
        return binarySearch(nums, target)


if __name__ == "__main__":
    S = Solution()
    nums = [1, 3, 5, 6]
    target = 5
    print(S.searchInsert(nums, target))

    nums = [1, 3, 5, 6]
    target = 2
    print(S.searchInsert(nums, target))

    nums = [1, 3, 5, 6]
    target = 7
    print(S.searchInsert(nums, target))

    nums = [1, 3, 5, 6]
    target = 0
    print(S.searchInsert(nums, target))

    nums = [1]
    target = 0
    print(S.searchInsert(nums, target))
