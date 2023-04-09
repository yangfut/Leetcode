class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if len(numbers)==2: return [1, 2]

        ptr1, ptr2 = 0, len(numbers)-1

        while(ptr2>ptr1):
            if (numbers[ptr1]+numbers[ptr2]) > target:
                ptr2-=1
            elif (numbers[ptr1]+numbers[ptr2]) < target:
                ptr1+=1
            else:
                return [ptr1+1, ptr2+1]