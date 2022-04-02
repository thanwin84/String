# time: O(n^2) and space: O(n) 
def solve(self, nums, k, pos, dp):
    lastIndex = len(nums) - 1
    # we cannot have extra space after last word in the last line
    if pos == lastIndex:
        return 0
    ans = float('inf')
    _sum = 0
    if dp[pos] != -1:
        return dp[pos]
    # checking how many words we can put at max in a line
    # spaces between words are not considered as extra space
    for currentIndex in range(pos, len(nums)):
        _sum += nums[currentIndex]
        widthCovered = _sum + currentIndex - pos
	# checking if words  can be put in the same line
        if widthCovered <= k:
            if currentIndex == lastIndex:
                ans = 0
                break
            extraSpaces = k - widthCovered
            right = self.solve(nums, k, currentIndex + 1, dp)
            ans = min(extraSpaces ** 2 + right, ans)
        else:
          # we can't keep words in the same line until this positon
          # so we can't extend our search
            break
    dp[pos] = ans
    return ans

    def solveWordWrap(self, nums, k):
        # Code here
        dp = [-1 for i in range(len(nums) + 1)]
        return self.solve(nums, k, 0, dp)
  
# iterative approach
# just copy paste the recursive approach
class Solution:
	def solveWordWrap(self, nums, k):
		#Code here
		dp = [0 for i in range(len(nums) + 1)]
		lastIndex = len(nums) - 1
        
        for start in range(len(nums)-1, -1, -1):
            _sum = 0
            ans = float('inf')
            for currentIndex in range(start, len(nums)):
                _sum += nums[currentIndex]
                widthCovered = _sum + currentIndex - start
                if widthCovered <= k:
                    if currentIndex == lastIndex:
                        ans = 0
                        break
                    extraSpaces = k - widthCovered
                    right = dp[currentIndex + 1]
                    ans = min(extraSpaces ** 2 + right, ans)
                else:
                    break
            dp[pos] = ans
        return dp[0]
    # time taken: 3hours
