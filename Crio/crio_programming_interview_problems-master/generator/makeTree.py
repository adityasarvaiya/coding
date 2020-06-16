import os
import subprocess
import sys
from random import choice

'''
Usage : python3 makeTree.py {no_of_test_cases} {no_of_nodes} {type_of_tree} {file_name} {distinct-flag} {optional->limit}
use random in type_of_tree as generating random tree
use bstrandom in type_of_tree as generating random bst tree
for distinct-flag input "yes" or "no"
for e.g 

python3 makeTree.py 5 7 balanced  /home/aman/Documents/compwtitive_coding/CrioProblemsetting/crio_mock_assessment_problems/MaxLeftRightSubtree/tests/base-input-1.txt no 10 

python3 makeTree.py 2 5 random base-input-1.txt no 10

'''

no_of_test_cases=sys.argv[1]
no_of_nodes=sys.argv[2]
type_of_tree=sys.argv[3]
file_name=sys.argv[4]
limit = 10000                                   # default limit 
distinct=True
if sys.argv[5] == "yes":
    distinct = True
elif sys.argv[5] == "no":
    distinct = False
if len(sys.argv)>6:
    limit=sys.argv[6]
os.system(f"echo '{no_of_test_cases}' > {file_name}")

types=['skew', 'randomize', 'balanced','lskew','rskew']
bst_types= ['bst-randomize','bst-skew']

for i in range(int(no_of_test_cases)):
    if type_of_tree == 'random':
        tree= choice(types)
        if distinct:
            os.system(f"python3 createTree.py -s {no_of_nodes} -t {tree} -l {limit} -d >> {file_name}")
        else:
            os.system(f"python3 createTree.py -s {no_of_nodes} -t {tree} -l {limit} >> {file_name}")
    elif type_of_tree == 'bstrandom':
        tree = choice(bst_types)
        os.system(f"python3 createTree.py -s {no_of_nodes} -t {tree} -l {limit} >> {file_name}")
    else:
        if distinct:
            os.system(f"python3 createTree.py -s {no_of_nodes} -t {type_of_tree} -l {limit} -d >> {file_name}")
        else:
            os.system(f"python3 createTree.py -s {no_of_nodes} -t {type_of_tree} -l {limit} >> {file_name}")
