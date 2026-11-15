#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// Binary lifting LCA for a tree with vertices [1, n].
// Add all edges, then call build(root).
struct TreeLCA {
    int n, logn;
    vector<vector<int>> adj, up;
    vector<int> depth;

    TreeLCA(int n) : n(n), logn(1), adj(n + 1), depth(n + 1) {
        while ((1LL << logn) <= n) ++logn;
        up.assign(logn, vector<int>(n + 1));
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void build(int root = 1) {
        vector<int> parent(n + 1);
        stack<int> st;
        st.push(root);
        parent[root] = root;
        up[0][root] = root;

        while (!st.empty()) {
            int u = st.top();
            st.pop();
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                up[0][v] = u;
                st.push(v);
            }
        }

        for (int j = 1; j < logn; ++j) {
            for (int v = 1; v <= n; ++v) {
                up[j][v] = up[j - 1][up[j - 1][v]];
            }
        }
    }

    int lift(int u, int k) const {
        for (int j = 0; j < logn; ++j) {
            if (k & (1 << j)) u = up[j][u];
        }
        return u;
    }

    int lca(int u, int v) const {
        if (depth[u] < depth[v]) swap(u, v);
        u = lift(u, depth[u] - depth[v]);
        if (u == v) return u;

        for (int j = logn - 1; j >= 0; --j) {
            if (up[j][u] != up[j][v]) {
                u = up[j][u];
                v = up[j][v];
            }
        }
        return up[0][u];
    }

    int distance(int u, int v) const {
        int w = lca(u, v);
        return depth[u] + depth[v] - 2 * depth[w];
    }
};

// Returns {farthest vertex, distance} from start.
pair<int, int> treeFarthest(const vector<vector<int>>& adj, int start) {
    vector<int> distance(adj.size(), -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;
    pair<int, int> result = {start, 0};

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (distance[u] > result.second) result = {u, distance[u]};

        for (int v : adj[u]) {
            if (distance[v] != -1) continue;
            distance[v] = distance[u] + 1;
            q.push(v);
        }
    }
    return result;
}

// The tree diameter as {endpoint1, endpoint2, number_of_edges}.
tuple<int, int, int> treeDiameter(const vector<vector<int>>& adj) {
    auto first = treeFarthest(adj, 1);
    auto second = treeFarthest(adj, first.first);
    return {first.first, second.first, second.second};
}
