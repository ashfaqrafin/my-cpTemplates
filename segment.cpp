#include <vector>

// ========================= Lazy Segment Tree =========================

template <typename T, typename U>
class LazySegmentTree {
    int n;
    std::vector<T> tree;
    std::vector<U> lazy;

    T mergeValues(T left, T right) const {
        return left + right;
    }

    void apply(int node, int left, int right, U value) {
        tree[node] += static_cast<T>(value) * (right - left + 1);
        lazy[node] += value;
    }

    void push(int node, int left, int right) {
        if (lazy[node] == U{} || left == right) return;

        int middle = left + (right - left) / 2;
        apply(node * 2, left, middle, lazy[node]);
        apply(node * 2 + 1, middle + 1, right, lazy[node]);
        lazy[node] = U{};
    }

    void build(const std::vector<T>& values, int node, int left, int right) {
        if (left == right) {
            tree[node] = values[left - 1];
            return;
        }

        int middle = left + (right - left) / 2;
        build(values, node * 2, left, middle);
        build(values, node * 2 + 1, middle + 1, right);
        tree[node] = mergeValues(tree[node * 2], tree[node * 2 + 1]);
    }

    void rangeAdd(int node, int left, int right,
                  int queryLeft, int queryRight, U value) {
        if (queryRight < left || right < queryLeft) return;
        if (queryLeft <= left && right <= queryRight) {
            apply(node, left, right, value);
            return;
        }

        push(node, left, right);
        int middle = left + (right - left) / 2;
        rangeAdd(node * 2, left, middle, queryLeft, queryRight, value);
        rangeAdd(node * 2 + 1, middle + 1, right, queryLeft, queryRight, value);
        tree[node] = mergeValues(tree[node * 2], tree[node * 2 + 1]);
    }

    T rangeQuery(int node, int left, int right,
                 int queryLeft, int queryRight) {
        if (queryRight < left || right < queryLeft) return T{};
        if (queryLeft <= left && right <= queryRight) return tree[node];

        push(node, left, right);
        int middle = left + (right - left) / 2;
        T leftResult = rangeQuery(node * 2, left, middle, queryLeft, queryRight);
        T rightResult =
            rangeQuery(node * 2 + 1, middle + 1, right, queryLeft, queryRight);
        return mergeValues(leftResult, rightResult);
    }

public:
    explicit LazySegmentTree(const std::vector<T>& values)
        : n(static_cast<int>(values.size())),
          tree(4 * n + 1, T{}),
          lazy(4 * n + 1, U{}) {
        if (n > 0) build(values, 1, 1, n);
    }

    void rangeAdd(int left, int right, U value) {
        if (n > 0 && left <= right) rangeAdd(1, 1, n, left, right, value);
    }

    T rangeQuery(int left, int right) {
        if (n == 0 || left > right) return T{};
        return rangeQuery(1, 1, n, left, right);
    }
};
