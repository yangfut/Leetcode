
# The isBadVersion API is already defined for you.
# @param version, an integer
# @return a bool
# def isBadVersion(version):

class Solution(object):
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        st, ed = 1, n
        if ed == 1:
            return ed

        pivot = (ed+st)//2
        while(ed-st>1):
            if isBadVersion(pivot):
                ed = pivot
            else:
                st = pivot
            pivot = (ed+st)//2
        return st if isBadVersion(st) else ed