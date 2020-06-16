def isPalindrome(s):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    s = "".join([i.lower() for i in s if i.isalnum()])
    return "true" if s == s[::-1] else "false"
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


if __name__ == '__main__':
    s = input()
    result = isPalindrome(s)
    print(result)
