
def is_s1_rotation_of_s2(s1, s2):
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    l1 = len(s1)
    l2 = len(s2)
    
    if l1 != l2:
        return False


    for i in range(l1):
      p1 = s1[0:i]
      p2 = s1[i:]
      if s2 == p2 + p1:
          return True

# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
 
    return False   

def main():
    (s1, s2) = input().strip().split()
    if is_s1_rotation_of_s2(s1, s2):
        print("Yes")
    else:
        print("No")

if __name__ == '__main__':
    main()
# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    s1 = 'a' * 700 + 'b' * 300
    s2 = 'b' * 100 + 'a' * 700 + 'b' * 200
    assert(is_s1_rotation_of_s2(s1, s2))
    s2 = 'a' * 400 + 'b' * 300 + 'a' * 300
    assert(is_s1_rotation_of_s2(s1, s2))
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
