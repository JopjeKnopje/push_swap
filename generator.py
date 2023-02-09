import random
import os

ARG_COUNT = 20
MIN_VAL = 0
MAX_VAL = 100


def main():
    string = "./app "
    for x in range(0, ARG_COUNT):
        num = random.randrange(MIN_VAL, MAX_VAL)
        string += str(num)
        string += " "
    print(string)
    os.system(string)


if __name__ == "__main__":
    main()
