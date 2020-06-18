import argparse
import sys
import os

def create_problem(id):
    function_id = str.lower(id[0])+id[1:]
    # print(function_id)
    problem_statement = id+'''

PROBLEM STATEMENT

INPUT


CONSTRAINTS


OUTPUT


=========
EXAMPLE 1
=========
Sample Input


Sample Output


Explanation

    '''
    python_format ='''def '''+function_id+'''():
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    pass

def main():
    pass

if __name__=="__main__":
    main()
'''
    cpp_format = '''#include <bits/stdc++.h>
using namespace std;

void '''+function_id+'''(){
    //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

    //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    return 
}


int main(){

}
'''

    java_format = '''import java.util.*;


class '''+id+'''{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
    }

    static void '''+function_id+'''(){
        //CRIO_SOLUTION_START_MODULE_L1_PROBLEMS

        
        //CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
    }
}
'''
    os.mkdir('./'+id)
    problem_dir = './'+id
    java = open(problem_dir+'/'+id+'.java','w+')
    java.write(java_format)
    java.close()
    python = open(problem_dir+'/'+id+'.py','w+')
    python.write(python_format)
    python.close()
    cpp = open(problem_dir+'/'+id+'.cpp','w+')
    cpp.write(cpp_format)
    cpp.close()

    os.mkdir('./'+id+'/tests')
    sample_input = open(problem_dir+'/tests/sample-input-1.txt','w+')
    sample_input.write('')
    sample_input.close()
    sample_output = open(problem_dir+'/tests/sample-output-1.txt','w+')
    sample_output.write('')
    sample_output.close()
    problem_st = open(problem_dir+'/problem.txt','w+')
    problem_st.write(problem_statement)
    problem_st.close()


if __name__ == "__main__":
    parser = argparse.ArgumentParser(prog='createProblem')
    parser.add_argument('-p','--problem',help='Problem ID of the new problem')
    args =  parser.parse_args()
    
    create_problem(args.problem)

    # USAGE
    # python3 createProblem.py -p PROBLEM_ID
