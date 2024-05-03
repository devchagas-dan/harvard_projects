from cs50 import get_int


def main():
    n = get_number()
    py(n)


def get_number():
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            break
    return height


def py(n):
    for i in range(n):
        print(" " * (n - 1 - i), end="")
        print("#" * (i + 1), end="")
        print(" " * 2, end="")
        print("#" * (i + 1), end="")
        print(end="\n")


main()