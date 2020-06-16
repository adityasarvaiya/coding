import sys

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def read_input_output(file_name):
    f = open(file_name, 'r')
    lines = f.readlines()

    lst = []

    for line in lines:
        lst.extend(line.split())

    lst = [int(i) for i in lst]

    return lst

def evaluate(input_file, expected_output_file, actual_output_file):

    lst_in = read_input_output(input_file)
    expected_index = read_input_output(expected_output_file)[0]
    actual_index = read_input_output(expected_output_file)[0]
    #print(lst_in, expected_index, actual_index)

    if expected_index not in range(len(lst_in)):
        return False

    return lst_in[actual_index] == lst_in[expected_index]

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

