class Solution:
    def restoreString(self, s, indices):
        out = len(indices) * [""]
        for char, index in zip(s,indices):
            out[index] = char
        
        return "".join(out)
    
def main():
    solution = Solution()
    s = "codeleet"
    indices = [4,5,6,7,0,2,1,3]
    print(solution.restoreString(s, indices))
    #Output: "leetcode"
    
    s = "abc"
    indices = [0,1,2]
    print(solution.restoreString(s, indices))
    #Output: "abc"
     
    s = "aiohn"
    indices = [3,1,4,2,0]
    print(solution.restoreString(s, indices))
    #Output: "nihao"

    s = "aaiougrt"
    indices = [4,0,2,6,7,3,1,5]
    print(solution.restoreString(s, indices))
    #Output: "arigatou"
    
    s = "art"
    indices = [1,0,2]
    print(solution.restoreString(s, indices))
    #Output: "rat"

if __name__ == '__main__':
    main()

