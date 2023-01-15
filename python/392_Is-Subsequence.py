class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) == 0:
            return True
        if len(t) == 0 or len(t) < len(s):
            return False

        ptr_s = 0
        ptr_t = 0

        while ptr_t < len(t):
            if s[ptr_s] == t[ptr_t]:
                ptr_s += 1
            if ptr_s == len(s):
                return True
            ptr_t += 1
        return False

if __name__ == "__main__":
    sol = Solution()
    s = "acb"
    t = "ahbgdc"
    print(sol.isSubsequence(s, t))