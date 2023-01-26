# space: O(1)
def fillCharCounts(string, countArr):
    for i in string:
        countArr[ord(i)] += 1
def printDuplicates(S):
    countArr = [0 for i in range(256)]
    fillCharCounts(S, countArr)

    # print character having count more than 0
    for i in range(256):
        if countArr[i] > 1:
            print(f'{chr(i)} : {countArr[i]}')


printDuplicates("test string")
