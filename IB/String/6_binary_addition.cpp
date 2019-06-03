// https://www.interviewbit.com/problems/add-binary-strings/

string Solution::addBinary(string A, string B) {
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    int l1 = A.length(), l2 = B.length(), i, j, c=0, sum=0;
    string res;
    
    for (i=0, j=0; i<l1 && j<l2; ++i, ++j) {
        sum = c + (A[i] - '0') + (B[j] - '0');
        
        if (sum == 0) {
            c = 0;
            res.push_back(0 + '0');
        }else if (sum == 1) {
            c = 0;
            res.push_back(1 + '0');
        } else if (sum == 2) {
            c = 1;
            res.push_back(0 + '0');
        } else if (sum == 3) {
            c = 1;
            res.push_back(1 + '0');
        } 
    } 
    
    string leftover;
    if (l1 > l2) {
        leftover = A.substr(i,l1-i+1);
    } else {
        leftover = B.substr(j,l2-j+1);
    }
    
    int l = leftover.length();
    for (i=0; i<l; ++i) {
        sum = c + (leftover[i] - '0');
        
        if (sum == 0) {
            c = 0;
            res.push_back(0 + '0');
        }else if (sum == 1) {
            c = 0;
            res.push_back(1 + '0');
        } else if (sum == 2) {
            c = 1;
            res.push_back(0 + '0');
        } else if (sum == 3) {
            c = 1;
            res.push_back(1 + '0');
        } 
    }
    
    
    if (c == 1) {
        res.push_back(1 + '0');
    }
    
    reverse(res.begin(), res.end());
    
    return res;
}
