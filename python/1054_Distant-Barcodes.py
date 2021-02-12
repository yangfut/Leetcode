class Solution:
    def rearrangeBarcodes(self, barcodes):
        dict ={}
        n = len(barcodes)
        ans = [None] * n
        i=0
        
        for key in barcodes: dict[key] = 1 + dict.get(key,0)
            
        for key, val in sorted(dict.items(), key = lambda x:x[1], reverse=True):
            for _ in range(val):
                ans[i] = key
                i = i + 2 if i + 2 < n else 1
        return ans
    
    
def main():
    s = Solution()

    barcodes = [1,1,1,2,2,2]
    #Output: [2,1,2,1,2,1]
    print(s.rearrangeBarcodes(barcodes))

    
    barcodes = [1,1,1,1,2,2,3,3]
    #Output: [1,3,1,3,1,2,1,2]
    print(s.rearrangeBarcodes(barcodes))
    
    barcodes = [2,1,1]
    #Output: [1,2,1]
    print(s.rearrangeBarcodes(barcodes))
    
if __name__ == '__main__':
    main()

