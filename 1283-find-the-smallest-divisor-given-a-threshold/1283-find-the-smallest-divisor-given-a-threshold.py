class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        def good(m : int, nums: List[int], threshold: int) -> bool:
            cnt = 0
            for num in nums:
                cnt += (num + m - 1) // m
            
            print(m, cnt)
            return cnt <= threshold
        
        l = 1
        r = max(nums)
        ans = 1
        
        while l <= r:
            m = l + (r - l)//2
            if(good(m, nums, threshold)):
                ans = m
                r = m - 1
            else:
                l = m + 1
        
        return ans
    
    