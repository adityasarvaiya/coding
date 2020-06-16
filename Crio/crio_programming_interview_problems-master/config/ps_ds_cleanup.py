import os

def get_list_of_all_problems(this_dir):
    f = open(os.path.join(this_dir, 'config/list_of_problems.txt'))
    all_problems = f.readlines()
    all_problems = [one_problem.strip() for one_problem in all_problems]
    f.close()
    return all_problems

def main(this_dir):
    all_problems = get_list_of_all_problems(this_dir)
    dirs_to_keep= ['crio', 'config', '.git']
    dirs_to_keep.extend(all_problems)
    all_files = [ name for name in os.listdir(os.getenv('PWD')) if os.path.isdir(os.path.join(os.getenv('PWD'), name)) ]
    for one_problem in all_files:
        #print("This problem = ", one_problem, type(one_problem))
        if one_problem in dirs_to_keep:
            if one_problem in all_problems:
                for one_test_type in ['perf', 'base', 'edge']:
                    os.system('rm  {}/tests/{}-*.txt'.format(one_problem, one_test_type))
                for one_pattern in ['actual-*', '*.out', '*.pyc', '*.class']:
                    os.system('rm {}/{}'.format(one_problem, one_pattern))
        else:
            os.system('rm -rf {}'.format(one_problem))


if __name__ == '__main__':
    this_dir = '/Users/keerthanaa/workspace/crio/ME_INTERVIEW_PREP/crio_programming_interview_problems'
    main(this_dir)
