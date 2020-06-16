def longest_ones(n):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    s = ""
    dict = {
	1 : '1',
	0 : '0'
    } 
    while (n > 0):
       s += dict[n % 2];
       n //= 2

    #print("s = ", s)
    lst = [len(x) for x in s.split("0")]
    ans = max(max(lst), 1)
    for i in range(len(lst)-1):
        ans = max(ans, 1 + lst[i] + lst[i+1])
    return ans
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    s = int(input().strip())
    print(longest_ones(s))
