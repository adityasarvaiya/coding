import sys

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS


row =0
col =0
def read_output(file_name):
  f = open(file_name, 'r')
  lines = f.readlines()

  lst = []
  try :
    for line in lines:
      if line.strip() != '':
        lst.append(list(map(int , line.strip().split())))

    return lst
  except :
    return False

def read_input(file_name):
  f= open(file_name,'r')
  lines = f.readlines()
  try :
    input1 = []
    val = 1
    for line in lines:
      if val == 1 :
        val = val+1
        temp = line.strip().split()
        global row
        global col 
        row = int(temp[0])
        col = int(temp[1])
      else:
        input1.append(list(map(int , line.strip().split())))
    return input1
  except :
    return False


def evaluate(input_file, expected_output_file, actual_output_file):
  output = read_output(actual_output_file)
  input1 = read_input(input_file)
  myout = read_output(expected_output_file)
  if myout == output :
    return True
  if input1 == False or output == False :
    return False
  if myout == False:
    return False
  outlen = len(output)
  if output[0] != [1,1] or output[-1] != [row,col]:
    return False
  curx = 1
  cury = 1
  for i in range(1,outlen):
    try : 
      x = output[i][0]
      y = output[i][1]
      if x > row or x < 1 :
        return False
      if y > col or y < 1 :
        return False
      if curx != x and cury != y :
        return False
      if x < curx or y < cury :
        return False
      if x - curx + y - cury != 1 :
        return False
      if input1[x-1][y-1] == 1 :
        return False
      curx = x
      cury = y
    except:
      return False
  return True  


if __name__ == '__main__':

  exit_code = 1

  if len(sys.argv) != 4:
    sys.exit(exit_code)
  result = evaluate(sys.argv[1], sys.argv[2], sys.argv[3])
  if result:
    exit_code = 0
  sys.exit(exit_code)
