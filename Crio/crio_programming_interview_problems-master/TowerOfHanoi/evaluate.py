import sys

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


n=0
def read_output(file_name):
  f = open(file_name, 'r')
  lines = f.readlines()
  stackA = []
  stackB = []
  stackC = []
  temp=0
  flag=0

  for i in reversed(range(1,n+1)):
    stackA.append(i)

  for line in lines:
    line=line.strip().split()
    temp=int(line[0])
    if line[1]=='A' and line[2]=='B':
      if not stackA:
        flag=1
        break
      if stackA[-1] == temp:
        if not stackB:
          stackB.append(temp)
          stackA.pop()
        elif stackB[-1]>temp:
          stackB.append(temp)
          stackA.pop()
        else:
          flag=1
          break
    if line[1]=='A' and line[2]=='C':
      if not stackA:
        flag=1
        break
      if stackA[-1] == temp:
        if not stackC:
          stackC.append(temp)
          stackA.pop()
        elif stackC[-1]>temp:
          stackC.append(temp)
          stackA.pop()
        else:
          flag=1
          break
    if line[1]=='B' and line[2]=='A':
      if not stackB:
        flag=1
        break
      if stackB[-1] == temp:
        if not stackA:
          stackA.append(temp)
          stackB.pop()
        elif stackA[-1]>temp:
          stackA.append(temp)
          stackB.pop()
        else:
          flag=1
          break
    if line[1]=='B' and line[2]=='C':
      if not stackB:
        flag=1
        break
      if stackB[-1] == temp:
        if not stackC:
          stackC.append(temp)
          stackB.pop()
        elif stackC[-1]>temp:
          stackC.append(temp)
          stackB.pop()
        else:
          flag=1
          break
    if line[1]=='C' and line[2]=='A':
      if not stackC:
        flag=1
        break
      if stackC[-1] == temp:
        if not stackA:
          stackA.append(temp)
          stackC.pop()
        elif stackA[-1]>temp:
          stackA.append(temp)
          stackC.pop()
        else:
          flag=1
          break
    if line[1]=='C' and line[2]=='B':
      if not stackC:
        flag=1
        break
      if stackC[-1] == temp:
        if not stackB:
          stackB.append(temp)
          stackC.pop()
        elif stackB[-1]>temp:
          stackB.append(temp)
          stackC.pop()
        else:
          flag=1
          break

  if flag == 1:
    return False
  else:
    for num in range(1,n):
      if stackC[n-num] != num:
        flag=1
        break
    if flag == 1 :
      return False
    else :
      return True

def read_input(file_name):
  f=open(file_name,'r')
  lines=f.readlines()
  global n
  n=int(lines[0])


def evaluate(input_file, expected_output_file, actual_output_file):
  read_input(input_file)
  return read_output(actual_output_file)

if __name__ == '__main__':

  exit_code = 1

  if len(sys.argv) != 4:
    sys.exit(exit_code)
  result = evaluate(sys.argv[1], sys.argv[2], sys.argv[3])
  if result:
    exit_code = 0

  #print('Exit code = ', exit_code)
  sys.exit(exit_code)
