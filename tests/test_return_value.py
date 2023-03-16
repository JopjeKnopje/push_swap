import os

arguments = [
        ["one", "Error!\n"],
        ["2147483647", "Error!\n"],
        ["-2147483648", "Error!\n"],
        ["1 1", "Error!\n"],
        ["1", ""],
        ["1 2", ""],
        ]


def main():

    for x in range(0, len(arguments)):
        cmd = "./push_swap " + arguments[x][0]
        expected = arguments[x][1]
        returned_output = os.popen(cmd).read()
        if (expected != returned_output):
            print("expected [{0}] | input [{1}] != output [{2}]".format(expected.rstrip('\n'), arguments[x][0].rstrip('\n'), returned_output.rstrip('\n')))
        else:
            print("passed")

if __name__ == "__main__":
    main()
