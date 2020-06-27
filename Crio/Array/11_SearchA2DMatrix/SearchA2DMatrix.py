import sys
from Solution import solve

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    rows, columns = map(int, sys.stdin.readline().split())
    matrix = list()
    for _ in range(rows):
        row = list(map(int, sys.stdin.readline().split()))
        matrix.append(row)
    queries = int(sys.stdin.readline())
    for _ in range(queries):
        target = int(sys.stdin.readline())
        result = solve(matrix, target)
        if result:
            sys.stdout.write("true\n")
        else:
            sys.stdout.write("false\n")


if __name__ == "__main__":
    main()
