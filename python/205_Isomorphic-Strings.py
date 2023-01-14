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
if __name__ == "__main__":
    sol = Solution()
    
    s = "badc"
    t = "baba"
    print(sol.isIsomorphic(s, t))

    s = "paper"
    t = "title"
    print(sol.isIsomorphic(s, t))
