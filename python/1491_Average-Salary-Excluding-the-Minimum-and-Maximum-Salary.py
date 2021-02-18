class Solution:
    def average(self, salary):
        maxNum = salary[0] // 1000
        minNum = salary[1] // 1000
        
        if maxNum < minNum:
            maxNum, minNum = minNum, maxNum  
            
        sumNums = maxNum + minNum
        
        for person in salary[2:]:
            num = person // 1000
            sumNums += num
            if num > maxNum:
                maxNum = num
            elif num < minNum:
                minNum = num
    
        return ((sumNums-minNum-maxNum) / (len(salary)-2)) * 1000

def main():
    sol = Solution()
    
    salary = [4000,3000,1000,2000]
    #Output: 2500.00000
    print(sol.average(salary))
    
    salary = [1000,2000,3000]
    #Output: 2000.00000
    print(sol.average(salary))
    
if __name__ == '__main__':
    main()

