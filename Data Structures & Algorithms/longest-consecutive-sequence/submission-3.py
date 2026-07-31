class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res=0
        st=set(nums)
        longest=0
              
        for num in nums:
            if num-1 not in st:
                len=1
                while(num+len in st):
                    len+=1
                longest=max(longest,len)

        
        return longest
                 