
def countConversionBits(a, b):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    xorr = a^b
    result = bin(xorr).count('1')
    return result
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def main():
    a, b = map(int, input().split())
    answer = countConversionBits(a, b)
    print(answer)

if __name__ == "__main__":
    main()
    
