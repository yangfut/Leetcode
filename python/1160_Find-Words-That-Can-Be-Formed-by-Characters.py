class Solution:
    def countCharacters(self, words, chars) -> int:
        offset = ord('a')
        count = 0
        hashmap = [0] * 26
        for char in chars:
            hashmap[ord(char)-offset] += 1
        
        hashmap2 = hashmap.copy()
        
        for word in words:
            flag = 1
            for alpha in word: 
                if hashmap[ord(alpha)-offset] == 0:
                    flag = 0
                    break
                hashmap[ord(alpha)-offset] -= 1
                
            hashmap = hashmap2.copy()
            if flag == 1:
                count += len(word)
                
        return count

def main():
    sol = Solution()
    
    words = ["cat","bt","hat","tree"]
    chars = "atach"
    #Output: Output: 6
    print(sol.countCharacters(words, chars))
    
    words = ["hello","world","leetcode"]
    chars = "welldonehoneyr"
    #Output: 10
    print(sol.countCharacters(words, chars))
    
if __name__ == '__main__':
    main()
