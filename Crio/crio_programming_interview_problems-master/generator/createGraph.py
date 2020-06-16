import argparse
import os
from random import randint,choice,shuffle
from collections import defaultdict, deque

MAX_WEIGHT = 1e9

def default_value_list():
	return list()

def default_value_int():
	return -1

def get_distinct_values(number_of_nodes ,limit):
    values = set()
    while len(values) < number_of_nodes:
        values.add(randint(0,limit))
    values = list(values)
    return values

def output_formatting(type_of_graph ,number_of_nodes ,number_of_edges ,values ,components ,perm ,limit):
	output=""
	output+=str(number_of_nodes)+" "+str(number_of_edges)+"\n";
	if limit != -1:
		for val in values:
			output+=str(val)+" ";
		output+="\n";
	for edges in components :
		for edge in edges:
			if len(edge) == 3:
				if type_of_graph in ["balanced_tree","skew_tree","random_tree"]:
					if randint(0,1e9)%2 == 1:
						output+=str(edge[0])+' '+str(edge[1])+' '+str(edge[2])+'\n'
					else:
						output+=str(edge[1])+' '+str(edge[0])+' '+str(edge[2])+'\n'
				else:
					if randint(0,1e9)%2 == 1:
						output+=str(perm[edge[0]-1])+' '+str(perm[edge[1]-1])+' '+str(edge[2])+'\n'
					else:
						output+=str(perm[edge[1]-1])+' '+str(perm[edge[0]-1])+' '+str(edge[2])+'\n'
			else:
				if type_of_graph in ["balanced_tree","skew_tree","random_tree"]:
					if randint(0,1e9)%2 == 1:
						output+=str(edge[0])+' '+str(edge[1])+'\n'
					else:
						output+=str(edge[1])+' '+str(edge[0])+'\n'
				else:
					if randint(0,1e9)%2 == 1:
						output+=str(perm[edge[0]-1])+' '+str(perm[edge[1]-1])+'\n'
					else:
						output+=str(perm[edge[1]-1])+' '+str(perm[edge[0]-1])+'\n'
	return output

def permutation_map(number_of_nodes):
	perm = list()
	for i in range(1,number_of_nodes+1):
		perm.append(i)
	shuffle(perm)
	return perm

def create_set_for_distinct_edge_for_weighted_tree(edges):
	distinct_edge_set = set()
	for edge in edges:
		distinct_edge_set.add((edge[0],edge[1]))
	return distinct_edge_set

def choose_random_tree_type():
	tree_types = ["random","skew","balanced"]
	return choice(tree_types)

