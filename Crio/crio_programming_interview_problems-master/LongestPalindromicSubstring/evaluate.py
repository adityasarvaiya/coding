import sys

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def read_content(file_name):
    f = open(file_name, 'r')
    content = f.readlines()
    f.close()
    return content

def is_palindrome(string):
    return string == string[::-1]

def evaluate(input_file, expected_output_file, actual_output_file):
    input_lines = read_content(input_file)
    expected_output_lines = read_content(expected_output_file)
    actual_output_lines = read_content(actual_output_file)

    input_str = input_lines[0].strip()
    expected_substr = expected_output_lines[0].strip()
    actual_substr = actual_output_lines[0].strip()

    #print(actual_substr, expected_substr)
    return actual_substr in input_str and is_palindrome(actual_substr) and len(actual_substr) == len(expected_substr)

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
