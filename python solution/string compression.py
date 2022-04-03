# time: O(n)
class Solution:
    def compress(self, chars: List[str]) -> int:
        size = len(chars)
        ansIndex = 0
        startIndex = 0
        while startIndex < size:
            repeatingIndex = startIndex + 1
            # keep moving forward until we get different char
            while repeatingIndex < size and chars[repeatingIndex] == chars[startIndex]:
                repeatingIndex += 1
                
            # store the current char
            chars[ansIndex] = chars[startIndex]
            ansIndex += 1
            repeatingCount = repeatingIndex - startIndex
            # convert repeating count in string and modify chars array with each char
            if repeatingCount > 1:
                repeatingCount = str(repeatingCount)
                for char in repeatingCount:
                    chars[ansIndex] = char
                    ansIndex += 1
            startIndex = repeatingIndex
        return ansIndex
