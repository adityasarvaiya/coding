import sys

# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

def read_output(file_name):
  f = open(file_name, 'r')
  lines = f.readlines()

  lst = []

  for line in lines:
    if line.strip() != '':
      lst.append(line.strip())

  return lst

def read_input(file_name):
  f= open(file_name, 'r')
  lines = f.readlines()
  size = len(lines)
  edges = list()
  for i in range(1,size-1):
    if lines[i].strip()!= '':
      edges.append(lines[i].strip().split())
  li = list()
  li.append(lines[size-1].strip().split())
  li.append(edges)
  return li;

def evaluate(input_file, expected_output_file, actual_output_file):
  input_list_source_dest = read_input(input_file)
  expected_output = read_output(expected_output_file)
  actual_output= read_output(actual_output_file)
  flag =0
  if len(expected_output) == len(actual_output):
    for i in range(1,len(actual_output)):
      check_edge = list()
      check_edge.append(actual_output[i])
      check_edge.append(actual_output[i-1])
      check_edge_reverse = list(reversed(check_edge))
      if check_edge in input_list_source_dest[1]:
        continue
      elif check_edge_reverse in input_list_source_dest[1]:
        continue
      else:
        flag =1
        break
    if flag ==0:
      return True
    else:
      return False
  else:
    return False

if __name__ == '__main__':

  exit_code = 1

  if len(sys.argv) != 4:
    sys.exit(exit_code)
  result = evaluate(sys.argv[1], sys.argv[2], sys.argv[3])
  if result:
    exit_code = 0

  #print('Exit code = ', exit_code)
  sys.exit(exit_code)
