// https://practice.geeksforgeeks.org/problems/column-name-from-a-given-column-number/0
// https://leetcode.com/problems/excel-sheet-column-number/submissions/

#include <bits/stdc++.h>
using namespace std;

int main() {


    int t;
    scanf("%d", &t);
    while(t--) {
        int number;
        scanf("%d", &number);
        
        char column[20];
        int i =0;
        
        while(number > 0) {
            column[i++] = 65 + (--number % 26);
            number = number / 26;
        }
    
        while(i--) {
            printf("%c", column[i]);
        }
        
        printf("\n");
    }
    return 0;
}