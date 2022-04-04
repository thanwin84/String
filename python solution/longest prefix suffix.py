# O(n + m)
class Solution:
	def lps(self, s):
		# code here
		result = [0] * len(s)
		prev = 0
		fast = 1
		ans = 0
		while fast < len(s):
		    if s[prev] == s[fast]:
		        result[fast] = prev + 1
		        prev += 1
		        fast += 1
		    else:
		        if prev == 0:
		            fast += 1
		        else:
		            prev = result[prev -1]
		return result[-1]
