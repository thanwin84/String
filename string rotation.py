

def string_rotation(s1, s2):
    l1 = len(s1)
    l2 = len(s2)
    if l1 == l2 != 0:
        s1s1 = s1 * 2
        return s2 in s1s1
    return False

s1 = "waterbottle"
s2 = "erbottlewat"
print(string_rotation(s1, s2))
