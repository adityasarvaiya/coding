import argparse
import os
from random import randint,choice,shuffle
from collections import defaultdict

'''
utility function
'''

def formatting(nodes, values, matrix):
    return str(nodes) + '\n' + ' '.join(map(str,values)) + '\n' + '\n'.join( ' '.join(map(str,row)) for row in matrix)

def get_matrix_from_parent_array(parent, nodes):
    tree = defaultdict(list)
    for node in range(nodes+1):
        tree[node] = []
    for index, node in enumerate(parent):
        tree[node].append(index+1)
    # for node in tree.values():
    #     assert(len(node)<=2)                # if this fails then tree is not a binary tree
    matrix = list()
    for index, node in enumerate(tree.values()):
        cur=[index]
        child = [-1,-1]
        if len(node)==2:
            child=node
        if len(node) == 1:
            child[0]=node[0]
            shuffle(child)
        matrix.append(cur+ child)
    return matrix[1:]

def get_bst_matrix_from_parent_array(parent, values,  nodes):
    tree = defaultdict(list)
    for node in range(nodes+1):
        tree[node] = []
    for index, node in enumerate(parent):
        tree[node].append(index+1)
    # for node in tree.values():
    #     assert(len(node)<=2)                # if this fails then tree is not a binary tree
    matrix = list()
    for index, node in enumerate(tree.values()):
        cur=[index]
        child = [-1,-1]
        if index==0:
            matrix.append(cur+ child)
            continue
        if len(node) >= 1:
            if values[node[0]-1] < values[index-1]:
                child[0]=node[0]
            elif values[node[0]-1] > values[index-1]:
                child[1]=node[0]
        if len(node) >= 2: 
            if values[node[1]-1] < values[index-1]:
                child[0]=node[1]
            elif values[node[1]-1] > values[index-1]:
                child[1]=node[1]
        assert(len(node)==2-child.count(-1))
        matrix.append(cur+ child)
    return matrix[1:]

class Tree(object):
    def __init__(self,val):
        self.left = None
        self.right = None
        self.data = val

def sortedArraytoBST(a,start,end):
    if start > end:
        return None
    mid = randint(start,end)
    root= Tree(a[mid])
    root.left = sortedArraytoBST(a,start,mid-1)
    root.right = sortedArraytoBST(a,mid+1,end)
    return root 

def isValidBST(root, low=-10**9, high=10**9):
    if root == None:
        return True
    if root.data < low or root.data > high:
        return False
    return isValidBST(root.left, low, root.data) and isValidBST(root.right, root.data, high)

def traverse(root,parent,par):
    values = list()
    values.append(root.data)
    parent.append(par)
    par = len(parent)-1
    if root.left != None:
        x,y=traverse(root.left,parent,par)
        # parent.extend(y)
        values.extend(x)
    if root.right != None:
        x,y=traverse(root.right,parent,par)
        values.extend(x)
        # parent.extend(y)
    return values,parent

def get_distinct_values(nodes,limit):
    values = set()
    while len(values)<nodes:
        values.add(randint(1,limit))
    values = list(values)
    return values

'''
Parent array creation section
'''

def get_skew_matrix(nodes,treetype):
    matrix = list()
    for node in range(1,nodes):
        childs = [node+1, -1]            # by default lskew
        if treetype == 'skew':
            shuffle(childs)
        elif treetype == 'rskew':
            childs = childs[::-1]
        cur= [node] + childs
        matrix.append(cur)
    matrix.append([nodes,-1,-1])
    return matrix

