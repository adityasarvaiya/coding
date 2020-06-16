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
    f = open(file_name , 'r')
    lines = f.readlines()
    f.close()

    n = int(lines[0])
    L = list(map(int , lines[1].strip().split()))
    x = int(lines[2])
    return n , L , x


def add(cntDict , x):
    if x not in cntDict:
        cntDict[x] = 0
    cntDict[x] += 1

def evaluate(input_file, expected_output_file, actual_output_file):
    n , L , x = read_input(input_file)
    O = read_output(actual_output_file)
    assert(len(L) == n)
    if len(O) != len(L):
        return False

    if sorted(O) != sorted(L):
        return False

    i = 0
    while(i < n):
        if(O[i] >= x):
            break
        i += 1
    while(i < n):
        if(O[i] < x):
            return False
        if O[i] > x:
            break
        i += 1
    while(i < n):
        if(O[i] <= x):
            return False
        i += 1

    return True

if __name__ == '__main__':

    exit_code = 1

    if len(sys.argv) != 4:
        sys.exit(exit_code)
    result = evaluate(sys.argv[1], sys.argv[2], sys.argv[3])
    if result:
        exit_code = 0

    #print('Exit code = ', exit_code)
    sys.exit(exit_code)
