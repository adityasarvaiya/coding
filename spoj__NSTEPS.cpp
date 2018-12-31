#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n,x,y;    
    cin >> n;

    while (n--) {
        cin >> x;
        cin >> y;

        int x_ = 0, y_ = 0, x__, y__, count = 0;

        while (x_ < x || y_ < y) {
            
            x__ = x_ % 2;
            y__ = y_ % 2;
            
            if (x__ == 0 && y__ == 0 ) {
                ++x_;
                ++y_;
            } else if (x_ == y_) {
                ++x_;
                --y_;
            } else {
                --x_;
                ++y_;
            }

            ++count;

            // cout << "x " << x << "  y "<< y << " x_ " << x_ << " y_ " << y_ << " x__ " << x__ << " y__ " << y__ << " count "<< count << endl;
        }

        if (x_ == x && y_ == y) {
            cout << count << endl;
        } else {
            cout << "No Number" << endl;
        }
    }

    return  0;
}