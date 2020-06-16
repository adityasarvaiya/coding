def number_of_ways(n):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    prime_mod = 1000000007;
    table = [0 for i in range(n + 10)]

    table[0] = 1
    table[1] = 1
    table[2] = 2
    for i in range(3, n+1):
        table[i] = (table[i-3] + table[i-2] + table[i-1]) % prime_mod

    return table[n]
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


def main():
    n = int(input().strip())
    print(number_of_ways(n))

if __name__ == '__main__':
    main()
