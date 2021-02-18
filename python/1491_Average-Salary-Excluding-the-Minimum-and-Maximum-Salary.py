class Solution:
    def average(self, salary):
        maxNum = salary[0]
        minNum = salary[1]
        
        if maxNum < minNum:
            maxNum, minNum = minNum, maxNum  
         
        sumNums = maxNum + minNum
        
        for person in salary[2:]:
            sumNums += person
            if person > maxNum:
                maxNum = person
            elif person < minNum:
                minNum = person
    
        return ((sumNums-minNum-maxNum) / (len(salary)-2))

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

