def is_unique(s):
    res = False
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    lst = [x[1] for x in list(enumerate(s))]
    res =  len(s) == len(set(lst))
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    return res
def main():
    s = input().strip()

    if is_unique(s):
        print("Yes")
    else:
        print("No")


if __name__ == '__main__':
    main()
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    assert(not is_unique('a' * 450000 + 'b' * 72300))
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
