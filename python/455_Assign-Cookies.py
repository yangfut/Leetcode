class Solution:
    def findContentChildren(self, g, s):
        g.sort(reverse=True)
        s.sort()
        counter = 0
        
        for cookie in s:
            if not g:
                return counter
            
            if cookie >= g[-1]:
                counter+=1
                g.pop()
        return counter

def main():
    sol = Solution()
    
    g = [1,2,3]
    s = [1,1]
    #Output: 1
    print(sol.findContentChildren(g, s))
    
    g = [1,2]
    s = [1,2,3]
    #Output: 2
    print(sol.findContentChildren(g, s))
    
if __name__ == '__main__':
    main()
