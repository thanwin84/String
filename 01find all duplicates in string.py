class FindDuplicates:
    def __init__(self):
        self.arr = [0] * 256

    def find_duplicates(self, s):
        for i in s:
            self.arr[ord(i)] += 1
        for i in range(len(self.arr)):
            if self.arr[i] > 1:
                print(f"{self.arr[i]} {chr(i)}")


s = "abaaccd"
obj = FindDuplicates()
obj.find_duplicates(s)
# time complexity: O(n) and space: O(256)
from collections import defaultdict
class FindDuplicates:
    def find_duplicates(self, s):
        table = defaultdict(int)
        for i in s:
            table[i] += 1

        for key, value in table.items():
            print(f"{key} {value} ")
# time: O(n) and space: O(k) where k is the number of unique character in string
