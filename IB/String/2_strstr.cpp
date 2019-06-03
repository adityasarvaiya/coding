int* prefix(string B) {
    
    int l = B.length(), j = 0, i;
    int pre[l];
    pre[0] = 0;
    
    cout << 1;
    
    for (i = 1; i < l; ++i) {
        if (B[i] == B[j]) {
            ++j;
        } else {
            j = 0;
        }
        
        pre[i] = j;
    }
    
    return pre;
}

int Solution::strStr(const string A, const string B) {
    int i=0, j=0, l1 = A.length(), l2 = B.length();
    
    if (l1 == 0 || l2 == 0) {
        return -1;
    }
    
    int* pre = prefix(B);
    
    for (i = 0; i < l1; ++i) {
        if (A[i] == B[j]) {
            j++;
        } else {
            if (j != 0) {
                j = pre[j-1];
                --i;    
            }
        }
        
        if (j == l2) {
            return i - l2 + 1;
        }
    }
    
    return -1;
}
