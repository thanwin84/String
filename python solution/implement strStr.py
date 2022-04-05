#https://leetcode.com/problems/implement-strstr/
# using kmp algorithm
# time: O(n + m) and space: O(m)
class Solution:
    def LPS(self, needle):
        result = [0] * len(needle)
        if len(needle) == 1:
            return result
        prev = 0
        current = 1
        while current < len(needle):
            if needle[prev] == needle[current]:
                result[current] = prev + 1
                current += 1
                prev += 1
            else:
                if prev == 0:
                    result[current] = 0
                    current += 1
                else:
                    prev = result[prev - 1]
        return result
    def strStr(self, haystack: str, needle: str) -> int:
        lps = self.LPS(needle)
        textIndex = 0
        patternIndex = 0
        while textIndex < len(haystack):
            # we got the matching
            if patternIndex == len(needle):
                break
            if needle[patternIndex] == haystack[textIndex]:
                textIndex += 1
                patternIndex += 1
            else:
                if patternIndex == 0:
                    textIndex += 1
                else:
                    patternIndex = lps[patternIndex - 1]
        # we couldn't find matching
        if patternIndex < len(needle):
            return -1
        return  textIndex - len(needle) 
        
