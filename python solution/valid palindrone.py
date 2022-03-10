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
