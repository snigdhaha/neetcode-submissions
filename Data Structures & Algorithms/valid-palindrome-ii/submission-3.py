class Solution:
    def is_palindrome(sle,i:int,j:int,s:str):
        while i<=j:
            while i < j and not s[i].isalnum():
                i+=1
            while i < j and not s[j].isalnum():
                j-=1
            

            if s[i].lower() != s[j].lower():
                return False
            
            i+=1
            j-=1
            
        
        return True
    
    def validPalindrome(self, s: str) -> bool:
        l=0
        r=len(s)-1

        while l<r:
            if s[l] != s[r]:
                return (self.is_palindrome(l + 1, r,s) or self.is_palindrome(l, r - 1,s))

            l+=1
            r-=1

        return True
