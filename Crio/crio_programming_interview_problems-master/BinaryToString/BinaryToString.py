
def convert_to_binary(number):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    if not (number*(2**31)).is_integer():
        return "ERROR"
    limit = number
    trailing_zeros = 0
    while not limit.is_integer():
        limit *= 2
        trailing_zeros += 1

    result = bin(int(limit))[::-1][:-2]
    return "0." + result.rjust(trailing_zeros, "0")
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    number = float(input())
    result = convert_to_binary(number)
    print(result)


if __name__ == "__main__":
    main()
