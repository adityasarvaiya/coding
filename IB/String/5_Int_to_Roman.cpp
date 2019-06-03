// https://www.interviewbit.com/problems/integer-to-roman/

string Solution::intToRoman(int A) {
    
    vector <pair<int, string>> ar;
    ar.push_back(make_pair(1, "I"));
    ar.push_back(make_pair(4, "IV"));
    ar.push_back(make_pair(5, "V"));
    ar.push_back(make_pair(9, "IX"));
    ar.push_back(make_pair(10, "X"));
    ar.push_back(make_pair(40, "XL"));
    ar.push_back(make_pair(50, "L"));
    ar.push_back(make_pair(90, "XC"));
    ar.push_back(make_pair(100, "C"));
    ar.push_back(make_pair(400, "CD"));
    ar.push_back(make_pair(500, "D"));
    ar.push_back(make_pair(900, "CM"));
    ar.push_back(make_pair(1000, "M"));

    int c,i,j;
    string ans;
    
    for (i = 12; i >= 0; --i) {
        c = A / ar[i].first;
        
        if (c > 0) {
            for (j = 0; j < c; ++j) {
                ans = ans + ar[i].second; 
            }
        }
        
        A = A - ar[i].first * c;
    }

    return ans;
}
