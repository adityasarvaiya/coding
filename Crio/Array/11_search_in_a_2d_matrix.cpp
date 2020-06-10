// Two - pointer solution
// SC : O( 1 )
// TC : O( n + m ) // where n and m is the no of rows and no of columns of the 2d grid matrix

bool answer(vector<vector<long long > > &matrix , long long target)
{
    // the no of rows of the matrix is rows
    long long int rows = matrix.size();

    // if the no of rows is 0 then no element is there and thus we return false
    if( rows == 0 )
        return false;

    // the no of columns of the matrix is columns
    long long int columns = matrix[0].size();

    // we start from the top right element of the matrix    
    long long int present_row = 0, present_column = columns - 1;
    
    // as long as we are inside the dimensions of the matrix we will continue to search the matrix
    while( present_row < rows && present_column >= 0){
            
            // the present no is 
            long long int present_no = matrix[present_row][present_column];
            
            // if present_no is equals to the target then we have found the target and thus return true
            if( present_no == target)
                return true;
            // if present_no is greater than the target then we need to step back a column
            else if(present_no > target){
                present_column--;
            }
            // if present_no is lesser than the target then we need to move forward a row
            else
                present_row++;;
    }
    
    // if we have reached here then the element has not been found thus return false
    return false;
}
