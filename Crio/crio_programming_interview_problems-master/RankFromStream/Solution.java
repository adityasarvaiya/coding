import java.util.*;

class SegmentTree {
    int start,end,value;
    SegmentTree left , right;
    SegmentTree(int s ,int e , int val) {
        start = s;
        end = e;
        value = val;
        left = null;
        right = null;
    }
    int query(int l ,int r) {
        if(start > r || end < l) {
            return 0;
        }
        if(l <= start && end <= r) {
            return value;
        }
        int leftAns = 0;
        if(left != null) {
            leftAns = left.query(l, r);
        }
        int rightAns = 0;
        if(right != null) {
            rightAns = right.query(l, r);
        }
        return (leftAns + rightAns);
    }
    void update(int index , int val) {
        if(start == end) {
            value += val;
            return;
        }
        int mid = (start + end)/2;
        if(start + 1 == end) {
            mid = start;
        }
        if(index <= mid) {
            if(left == null) {
                left = new SegmentTree(start , mid , 0);
            }
            left.update(index, val);
        } else {
            if(right == null) {
                right = new SegmentTree(mid + 1, end, 0);
            }
            right.update(index, val);
        }
        value = 0;
        if(left != null) {
            value += left.value;
        }
        if(right != null) {
            value +=right.value;
        }
    }
}

public class Solution {
    SegmentTree root;
    Solution() {
        root = new SegmentTree(0, 1000000000, 0);
    }
    void track(int x) {
        root.update(x, 1);
    }
    int getRankOfNumber(int x) {
        return root.query(0, x);
    }
}