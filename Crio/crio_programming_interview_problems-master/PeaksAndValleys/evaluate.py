import sys

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def read_output(file_name):
    f = open(file_name, 'r')
    lines = f.readlines()
    f.close()

    lst = []
    return list(map(int , lines[0].strip().split()))


def read_input(file_name):
    f = open(file_name, 'r')
    lines = f.readlines()
    f.close()

    lst = []
    return int(lines[0])

def evaluate(input_file, expected_output_file, actual_output_file):
    A = read_output(actual_output_file)
    n = read_input(input_file)
    if n != len(A):
        return False
    if n == 1:
        return True
    ok = True

    for i in range(1 , n-1):
        if (i%2) == 0:
            if A[i] >= A[i+1] and A[i] >= A[i-1]:
                continue
        else:
            if A[i] <= A[i+1] and A[i] <= A[i-1]:
                continue
        ok = False
    if ok:
        return True

    ok = True

    for i in range(1 , n-1):
        if (i%2) == 0:
            if A[i] >= A[i+1] and A[i] >= A[i-1]:
                continue
        else:
            if A[i] <= A[i+1] and A[i] <= A[i-1]:
                continue
        ok = False
    return ok


if __name__ == '__main__':

    exit_code = 1

    if len(sys.argv) != 4:
        sys.exit(exit_code)
    result = evaluate(sys.argv[1], sys.argv[2], sys.argv[3])
    if result:
        exit_code = 0

    #print('Exit code = ', exit_code)
    sys.exit(exit_code)
