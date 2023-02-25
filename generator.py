import random
import os

ARG_COUNT = 500
MIN_VAL = -2147483648
MAX_VAL = 2147483647 



def main():
    lst = []
    string = "./push_swap "
    for x in range(0, ARG_COUNT):
        num = random.randrange(MIN_VAL, MAX_VAL)
        lst.append(num)
    lst = list(dict.fromkeys(lst))

    string += ' '.join(map(str, lst)) 
    # print(string)
    os.system(string)


if __name__ == "__main__":
    main()
