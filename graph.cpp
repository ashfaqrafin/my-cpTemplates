#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = numeric_limits<ll>::max() / 4;

struct DSU {
    vector<int> parent, size;

    DSU(int n) : parent(n + 1), size(n + 1, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return parent[u] == u ? u : parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (size[u] < size[v]) swap(u, v);
        parent[v] = u;
        size[u] += size[v];
        return true;
    }
};

// Depth-first traversal from start. Unreachable vertices are omitted.
vector<int> dfs(const vector<vector<int>>& adj, int start) {
    vector<bool> visited(adj.size());
    vector<int> order;
    stack<int> st;
    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        order.push_back(u);

        for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
            int v = *it;
            if (visited[v]) continue;
            visited[v] = true;
            st.push(v);
        }
    }
    return order;
}

// Four-direction grid BFS. '#' is blocked; unreachable cells have distance -1.
vector<vector<int>> gridBfs(const vector<string>& grid, pair<int, int> start) {
    if (grid.empty() || grid[0].empty()) return {};
    int n = grid.size();
    int m = grid[0].size();
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};
    vector<vector<int>> distance(n, vector<int>(m, -1));
    queue<pair<int, int>> q;

    auto [sr, sc] = start;
    if (sr < 0 || sr >= n || sc < 0 || sc >= m || grid[sr][sc] == '#') {
        return distance;
    }

    q.push(start);
    distance[sr][sc] = 0;
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#' || distance[nr][nc] != -1) continue;
            distance[nr][nc] = distance[r][c] + 1;
            q.push({nr, nc});
        }
    }
    return distance;
}

// Four-direction grid DFS. '#' is blocked; returns visited cells in DFS order.
vector<pair<int, int>> gridDfs(const vector<string>& grid, pair<int, int> start) {
    if (grid.empty() || grid[0].empty()) return {};
    int n = grid.size();
    int m = grid[0].size();
    const int dr[] = {-1, 1, 0, 0};
    const int dc[] = {0, 0, -1, 1};
    vector<vector<bool>> visited(n, vector<bool>(m));
    vector<pair<int, int>> order;
    stack<pair<int, int>> st;

    auto [sr, sc] = start;
    if (sr < 0 || sr >= n || sc < 0 || sc >= m || grid[sr][sc] == '#') {
        return order;
    }

    st.push(start);
    visited[sr][sc] = true;
    while (!st.empty()) {
        auto [r, c] = st.top();
        st.pop();
        order.push_back({r, c});
        for (int k = 3; k >= 0; --k) {
            int nr = r + dr[k], nc = c + dc[k];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#' || visited[nr][nc]) continue;
            visited[nr][nc] = true;
            st.push({nr, nc});
        }
    }
    return order;
}

// Unweighted shortest paths from start. Unreachable vertices have distance -1.
vector<int> bfs(const vector<vector<int>>& adj, int start) {
    vector<int> distance(adj.size(), -1);
    queue<int> q;
    q.push(start);
    distance[start] = 0;

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : adj[u]) {
            if (distance[v] != -1) continue;
            distance[v] = distance[u] + 1;
            q.push(v);
        }
    }
    return distance;
}

// Single-source shortest paths for non-negative edge weights.
vector<ll> dijkstra(const vector<vector<pair<int, ll>>>& adj, int start) {
    vector<ll> distance(adj.size(), INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                   greater<pair<ll, int>>>
        pq;
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [currentDistance, u] = pq.top();
        pq.pop();
        if (currentDistance != distance[u]) continue;

        for (auto [v, weight] : adj[u]) {
            if (distance[v] > currentDistance + weight) {
                distance[v] = currentDistance + weight;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}

// Kahn's algorithm. Returns an empty vector if the graph has a cycle.
vector<int> topologicalSort(const vector<vector<int>>& adj) {
    int n = static_cast<int>(adj.size()) - 1;
    vector<int> indegree(n + 1);
    for (int u = 1; u <= n; ++u) {
        for (int v : adj[u]) ++indegree[v];
    }

    queue<int> q;
    for (int u = 1; u <= n; ++u) {
        if (indegree[u] == 0) q.push(u);
    }

    vector<int> order;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        order.push_back(u);
        for (int v : adj[u]) {
            if (--indegree[v] == 0) q.push(v);
        }
    }

    if (static_cast<int>(order.size()) != n) return {};
    return order;
}
