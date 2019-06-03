#include <bits/stdc++.h>
using namespace std;

int findpriority(char c)
{
    if (c == '+') {
        return 1;
    } else if (c == '-') {
        return 2;
    } else if (c == '*') {
        return 3;
    } else if (c == '/') {
        return 4;
    } else if (c == '^') {
        return 5;
    } else if (c == '(') {
        return 0;
    } else if (c == ')') {
        return 7;
    }
}

int main(int argc, char const *argv[])
{
    int n, len, i, p;
    cin >> n;

    while (n--) {
        string str;
        string result = "";
        cin >> str;
        stack <char> st;
        
        len = str.length();

        for (i = 0; i < len; i++) {
            if (str[i] > 96 && str[i] < 123) {
                result.push_back(str[i]);
            } else {
                if (str[i] == '(') {
                    st.push('(');
                } else if (str[i] == ')') {
                    char ch = st.top(); 
                    st.pop();
                    while (ch != '(') {
                        result.push_back(ch);
                        
                        if (st.empty()) {
                            break;
                        } else {
                            ch = st.top();
                            st.pop();
                        }
                    }
                } else {
                    p = findpriority(str[i]);

                    if (!st.empty()) {
                        if (p < findpriority(st.top())) {
                            char ch = st.top();
                            st.pop();
                            while (p < findpriority(ch)) {
                                result.push_back(ch);
                                if (st.empty()) {
                                    break;
                                } else {
                                    ch = st.top();
                                    st.pop();
                                }
                            }
                            st.push(ch);
                        }
                    }

                    st.push(str[i]);
                }
            }
        }

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        cout << result << endl;
    }

    return 0;
}
