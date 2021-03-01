class Solution:
    def distributeCandies(self, candies, num_people):
        
        ans, c = [0] * num_people, 0
        total = sum_0 = num_people * (1+num_people) // 2
        
        while total <= candies:
            total += sum_0 + (c+1)*num_people*num_people
            c += 1
            
        total -= sum_0+c*num_people*num_people
        res = candies - total
        
        for i in range(num_people):
            ans[i] = (i+1)*c + num_people * sum(range(1,c))
            if res == 0:
                continue
            if res - ((i+1) + c*num_people) > 0:
                res -= ((i+1) + c*num_people)
                ans[i] += (i+1) + c*num_people
            else:
                ans[i] += res
                res = 0
            
        return ans
    
def main():
    sol = Solution()
    candies = 60
    num_people = 4
    #Output: [15,18,15,12]
    print(sol.distributeCandies(candies, num_people))
    
    candies = 10
    num_people = 3
    #Output: [5,2,3]
    print(sol.distributeCandies(candies, num_people))
    
    candies = 7
    num_people = 4
    #Output: [1,2,3,1]
    print(sol.distributeCandies(candies, num_people))
    
if __name__ == "__main__":
    main()
