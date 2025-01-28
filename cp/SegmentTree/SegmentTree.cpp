#include <iostream>
#include <vector>

using namespace std;

// Segment Tree class
class SegmentTree {
private:
    vector<int> tree;
    vector<int> arr;
    int n;

    // Build the segment tree
    void buildTree(int node, int start, int end) {
        if (start == end) {
            tree[node] = arr[start];
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            buildTree(leftChild, start, mid);
            buildTree(rightChild, mid + 1, end);

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    // Update a value in the array and segment tree
    void updateTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            arr[idx] = val;
            tree[node] = val;
        } else {
            int mid = (start + end) / 2;
            int leftChild = 2 * node + 1;
            int rightChild = 2 * node + 2;

            if (idx <= mid) {
                updateTree(leftChild, start, mid, idx, val);
            } else {
                updateTree(rightChild, mid + 1, end, idx, val);
            }

            tree[node] = tree[leftChild] + tree[rightChild];
        }
    }

    // Query a range sum
    int queryTree(int node, int start, int end, int l, int r) {
        if (start > r || end < l) {
            return 0; // Out of range
        }
        if (start >= l && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int leftChild = 2 * node + 1;
        int rightChild = 2 * node + 2;

        int leftSum = queryTree(leftChild, start, mid, l, r);
        int rightSum = queryTree(rightChild, mid + 1, end, l, r);

        return leftSum + rightSum;
    }

public:
    // Constructor
    SegmentTree(const vector<int>& input) {
        arr = input;
        n = arr.size();
        tree.resize(4 * n, 0);
        buildTree(0, 0, n - 1);
    }

    // Update function
    void update(int idx, int val) {
        updateTree(0, 0, n - 1, idx, val);
    }

    // Query function
    int query(int l, int r) {
        return queryTree(0, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTree segTree(arr);

    cout << "Sum of range (1, 3): " << segTree.query(1, 3) << endl;

    segTree.update(1, 10);
    cout << "After update, sum of range (1, 3): " << segTree.query(1, 3) << endl;

    return 0;
}
