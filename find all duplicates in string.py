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
