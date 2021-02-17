class Solution:
    def alphabetBoardPath(self, target):
        hashTable = [[0, 0], [0, 1], [0, 2], [0, 3], [0, 4], [1, 0], [1, 1], [1, 2], [1, 3], [1, 4], [2, 0], [2, 1], [2, 2], [2, 3], [2, 4], [3, 0], [3, 1], [3, 2], [3, 3], [3, 4], [4, 0], [4, 1], [4, 2], [4, 3], [4, 4], [5, 0]]
        OFFSET, current = 97, 0
        res = ""
        
        for t in target:
            v_move = hashTable[current][0] - hashTable[ord(t)-OFFSET][0]
            h_move = hashTable[current][1] - hashTable[ord(t)-OFFSET][1]
            
            while v_move != 0 or h_move != 0:
                #Go vertical direction
                while v_move != 0:
                    if v_move < 0 and current < 21:
                        res += 'D'
                        v_move += 1
                        current += 5
                    elif v_move > 0:
                        res += 'U'
                        v_move -= 1
                        current -= 5
                    else:
                        break
                #Go horizontal direction     
                current -= h_move
                while h_move != 0:
                    if h_move < 0:
                        res += 'R'
                        h_move += 1
                    else:
                        res += 'L'
                        h_move -= 1
            res += '!'
        return res

def main():
    sol = Solution()
    
    target = "leet"
    #Output: "DDR!UURRR!!DDD!"
    print(sol.alphabetBoardPath(target))
    
    target = "code"
    #Output: "RR!DDRR!UUL!R!"
    print(sol.alphabetBoardPath(target))
    
    target = "zdz"
    #Output: "DDDDD!UUUUURRR!DDDDLLLD!"
    print(sol.alphabetBoardPath(target))
    
    target = "zb"
    #Output: "DDDDD!UUUUUR!"
    print(sol.alphabetBoardPath(target))
    
#     target = "grfgruuzjrktmqkziczvhezkpjzzxrdofdsksssvqoqpvwybrfigkfekcuzqdopwkgwtajelpkpxymvzikrcyoglzejtgsgzstun"
#     print(sol.alphabetBoardPath(target))
    
if __name__ == '__main__':
    main()