def get_balanced_matrix(nodes):
    matrix = list()
    for node in range(1,nodes+1):
        matrix.append([node ,-1,-1])
    for node in range(2,nodes+1):
        matrix[node//2 - 1][1+node%2]=node
    return matrix

def random_parent_array(nodes):
    if nodes == 1:
        return [0]
    lis=[0,1]
    while len(lis)<nodes:
        if(lis[-1]==lis[-2]):
            lis.append(lis[-1]+1)
        else:
            lis.append(lis[-1]+randint(0,1))
    return lis

def get_random_matrix(nodes):
    parent = random_parent_array(nodes)
    if nodes == 1:
        return [1,-1,-1]
    matrix = get_matrix_from_parent_array(parent, nodes)
    return matrix


def get_bst_matrix(nodes, parent):
    pass

'''
Tree building section
'''


def build_skew_tree(nodes,limit,distinct,treetype):
    values=list()
    if distinct:
        values = get_distinct_values(nodes,limit)
    else:
        values = [randint(1,limit) for _ in range(nodes)]
    matrix = get_skew_matrix(nodes,treetype)
    output_format = formatting(nodes, values, matrix)
    return output_format


def build_balanced_tree(nodes,distinct, limit):
    values=list()
    if distinct:
        values = get_distinct_values(nodes,limit)
    else:
        values = [randint(1,limit) for _ in range(nodes)]
    matrix = get_balanced_matrix(nodes)
    output_format = formatting(nodes,values,matrix)
    return output_format

def build_random_tree(nodes,distinct, limit):
    values=list()
    if distinct:
        values = get_distinct_values(nodes,limit)
    else:
        values = [randint(1,limit) for _ in range(nodes)]
    matrix = get_random_matrix(nodes)
    output_format = formatting(nodes,values,matrix)
    return output_format

def build_bst_random_tree(nodes,limit):
    values = set()
    while len(values)<nodes:
        values.add(randint(1,limit))
    values = list(values)
    values.sort()
    root = sortedArraytoBST(values , 0, nodes - 1)
    assert isValidBST(root) == True
    values, parent =  traverse(root, [], -1)
    parent = [(i+1) for i in parent]
    matrix = get_bst_matrix_from_parent_array(parent ,values, nodes)
    output_format = formatting(nodes,values,matrix)
    return output_format

def build_bst_skew_tree(nodes, limit):
    values = set()
    while len(values)<nodes:
        values.add(randint(1,limit))
    values = list(values)
    values.sort()
    parent = list(range(nodes))
    if randint(0,1) == 1:
        values.reverse()
    matrix = get_bst_matrix_from_parent_array(parent, values, nodes)
    output_format = formatting(nodes,values,matrix)
    return output_format

def custom_create_tree():
    # we can create a custom tree here.
    pass



def build(treetype, nodes, distinct, limit = 10000):
    assert treetype in ['skew', 'randomize', 'balanced','lskew','rskew','bst-randomize','bst-skew']
    if distinct == "yes":
        assert limit >= nodes , "Enter greater limit size while using more number of nodes and distinct"
    output = ""
    if treetype in ['skew','rskew','lskew']:
        output = build_skew_tree(nodes, limit,distinct, treetype)
    elif treetype == 'randomize':
        output = build_random_tree(nodes,distinct, limit)
    elif treetype == 'balanced':
        output = build_balanced_tree(nodes,distinct, limit)
    elif treetype == 'bst-randomize':
        output = build_bst_random_tree(nodes, limit)
    elif treetype == 'bst-skew':
        output = build_bst_skew_tree(nodes, limit)
    print(output)



if __name__ == '__main__':
    parser = argparse.ArgumentParser(prog='createTree.py',description='Create custom Tree test-cases',epilog='This version creates a single tree right now')
    parser.add_argument('-v', '--version', action='version', version='%(prog)s 1.0')
    parser.add_argument('-t', '--type', help="Type of tree from options ['randomize','balanced','skew','lskew','rskew','bst-randomize','bst-skew']", required = True, type = str)
    parser.add_argument('-s', '--size', help='Number of nodes', type = int, required = True)
    parser.add_argument('-d', '--distinct', action = 'store_true', help = 'For distinct values in tree')
    parser.add_argument('-l', '--limit' ,metavar='num',help='upperlimit range of values for tree',type=int)
    args = parser.parse_args()

    if args.limit == None:
        build(args.type,args.size,args.distinct)
    else:
        build(args.type,args.size,args.distinct,args.limit)



'''
TODOS:
        To make multiple tree for number of test cases
        To get the height of the tree after generation for specific purposes
 ...
'''