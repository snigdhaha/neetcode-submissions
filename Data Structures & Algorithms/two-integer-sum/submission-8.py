class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash= {}
        for i in range(len(nums)):
            hash[nums[i]]=i

        ans=[]
        
        for i in range(len(nums)):
            diff=target-nums[i]
            if diff in hash and hash[diff]!=i:
                ans.append(i)
                ans.append(hash[diff])
                return ans
        
        return ans