def find_replace(s, pat1, pat2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    res = ''
    
    for (i, c) in enumerate(s):
        if c == pat1:
           res += pat2
        else:
           res += c

    return res
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    s = input()
    print(find_replace(s, ' ', '%20'))

if __name__ == '__main__':
   main()
