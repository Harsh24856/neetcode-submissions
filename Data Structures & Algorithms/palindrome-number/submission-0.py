class Solution:
    def check(self, x: int) -> bool:
        l=0
        r=len(x)-1
        while(l<r):
            if x[l]!=x[r]:
                return False
            l+=1
            r-=1
        return True

    def isPalindrome(self, x: int) -> bool:
        num=str(x)
        return self.check(num)