def next_greater(num):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    temp_num = num
    zero_bits = ones_bits = 0

    while temp_num&1 == 0 and temp_num != 0:
        zero_bits += 1
        temp_num = temp_num >> 1

    while temp_num&1 == 1:
        ones_bits += 1
        temp_num = temp_num >> 1

    if zero_bits + ones_bits == 63 or zero_bits + ones_bits == 0:
        return -1

    return num + (1<<zero_bits) + (1<<(ones_bits - 1)) -1
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def next_smaller(num):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    temp_num = num
    zero_bits = ones_bits = 0

    while temp_num&1 == 1:
        ones_bits += 1
        temp_num = temp_num >> 1

    if temp_num == 0:
        return "No Number"

    while temp_num&1 == 0 and temp_num != 0:
        zero_bits += 1
        temp_num = temp_num >> 1

    return num - (1<<ones_bits) - (1<<(zero_bits - 1)) + 1
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    n = int(input())
    greater_number = next_greater(n)
    smaller_number = next_smaller(n)
    print(greater_number)
    print(smaller_number)


if __name__ == "__main__":
    main()
    
