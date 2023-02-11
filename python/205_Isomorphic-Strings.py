class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        hashmap = [0]*128
        alphabetIsUsed = [0]*128
        for idx, ele in enumerate(s):
            if hashmap[ord(ele)] == 0:
                hashmap[ord(ele)] = t[idx]
                if alphabetIsUsed[ord(t[idx])] == 0:
                    alphabetIsUsed[ord(t[idx])]+= 1
                else:
                    return False
            else:
                if hashmap[ord(ele)] != t[idx]:
                    return False
        return True
    def isIsomorphic2(self, s: str, t: str) -> bool:
        #Check alphabet is used
        #Check every single word is being mapped
        #Check no word is mapped to the same target

        charMap = {}
        IsTargetUsed = [0] * 128
        for idx, ele in enumerate(s):
            if ele in charMap:
                if charMap[ele] != t[idx]:
                    return False
            else:
                if IsTargetUsed[ord(t[idx])] == 0:
                    IsTargetUsed[ord(t[idx])] += 1
                else:
                    return False
                charMap[ele] = t[idx]
                
        return True
if __name__ == "__main__":
    sol = Solution()
    
    s = "badc"
    t = "baba"
    print(sol.isIsomorphic2(s, t))

    s = "paper"
    t = "title"
    print(sol.isIsomorphic2(s, t))