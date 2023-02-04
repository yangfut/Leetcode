class Solution:
    def longestCommonPrefix(self, strs):
        #Only one case
        if len(strs) == 1:
            return strs[0]
        #Check empty str
        for ele in strs:
            if len(ele) == 0:
                return ""
        pivot = 0
        for idx, item in enumerate(zip(*strs)):
            itemInSet = set(item)
            pivot = idx
            #print(item)
            if len(itemInSet) != 1:
                #print("idx = ", idx)
                return strs[0][:pivot]
        return strs[0][:pivot+1]

        
if __name__ == "__main__":
    s = Solution()
    strs = ["flower","flow","flight"]
    print("ansStr = ", s.longestCommonPrefix(strs))

    strs = ["dog","racecar","car"]  
    print("ansStr = ", s.longestCommonPrefix(strs))

    strs = ["ab", "a"]
    print("ansStr = ", s.longestCommonPrefix(strs))

    strs = ["abab","aba",""]
    print("ansStr = ", s.longestCommonPrefix(strs))