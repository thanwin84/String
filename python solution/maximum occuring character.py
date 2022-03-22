# time: O(n) and space: O(1)
class Solution:
    # Function to find the maximum occurring character in a string.
    def getMaxOccurringChar(self, s):
        frequency = [0] * 26
        for char in s:
            char_number = 0
            if 'a' <= char <= 'z':
                char_number = ord(char) - ord('a')
            else:
                char_number = ord(char) - ord('A')
            frequency[char_number] += 1
        _max = 0
        char = 0
        for i in range(26):
            if frequency[i] > _max:
                char = i
                _max = frequency[i]
          # a = 97
        return chr(97 + char)
