class Solution:
    def isHappy(self, n: int) -> bool:
        def divde_square(x):
            s=0
            while x>0:
                x, mod = divmod(x,10)
                s += (mod**2)
            return s
        
        if n==1:
            return True

        _set = set()
        _set.add(n)
        while True:
            n = divde_square(n)
            if n == 1:
                return True
            if n in _set:
                return False
            _set.add(n)


def main():
    sol = Solution()
    n = 19
    print(sol.isHappy(n))
    n=2
    print(sol.isHappy(n))

if __name__ == '__main__':
    main()
