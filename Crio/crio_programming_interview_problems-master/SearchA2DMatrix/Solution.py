
def solve(matrix,target):
    # CRIO_SOLUTION_START_MODULE_L1_PROBLEMS
    # the no of rows of the matrix is rows
    rows = len(matrix)

    # if the no of rows is 0 then no element is there and thus we return false
    if(rows == 0) :
        return False

    # the no of columns of the matrix is columns
    columns = len(matrix[0])

    # we start from the top right element of the matrix    
    present_row = 0 
    present_column = columns - 1
    
    # as long as we are inside the dimensions of the matrix we will continue to search the matrix
    while( present_row < rows and present_column >= 0):
            
            # the present no is 
            present_no = matrix[present_row][present_column]
            
            # if present_no is equals to the target then we have found the target and thus return true
            if(present_no == target):
                return True
            
            # if present_no is greater than the target then we need to step back a column
            elif(present_no > target):
                present_column -= 1
            
            # if present_no is lesser than the target then we need to move forward a row
            else:
                present_row += 1
    
    # if we have reached here then the element has not been found thus return false
    return False
    # CRIO_SOLUTION_END_MODULE_L1_PROBLEMS
