import sys

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def read_output(file_name):
  f = open(file_name, 'r')
  lines = f.readlines()

  lst = []
  s=""
  templst = []
  for line in lines:
    x=line.strip().split('\n')
    if x[0] == '' :
      if len(templst) > 0 :
         lst.append(templst)
         templst = []
    else :
      templst.append(x)
  if len(templst)>0 :
    lst.append(templst)
  res = sorted(lst)
  return res


def evaluate(input_file, expected_output_file, actual_output_file):
  return read_output(expected_output_file) == read_output(actual_output_file)

if __name__ == '__main__':

  exit_code = 1

  if len(sys.argv) != 4:
    sys.exit(exit_code)
  result = evaluate(sys.argv[1], sys.argv[2], sys.argv[3])
  if result:
    exit_code = 0

  #print('Exit code = ', exit_code)
  sys.exit(exit_code)
