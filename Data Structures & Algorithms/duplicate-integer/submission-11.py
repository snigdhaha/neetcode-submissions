class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        if(len(nums)==0):
            return False;

        hash={}
        for num in nums:
            if num in hash:
                hash[num]+=1
            else:
                hash[num]=1
            if hash[num]>1:
                return True;
                break;
        return False;
