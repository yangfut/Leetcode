class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        OFFSET = 97
        hash_table = [0] * 26
    
        
        for ch0, ch1 in zip(s,t):
            hash_table[ord(ch0)-OFFSET] += 1
            hash_table[ord(ch1)-OFFSET] -= 1
        
        for val in hash_table:
            if val != 0:
                return False
        
        return True
    
def main():
    solution = Solution()
    
    s = "anagram"
    t = "nagaram"
    print(solution.isAnagram(s, t))
    #Output: true

    s = "rat"
    t = "car"
    print(solution.isAnagram(s, t))
    #Output: false
    
    return None

if __name__ == '__main__':
    main()

