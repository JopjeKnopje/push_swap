import subprocess

arguments = [
        ["one", "Error\n"],
        ["2147483648", "Error\n"],
        ["-2147483649", "Error\n"],
        ["1 1", "Error\n"],
        ["1", ""],
        ["1 2", ""],
        ]


def main():

    for x in range(0, len(arguments)):
        expected = arguments[x][1]

        sp = subprocess.Popen(["./push_swap", arguments[x][0]], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        out, err = sp.communicate()

        if (err == ""):
            cmd_output = out.decode('utf-8')
        else:
            cmd_output = err.decode('utf-8')

        if (expected != cmd_output):
            print("expected [{0}] | input [{1}] != output [{2}]".format(expected.rstrip('\n'), arguments[x][0].rstrip('\n'), cmd_output.rstrip('\n')))
        else:
            print("passed")


if __name__ == "__main__":
    main()
