#include <iostream>

using namespace std;

int main() 
{
    int in;

    while (true) {
        cin >> in;
        if (in == 42) {
            break;
        } 

        cout << in << endl;
    }
}