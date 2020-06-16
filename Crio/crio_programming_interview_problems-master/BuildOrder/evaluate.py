# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

import sys
from collections import defaultdict
def read_output(file_name):
  f = open(file_name, 'r')
  lines = f.readlines()

  lst = []
  if(lines[0].strip()!=''):
    lst = list(lines[0].split())
  return lst

def read_input(file_name):
  f= open(file_name, 'r')
  lines = f.readlines()

  edges = []
  edges.append(list(map(int,lines[0].split())))
  for line in lines[2:]:
    if(line.strip()!=''):
      edges.append(list(line.split()))
  return edges

def evaluate(input_file, expected_output_file, actual_output_file):
  edges = read_input(input_file)
  expected_output = read_output(expected_output_file)
  output= read_output(actual_output_file)
  n,e = edges[0]
  if(len(output) != len(expected_output)):
    return False
  if(expected_output[0]=="-1"):
    if(output[0]=="-1"):
      return True
    else:
      return False

  idx = defaultdict(int)
  for i in range(n):
    idx[output[i]] = i+1
  for edge in edges[1:]:
    if(idx[edge[0]] > idx[edge[1]]):
      return False
  if(len(idx)==n):
    return True
  return False

if __name__ == '__main__':

  exit_code = 1

  if len(sys.argv) != 4:
    sys.exit(exit_code)
  result = evaluate(sys.argv[1], sys.argv[2], sys.argv[3])
  if result:
    exit_code = 0

  sys.exit(exit_code)
