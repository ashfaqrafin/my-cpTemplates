#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 4e18;


// ============================== Disjoint Set Union ==============================

// Stores connected components for 0-based vertices.
struct DSU {
    vector<int> parent, sz;

    DSU(int n) : parent(n), sz(n, 1) {
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        if (parent[u] == u) return u;
        return parent[u] = find(parent[u]);
    }

    bool unite(int u, int v) {
        u = find(u);
        v = find(v);
        if (u == v) return false;
        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
};
// DSU


// =========================== Graph Traversals ===========================

// Iterative DFS from start. Returns visited vertices in DFS order.
// The adjacency list must be 0-based.
vector<int> dfs(const vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    vector<int> order;
    stack<int> st;

    st.push(start);
    visited[start] = true;

    while (!st.empty()) {
        int u = st.top();
        st.pop();
        order.push_back(u);

        for (int v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                st.push(v);
            }
        }
    }
    return order;
}
// dfs

// Recursive DFS helper. Call dfsRecursive(start, adj, visited, order).
// This visits each reachable vertex once.
void dfsRecursive(int u,
                  const vector<vector<int>>& adj,
                  vector<bool>& visited,
                  vector<int>& order) {
    visited[u] = true;
    order.push_back(u);

    for (int v : adj[u]) {
        if (!visited[v]) dfsRecursive(v, adj, visited, order);
    }
}
// dfsRecursive

// BFS from start. Returns the shortest number of edges from start.
// Unreachable vertices have distance -1.
vector<int> bfs(const vector<vector<int>>& adj, int start) {
    int n = adj.size();
    vector<int> distance(n, -1);
    queue<int> q;

    distance[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            if (distance[v] == -1) {
                distance[v] = distance[u] + 1;
                q.push(v);
            }
        }
    }
    return distance;
}
// bfs


// =========================== Bipartite Graph ===========================

// Returns true when every connected component can use two colors.
// An edge between equal colors means the graph is not bipartite.
bool bipartite(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> color(n, -1);

    for (int start = 0; start < n; ++start) {
        if (color[start] != -1) continue;

        queue<int> q;
        color[start] = 0;
        q.push(start);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (color[v] == -1) {
                    color[v] = color[u] ^ 1;
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}
// bipartite

// Recursive bipartite helper. Start by assigning color 0 to u.
// Pass -1 as the initial color of every vertex.
bool bipartiteRecursive(int u,
                        int color,
                        const vector<vector<int>>& adj,
                        vector<int>& colors) {
    colors[u] = color;

    for (int v : adj[u]) {
        if (colors[v] == -1) {
            if (!bipartiteRecursive(v, color ^ 1, adj, colors)) return false;
        } else if (colors[v] == colors[u]) {
            return false;
        }
    }
    return true;
}
// bipartiteRecursive helper

// Recursive bipartite check for the whole graph.
bool bipartiteRecursive(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> colors(n, -1);

    for (int u = 0; u < n; ++u) {
        if (colors[u] == -1 &&
            !bipartiteRecursive(u, 0, adj, colors)) {
            return false;
        }
    }
    return true;
}
// bipartiteRecursive


// =========================== Grid Traversal ===========================

// Recursive DFS helper for a grid using four directions.
// '#' is blocked. Mark visited and fill order before recursive calls.
void gridDfs(const vector<string>& grid,
             int r,
             int c,
             vector<vector<bool>>& visited,
             vector<pair<int, int>>& order) {
    int n = grid.size();
    int m = grid[0].size();
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    visited[r][c] = true;
    order.push_back({r, c});

    for (int k = 0; k < 4; ++k) {
        int nr = r + dr[k];
        int nc = c + dc[k];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
        if (grid[nr][nc] == '#' || visited[nr][nc]) continue;

        gridDfs(grid, nr, nc, visited, order);
    }
}
// gridDfs

// BFS in a grid using four directions.
// '#' is blocked and unreachable cells have distance -1.
vector<vector<int>> gridBfs(const vector<string>& grid, int sr, int sc) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> distance(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    distance[sr][sc] = 0;
    q.push({sr, sc});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int k = 0; k < 4; ++k) {
            int nr = r + dr[k];
            int nc = c + dc[k];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (grid[nr][nc] == '#' || distance[nr][nc] != -1) continue;

            distance[nr][nc] = distance[r][c] + 1;
            q.push({nr, nc});
        }
    }
    return distance;
}
// gridBfs


// =========================== Shortest Paths ===========================

// Dijkstra for non-negative weighted directed or undirected edges.
// Returns INF for unreachable vertices.
vector<ll> dijkstra(const vector<vector<pair<int, ll>>>& adj, int start) {
    int n = adj.size();
    vector<ll> distance(n, INF);
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;

    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [du, u] = pq.top();
        pq.pop();
        if (du != distance[u]) continue;

        for (auto [v, w] : adj[u]) {
            if (distance[v] > du + w) {
                distance[v] = du + w;
                pq.push({distance[v], v});
            }
        }
    }
    return distance;
}
// dijkstra


// =========================== Directed Graph ===========================

// Kahn's algorithm for a 0-based directed graph.
// Returns an empty vector if the graph contains a cycle.
vector<int> topologicalSort(const vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n, 0);

    for (int u = 0; u < n; ++u) {
        for (int v : adj[u]) ++indegree[v];
    }

    queue<int> q;
    for (int u = 0; u < n; ++u) {
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

    if ((int) order.size() != n) return {};
    return order;
}
// topologicalSort
