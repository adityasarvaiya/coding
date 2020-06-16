import sys

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def read_output(file_name):
    f = open(file_name, 'r')
    lines = f.readlines()

    lst = []

    for line in lines:
        if line.strip() != '':
            lst.append(sorted(line.strip().split()))

    res = sorted(lst)
    #print(res)
    return res


def evaluate(input_file, expected_output_file, actual_output_file):
    return read_output(expected_output_file) == read_output(actual_output_file)

if __name__ == '__main__':
    #assert evaluate('input.txt', 'expected.txt', 'out1.txt')
    #assert evaluate('input.txt', 'expected.txt', 'out2.txt')
    exit_code = 1
    #print('length = ', len(sys.argv))
    if len(sys.argv) != 4:
        sys.exit(exit_code)
    result = evaluate(sys.argv[1], sys.argv[2], sys.argv[3])
    if result:
        exit_code = 0

    #print('Exit code = ', exit_code)
    sys.exit(exit_code)

