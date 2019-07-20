#include <bits/stdc++.h>
using namespace std;

vector<string> subdomainVisits(vector<string>& A) {
    unordered_map <string, int> h;
    int l = A.size(), vis;
    
    for (int i = 0; i < l; ++i) {
        vector <string> B;
        sscanf(A[i].c_str(), "%d", &vis);
        
        char *in;
        strcpy(in, A[i].c_str());
        char *toks = strtok(in, " ");
        toks = strtok(NULL, " ");
        
        char *domains = strtok(toks, ".");
        
        while (domains != NULL) {
            B.push_back(string(domains));
            domains = strtok(NULL, ".");
        }
        
        cout << "DObn" << endl;
        
        // for (int j = 0; j < B.size(); ++j) {
        //     string s = B[j];
        //     for (int k = j+1; k < B.size(); ++k) {
        //         s = s + "." + B[k];
        //     }
        
        //     if (h.find(s) == h.end()) {
        //         h[s] = vis;
        //     } else {
        //         h[s] += vis;
        //     }
        // }
    }
    
    vector <string> ans;
    
    // for(auto x : h) {
    //     ans.push_back(to_string(x.second) + " " + x.first);
    // }
    
    return ans;
}

int main() 
{ 
    vector <string> s;
    s.push_back("9001 discuss.leetcode.com");
	subdomainVisits(s);
	return 0; 
} 
