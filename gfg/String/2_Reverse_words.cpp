#include<iostream>
#include <boost/algorithm/string.hpp>
using namespace std;

string find(string st) {
    vector <string> result;
    vector <string> :: reverse_iterator it;
    string res;
    
    boost:: split(result, st, boost::is_any_of("."));
    
    for (it = result.rbegin(); it != result.rend(); ++it) {
        res += *it;

        if (it != result.rend() - 1) {
            res += '.';
        }
    }
    
    return res;
}

int main()
{
	int t;
    cin >> t;

    while (t--) {
        string st;
        cin >> st;

        cout << find(st) << endl;
    }
	
	return 0;
}