def create_tree(tree_type ,start_node_number ,end_node_number ,weighted ,negative_weight ,directed):
	edges = list()
	for i in range(start_node_number+1,end_node_number+1):
		if weighted:
			if negative_weight:
				if tree_type == "random":
					edges.append((i,randint(start_node_number,i-1),randint(-MAX_WEIGHT,MAX_WEIGHT)))
				elif tree_type == "skew":
					edges.append((i,i-1,randint(-MAX_WEIGHT,MAX_WEIGHT)))
				elif tree_type == "balanced":
					edges.append((i,i//2,randint(-MAX_WEIGHT,MAX_WEIGHT)))
			else:
				if tree_type == "random":
					edges.append((i,randint(start_node_number,i-1),randint(0,MAX_WEIGHT)))
				elif tree_type == "skew":
					edges.append((i,i-1,randint(0,MAX_WEIGHT)))
				elif tree_type == "balanced":
					edges.append((i,i//2,randint(0,MAX_WEIGHT)))
		else:
			if tree_type == "random":
				edges.append((i,randint(start_node_number,i-1)))
			elif tree_type == "skew":
				edges.append((i,i-1))
			elif tree_type == "balanced":
				edges.append((i,i//2))
	return edges

def split_tree_into_bipartite_sets(tree_edges ,start_node_number , end_node_number ,directed ):
	queue = deque()
	set1 = set()
	set2 = set()
	adjacency = defaultdict(default_value_list)
	for edge in tree_edges:
		adjacency[edge[0]].append(edge[1])
		if directed == False :
			adjacency[edge[1]].append(edge[0])
	visit = defaultdict(default_value_int)
	visit[tree_edges[0][0]] = 1
	set1.add(tree_edges[0][0])
	queue.append(tree_edges[0][0])
	while queue :
		top = queue.popleft()
		for node in adjacency[top]:
			if visit[node] == -1 :
				visit[node] = visit[top]+1
				if visit[node]%2 ==0 : 
					set2.add(node)
				else:
					set1.add(node)
				queue.append(node)
	set1 = list(set1)
	set2 = list(set2)
	bipartite_set_list = [set1,set2]

def create_edge_list(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed ,edges ,bipartite_split_set_list = [] ):
	#add edges to a set to create distinct edges only (distinct_edge_set)

	edges_with_weight = set(edges)	#set which holds the edges
	distinct_edge_set = create_set_for_distinct_edge_for_weighted_tree(edges)  #taken Because of finding if a certain edge is not already present
	
	while len(distinct_edge_set) < number_of_edges:
		if bipartite_split_set_list:
			index1=bipartite_split_set_list[0][randint(0,len(bipartite_split_set_list[0]))] #vertex1
			index2=bipartite_split_set_list[1][randint(0,len(bipartite_split_set_list[1]))]
		else:
			index1=randint(start_node_number,end_node_number) #vertex1
			index2=randint(start_node_number,end_node_number) #vertex2
		if index1 == index2 :  #for no self loop
			continue
		if weighted:
			if negative_weight:
				index3=randint(-MAX_WEIGHT,MAX_WEIGHT); #weight
			else:
				index3=randint(0,MAX_WEIGHT);	#weight

			if directed :
				if (index1,index2) not in distinct_edge_set :
					distinct_edge_set.add((index1,index2))
					edges_with_weight.add((index1,index2,index3))
			else :
				if index1 > index2:
					if (index1,index2) not in distinct_edge_set :
						distinct_edge_set.add((index1,index2))
						edges_with_weight.add((index1,index2,index3))
				else:
					if (index2,index1) not in distinct_edge_set :
						distinct_edge_set.add((index2,index1))
						edges_with_weight.add((index2,index1,index3))
		else:
			if directed :
				if (index1,index2) not in distinct_edge_set :
					distinct_edge_set.add((index1,index2))
					edges_with_weight.add((index1,index2))
			else :
				if index1 > index2:
					if (index1,index2) not in distinct_edge_set :
						distinct_edge_set.add((index1,index2))
						edges_with_weight.add((index1,index2))
				else:
					if (index2,index1) not in distinct_edge_set :
						distinct_edge_set.add((index2,index1))
						edges_with_weight.add((index2,index1))
	edges_with_weight=list(edges_with_weight)
	return edges_with_weight

#types_of_graph start

def random_graph(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed ):
	tree_type = choose_random_tree_type()
	tree_edges = create_tree(tree_type ,start_node_number ,end_node_number ,weighted ,negative_weight ,directed)
	return create_edge_list(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed ,tree_edges)	

def bipartite_graph(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed ):
	tree_type = choose_random_tree_type()
	tree_edges = create_tree(tree_type ,start_node_number ,end_node_number ,weighted ,negative_weight ,directed)
	split_set_list = split_tree_into_bipartite_sets(tree_edges ,start_node_number ,end_node_number ,directed)
	return create_edge_list(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed ,tree_edges ,split_set_list)

def balanced_tree(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed):
	return create_tree("balanced" ,start_node_number ,end_node_number ,weighted ,negative_weight ,directed)

def skew_tree(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed):
	return create_tree("skew" ,start_node_number ,end_node_number ,weighted ,negative_weight ,directed)

def random_tree(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed):
	return create_tree("random" ,start_node_number ,end_node_number ,weighted ,negative_weight ,directed)

def complete_graph(start_node_number ,end_node_number ,weighted ,negative_weight ,directed):
	#full complete graph implementation from start node to end node
	edges = list()
	if directed:
		if weighted:
			if negative_weight:
				for i in range(start_node_number,end_node_number+1):
					for j in range(start_node_number,end_node_number+1):
						if i == j:
							continue
						else:
							edges.append((i,j,randint(-MAX_WEIGHT,MAX_WEIGHT)))
			else:
				for i in range(start_node_number,end_node_number+1):
					for j in range(start_node_number,end_node_number+1):
						if i == j:
							continue
						else:
							edges.append((i,j,randint(0,MAX_WEIGHT)))
		else:
			for i in range(start_node_number,end_node_number+1):
				for j in range(start_node_number,end_node_number+1):
					if i == j:
						continue
					else:
						edges.append((i,j))
	else:
		if weighted:
			if negative_weight:
				for i in range(start_node_number,end_node_number+1):
					for j in range(i+1,end_node_number+1):
						edges.append((i,j,randint(-MAX_WEIGHT,MAX_WEIGHT)))
			else:
				for i in range(start_node_number,end_node_number+1):
					for j in range(i+1,end_node_number+1):
						edges.append((i,j,randint(0,MAX_WEIGHT)))
		else:
			for i in range(start_node_number,end_node_number+1):
				for j in range(i+1,end_node_number+1):
					edges.append((i,j))
	return edges

#types of graph end

def build(type_of_graph ,start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed ):
	if type_of_graph == "random" :
		return random_graph(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed )
	if type_of_graph == "complete" :
		return complete_graph(start_node_number ,end_node_number ,weighted ,negative_weight ,directed)
	if type_of_graph == "bipartite" :
		return bipartite_graph(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed)
	if type_of_graph == "balanced_tree" :
		return balanced_tree(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed)
	if type_of_graph == "random_tree" :
		return random_tree(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed)
	if type_of_graph == "skew_tree" :
		return skew_tree(start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed)
	

def connected_or_disconnected(type_of_graph ,number_of_nodes ,weighted ,negative_weight ,disconnected ,directed ):
	
	component_division_edge_list = list()	#list stores different components edge list
	total_number_of_edges = 0
	start_node_number = 0
	end_node_number = 0

	if disconnected:
		#create the number of components and then make divisions and make graph of that division
		number_of_component = randint(2,number_of_nodes) #number of components
		nodes_left = number_of_nodes	#number of nodes left to be assigned to a component
		for i in range(number_of_component):
			if i == number_of_component-1 :   
				division=nodes_left
			else:
				division = randint(1,nodes_left-(number_of_component-(i+1)))
			start_node_number = end_node_number +1 #next components starting node is equal to last components ending node +1
			end_node_number += division;
			nodes_left -= division
			if type_of_graph == "complete":
				number_of_edges = (division*(division-1))//2;
			elif type_of_graph in ["balanced_tree","skew_tree","random_tree"]:
				number_of_edges = division -1
			else:
				number_of_edges = randint(division-1,min((division*(division-1))//2,(division-1)+10000))
			total_number_of_edges += number_of_edges
			component_division_edge_list.append(build(type_of_graph ,start_node_number ,end_node_number ,number_of_edges ,weighted ,negative_weight ,directed ))
	else:
		start_node_number = 1
		end_node_number = number_of_nodes
		if type_of_graph in ["balanced_tree","skew_tree","random_tree"]:
			total_number_of_edges = number_of_nodes -1
		elif type_of_graph == "complete":
			total_number_of_edges = (number_of_nodes*(number_of_nodes-1))//2
		else:
			total_number_of_edges = randint(number_of_nodes-1 ,min((number_of_nodes*(number_of_nodes-1))//2 ,100000))#100000
		component_division_edge_list.append(build(type_of_graph ,start_node_number ,end_node_number ,total_number_of_edges ,weighted ,negative_weight ,directed ))
	
	edges_number_of_edges = list()  #list which stores the number of edges at [0] and a list of list of tuple od edges at [1]
	edges_number_of_edges.append(total_number_of_edges)
	edges_number_of_edges.append(component_division_edge_list)
	return  edges_number_of_edges

def pre_function(type_of_graph ,number_of_nodes ,weighted ,negative_weight ,distinct ,disconnected ,directed ,limit,edge_weight):
	global MAX_WEIGHT
	MAX_WEIGHT = edge_weight
	values=list()
	if limit != -1:
		if distinct :
			values = get_distinct_values(number_of_nodes ,limit)
		else :
			values = [randint(1,limit) for _ in range(number_of_nodes)]
	
	edges_list = connected_or_disconnected( type_of_graph ,number_of_nodes ,weighted ,negative_weight ,disconnected ,directed )
	print(edges_list)
	perm_array = permutation_map( number_of_nodes )
	return output_formatting(type_of_graph ,number_of_nodes ,edges_list[0] ,values ,edges_list[1] ,perm_array ,limit )

if __name__ == '__main__':
	parser = argparse.ArgumentParser(prog='createGraph.py',description='Create custom graph test-cases')
	parser.add_argument('-t','--type', help="Type of graph from options ['random','complete','bipartite','balanced_tree','skew_tree','random_tree']", required = True, type = str)
	parser.add_argument('-n','--num', help='Number of nodes', type = int, required = True)
	parser.add_argument('-w','--weighted',default=False, action='store_true', help = 'if graph is weighted or not')
	parser.add_argument('-nw','--negativeweight', default=False, action='store_true',help='if negative weight is allowed')
	parser.add_argument('-ew','--edgeweight',help='edge weight limit in the graph',type=int)
	parser.add_argument('-dt','--distinct', default=False, action='store_true', help='if value of nodes are distinct')
	parser.add_argument('-di','--disconnected', default=False, action='store_true', help='if graph is disconnected')
	parser.add_argument('-d','--directed' , default=False, action='store_true', help='if graph is directed')
	parser.add_argument('-l','--limit' ,help='upperlimit range of values for graph',type=int )
	parser.add_argument('-f','--filename' ,help='name of input file',type=str , required = True)
	args = parser.parse_args()
	output = pre_function(args.type,args.num,args.weighted,args.negativeweight,args.distinct,args.disconnected,args.directed,args.limit,args.edgeweight)
	#output = pre_function("complete",10,True,False,True,False,False,100)
	f = open(""+args.filename,"w")
	f.write(output)


'''
	usage 
	python3 -t {type of graph from ['random','complete','bipartite','balanced_tree','skew_tree','random_tree']} -n {number of nodes in graph} -l {upperlimit range of values for graph} -f {file name with extension}

	add -w if u want weighted
	add -nw if u want neagtive weighted
	add -dt if u want distinct value of nodes
	add -di if u want disconnected 
	add -d if u want directed
	add -ew NUMBER if u want to change the edge weight limit to NUMBER(For eg. -ew 100) 

	eg
	python3 createGraph.py -t complete -n 10 -w -dt -l 100 -f sample-input.txt
	complete graph with weights and distinct value of nodes
	
	Note: balanced_tree is balanced binary tree
	      Root of all tree ["balanced_tree","skew_tree","random_tree"] is 1.
	      Put limit -1 if you dont want values array.
		  Max Number of edges is 100000 (10^5)
		  For base input change the constraints for number of edges line 279 and 290 .
'''
