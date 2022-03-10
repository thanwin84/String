def reverse_a_string(phrase):
    reversed_str = ""
    for char in reversed(range(len(phrase) - 1)):
        reversed_str += phrase[char]
    return reversed_str


if __name__ == "__main__":
    name = str(input())
    print(reverse_a_string(name))
