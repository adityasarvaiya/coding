
def evaluateExpression(arr):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    stack = []
    
    for token in arr:
        if token not in "+-/*":
            stack.append(int(token))
            continue
        
        number_2 = stack.pop()
        number_1 = stack.pop()
        
        result = 0
        if token == "+":
            result = number_1 + number_2
        elif token == "-":
            result = number_1 - number_2
        elif token == "*":
            result = number_1 * number_2
        else:
            result = int(number_1 / number_2)
            
        stack.append(result)

    return stack.pop()
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    arr = list(map(str, input().strip().split()))
    result = evaluateExpression(arr)
    print(result)
    
