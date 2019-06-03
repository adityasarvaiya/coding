int Solution::compareVersion(string A, string B) {

    long long i=0, j=0, l1=A.length(), l2=B.length(), a=0,b=0;
    int f = 0;
    
    while (true) {
        a=0; b=0;
        
        while (i < l1 && A[i] != '.') {
            a = a * 10 + A[i] - '0';
            i++;
        }
        
        while (j < l2 && B[j] != '.') {
            b = b * 10 + B[j] - '0';
            j++;
        }
        
        
        if (a > b) {
            return 1;
        } else if (a < b) {
            return -1;
        } 
        
        if (f == 1) {
            break;
        }
        
        i++;
        j++;
        
        if (i >= l1 || j >= l2) {
            f = 1;
        }
    }
    
    if (a > b) {
        return 1;
    } else if (a < b) {
        return -1;
    } else if (a == b) {            
        return 0;
    }

}
