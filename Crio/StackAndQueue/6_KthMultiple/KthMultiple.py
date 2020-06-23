def kthMultiple(k):
    # 1st element will be 1
    ans = 1
    
    # Make individual queue for 3, 5 and 7
    q3 = [] 
    q5 = [] 
    q7 = []
    
    for i in range(k-1):
        # Add next possible numbers to queue
        q3.append(ans * 3)
        q5.append(ans * 5)
        q7.append(ans * 7)

        # Find current number
        ans = min(q3[0], q5[0], q7[0])

        # Delete current number from all the queues
        if (ans == q3[0]):
            q3.pop(0)

        if (ans == q5[0]):
            q5.pop(0)

        if (ans == q7[0]):
            q7.pop(0)

    return ans

if __name__ == '__main__':
    k = int(input())
    result = kthMultiple(k)
    print(result)