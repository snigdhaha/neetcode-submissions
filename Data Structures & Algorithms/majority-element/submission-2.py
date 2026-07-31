class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        el=0
        cnt=0
        i=0
        n=len(nums)

        while(i<n):
            if(cnt==0):
                el=nums[i]
                cnt+=1
            elif el==nums[i]:
                cnt+=1
            else:
                cnt-=1
            i+=1
        
        return el