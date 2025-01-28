#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<int> tree;
    int n;

public:
    FenwickTree(int size) {
        n = size;
        tree.assign(n + 1, 0);
    }

    void update(int idx, int delta) {
        int tmp;
        while (idx <= n) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    int query(int idx) {
        int sum = 0;
        while (idx > 0) {
            sum += tree[idx];
            idx -= idx & -idx;
        }
        return sum;
    }

    int rangeQuery(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    vector<int> arr = {0, 1, 7, 3, 0, 2, 6};
    int n = arr.size() - 1;

    FenwickTree fenwick(n);

    // Build the Fenwick Tree
    for (int i = 1; i <= n; i++) {
        fenwick.update(i, arr[i]);
    }

    cout << "Sum of range [1, 3]: " << fenwick.rangeQuery(1, 3) << endl;

    fenwick.update(3, 5); // Add 5 to index 3
    cout << "After update, sum of range [1, 3]: " << fenwick.rangeQuery(1, 3) << endl;

    return 0;
}