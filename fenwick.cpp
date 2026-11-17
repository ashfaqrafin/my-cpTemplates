#include <vector>

// ========================== Fenwick Tree (1-based) ==========================

template <typename T>
struct FenwickTree {
    int n;
    std::vector<T> tree;

    explicit FenwickTree(int n = 0) : n(n), tree(n + 1, T{}) {}

    explicit FenwickTree(const std::vector<T>& values)
        : FenwickTree(static_cast<int>(values.size())) {
        for (int i = 1; i <= n; ++i) {
            tree[i] += values[i - 1];
            int parent = i + (i & -i);
            if (parent <= n) tree[parent] += tree[i];
        }
    }

    void add(int i, T value) {
        for (; i <= n; i += i & -i) tree[i] += value;
    }

    T query(int i) const {
        T result{};
        for (; i > 0; i -= i & -i) result += tree[i];
        return result;
    }

    T query(int left, int right) const {
        if (left > right) return T{};
        return query(right) - query(left - 1);
    }
};
