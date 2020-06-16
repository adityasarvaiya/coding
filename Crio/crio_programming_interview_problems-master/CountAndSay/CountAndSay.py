def countAndSay(n):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
        arr = [None for _ in range(30)]
        arr[0] = "1"
        for i in range(1,n):
        	strr = ""
        	x = len(arr[i - 1])
        	j=0
        	while j<x:
        		ch = arr[i - 1][j]
        		count = 1
        		j+=1
        		while j < x and arr[i - 1][j] == ch:
        			count+=1
        			j+=1
        		strr += str(count)+ch
        	arr[i] = strr
        return arr[n - 1]
    #CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

if __name__ == '__main__':
    n = int(input())
    result = countAndSay(n)
    print(result)
