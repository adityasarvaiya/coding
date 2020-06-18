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

    lst_in = read_input_output(input_file)[1:]
    expected_index = read_input_output(expected_output_file)[0]
    actual_index = read_input_output(actual_output_file)[0]

    if expected_index not in range(len(lst_in)):
        return False
    if(expected_index==0 and len(lst_in)==1):
        return True
    if(expected_index==0 and lst_in[0]>lst_in[1]):
        return True
    if(expected_index==len(lst_in)-1 and lst_in[-1]>lst_in[-2]):
        return True
    if(lst_in[expected_index]>lst_in[expected_index+1] and lst_in[expected_index]>lst_in[expected_index-1]):
        return True
    return False

if __name__ == '__main__':
    #assert evaluate('input.txt', 'expected.txt', 'out1.txt')
    #assert evaluate('input.txt', 'expected.txt', 'out2.txt')
    exit_code = 1
    if len(sys.argv) != 4:
        sys.exit(exit_code)
    result = evaluate(sys.argv[1], sys.argv[2], sys.argv[3])
    if result:
        exit_code = 0

    #print('Exit code = ', exit_code)
    sys.exit(exit_code)

