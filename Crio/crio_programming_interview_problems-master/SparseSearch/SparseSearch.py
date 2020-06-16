
def sparseSearch(sparseArray, queries):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    mapped = dict()
    for pos,element in enumerate(sparseArray):
        if element != "":
            assert element not in mapped
        mapped[element] = pos
    result = list()
    for query in queries:
        if query in mapped:
            result.append(mapped[query])
        else:
            result.append(-1)
    return result
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
def main():
    n  = int(input())
    sparseArray  = input().split()
    sparseArray = [x if x!="$" else "" for x in sparseArray]
    query = int(input())
    queries = list() 
    for _ in range(query):
        target = input()
        queries.append(target)
    result = sparseSearch(sparseArray,queries)
    print('\n'.join(str(i) for i in result))

if __name__ == "__main__":
    main()
