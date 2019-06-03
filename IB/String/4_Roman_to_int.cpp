// https://www.interviewbit.com/problems/roman-to-integer/

int value(char c) {
    if (c == 'I') { return 1; }
    if (c == 'V') { return 5; }
    if (c == 'X') { return 10; }
    if (c == 'L') { return 50; }
    if (c == 'C') { return 100; }
    if (c == 'D') { return 500; }
    if (c == 'M') { return 1000; }
}

int Solution::romanToInt(string A) {
    int l = A.length(), i, ans=0,c;
    
    for (i = 0; i < l; ++i) {
        c = 1;
        while (i < l-1 && A[i] == A[i+1]) {
            i++;
            c++;
        }
        
        if (i < l-1 && value(A[i]) < value(A[i+1])) {
            ans = ans - value(A[i]);
        } else {
            ans = ans + (value(A[i]) * c);
        }
    }
    
    return ans;
}
