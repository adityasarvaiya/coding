# CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
# CRIO_SOLUTION_END_MODULE_L1_PROBLEMS

import sys
def read_output(file_name):
  f = open(file_name, 'r')
  lines = f.readlines()

  lst = []
  if(lines[0].strip()!=''):
    lst = list(map(int,lines[0].split()))
  return lst

def read_input(file_name):
  f= open(file_name, 'r')
  lines = f.readlines()

  edges = []
  for line in lines:
    if(line.strip()!=''):
      edges.append(list(map(int,line.split())))
  return edges

def evaluate(input_file, expected_output_file, actual_output_file):
  edges = read_input(input_file)
  # expected_output = read_output(expected_output_file)
  output= read_output(actual_output_file)
  n,e = edges[0]
  if(len(output)!=n):
    return False
  adj = [[] for _ in range(n+1)]
  indegree = [0]*(n+1)
  for edge in edges[1:]:
    indegree[edge[1]]+=1
    adj[edge[0]].append(edge[1])
  vis = set()
  for node in output:
    if (node in vis):
      return False
    else:
      vis.add(node)
    if(indegree[node]>0):
      return False
    else:
      for child in adj[node]:
        indegree[child]-=1

  if(len(vis)==n):
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
