#include <vector>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
struct FenwickTree {
    int n;
    std::vector<T> tree;

    // Empty constructor
    FenwickTree(int n = 0) : n(n), tree(n + 1, 0) {}

    // O(N) Construction from a 0-indexed vector
    FenwickTree(const vector<T>& a) : FenwickTree(a.size()) {
        for (int i = 1; i <= n; i++) {
            tree[i] += a[i - 1];
            int nxt = i + (i & -i); // parent node
            if (nxt <= n) {
                tree[nxt] += tree[i];
            }
        }
    }

    // Add 'val' to element at index i (1-based)
    // Time Complexity: O(log N)
    void add(int i, T val) {
        for (; i <= n; i += i & -i) {
            tree[i] += val;
        }
    }

    // Get sum of elements in range [1, i] (1-based)
    // Time Complexity: O(log N)
    T query(int i) const {
        T sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i];
        }
        return sum;
    }

    // Get sum of elements in range [l, r] (1-based)
    // Time Complexity: O(log N)
    T query(int l, int r) const {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};


int main() {
    // Original 0-indexed array
    vector<long long> arr = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};

    // Initialize Fenwick Tree
    FenwickTree<long long> bit(arr);

    // Query sum of range [1, 5] (1-based indices -> elements {2, 1, 1, 3, 2})
    cout << "Sum [1, 5]: " << bit.query(1, 5) << "\n"; // Output: 9

    // Add 5 to the 3rd element (1-based index 3, which is arr[2])
    bit.add(3, 5);

    // Query sum of range [1, 5] again
    cout << "Sum [1, 5] after update: " << bit.query(1, 5) << "\n"; // Output: 14

    return 0;
}
