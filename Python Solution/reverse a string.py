def reverse_a_string(str):
    reversed_str = ""
    for char in reversed(range(len(str) -1)):
        reversed_str += str[char]
    return reversed_str


if __name__ == "__main__":
    name = str(input())
    print(reverse_a_string(name))
