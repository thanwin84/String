class Solution:
    def check_palindrone(self, phrase):
        start = 0
        end = len(phrase) - 1
        while start < end:
            if phrase[start] == phrase[end]:
                return False
        return True
    def check_palindrone(self, phrase):
        start = 0
        end = len(phrase) - 1
        while start < end:
            if phrase[start] != phrase[end]:
                return False
            start += 1
            end -= 1
        return True
    def isPalindrome(self, s: str) -> bool:
        filtered_str = ""
        for ch in s:
            if ch.isalpha() or ch.isnumeric():
                filtered_str += ch.lower()
        return self.check_palindrone(filtered_str)
# one pass solution
class Solution:
    def isValid(self, ch):
        return ch.isalpha() or ch.isnumeric()
    
    def isPalindrome(self, s: str) -> bool:
        start = 0
        end = len(s) - 1
        while start < end:
            if not self.isValid(s[start]):
                start += 1
                continue
            if not self.isValid(s[end]):
                end -= 1
                continue
            if s[start].lower() != s[end].lower():
                return False
            start += 1
            end -= 1
        return True
    # changes made here
