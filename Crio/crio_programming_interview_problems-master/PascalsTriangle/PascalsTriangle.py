def pascalsTriangle(n):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    M = []*n
    for i in range(n):
        M.append([1])
        for j in range(i-1):
            M[-1].append(M[-2][j]+M[-2][j+1])
        if(i>0):
            M[-1].append(1)
    return M
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    result = pascalsTriangle(n)
    for row in result:
        print(*row)