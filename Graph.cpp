/* graph(matrix) = [[0, 0, 0, 0, 0], 
            [0, 0, 1, 1, 1], 
            [0, 1, 0, 0, 1], 
            [0, 1, 0, 0, 1], 
            [0, 1, 1, 1, 0]] 
*/
/*graph(list) = [[2, 3, 4],
            [0, 1, 4], 
            [0, 1, 2], 
            [1, 2, 3], 
            [1, 2, 4]]
*/

// BFS in graph using adjacency matrix
void BFS(int i) { // i = starting node
    int j;
    queue<int> q;
    print(i);
    q.push(i);
    visited[i] = true; // bool vector to mark visited nodes
    
    while (!q.empty()) {
        i = q.front();
        q.pop();
        for (j = 1; j <= n; j++) { // n = no. of nodes in graph
            if (graph[i][j] && !visited[j]) {
                print(j);
                visited[j] = true;
                q.push(j);
            }
        }
    }
}

// BFS in graph using adjacency list
void bfs(vector<vector<int>> graph, int V) {
    vector<int> bfs;
    vector<int> vis(v + 1, 0);

    for(int i = 0; i <= V; ++i) {
        if (!vis[i]) {
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty()) {
                int node = q.front();
                q.pop();
                bfs.push_back(node);

                for(auto it: graph[node]) {
                    if (!vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
            }
        }
    }

    return bfs;
}

// DFS in graph using adjacency matrix
void DFS(int i) {
    if (visited[i] == false) {
        print(i);
        visited[i] = true;
        for(int j = 1; j <= n; ++j) {
            if (graph[i][j] == 1 && visited[j] != true) {
                DFS(j);
            }
        }
    }
}

// DFS in graph using adjacency list
void dfs(int node, vector<int> &vis, vector<vector<int>> graph, vector<int> storeDfs) {
    storeDfs.push_back(node);
    vis[node] = 1;
    for(auto it: graph[node]) {
        if (!vis[it]) {
            dfs(it, vis, graph, storeDfs);
        }
    }
}

vector<int> dfsOfGraph(vector<vector<int>> graph, int V) {
    vector<int> storeDfs;
    vector<int> vis(v + 1, 0);
    for(int i = 1; i <= V; ++i) {
        if (!vis[i]) {
            dfs(i, vis, graph, storeDfs);
        }
    }

    return StoreDfs;
}

// convert adjacency matrix to list
function() {
    vector<vector<int>> adjLs[V];
    for(int i = 0; i < V; ++i) {
        for(int j = 0; j < V; ++j) {
            if (graph[i][j] == 1 && i != j) {
                adjLs[i].push_back(j);
                ajsLs[j].push_back(i);
            }
        }
    }
}

// Prims algo
int I = INT_MAX;
int cost[s][s] = {{I, I, I, I}, // s = size of graph
                  {I, 25, 5, 14},
                  {I, 60, I, 40},
                  {I, 23, 19, I}};

int near[s] = {I, I, I, I};
int t[2][s - 1];

void main() {
    int i, j, k, u, v, n = 3, min = I;
    for(i = 1; i <= n; ++i) {
        for(j = i, j <= n, ++j) {
            if (cost[i][j] < min) {
                min = cost[i][j];
                u = i;
                v = j;
            }
        }
    }

    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;
    for(i = 1; i <= n; ++i) {
        if (near[i] && cost[i][u] < cost[i][v]) {
            near[i] = u;
        }
        else {
            near[i] = v;
        }
    }

    for(i = 1; i < n - 1; ++i) {
        min  = I;
        for(j = 1; j <= n; ++j) {
            if (near[j] && cost[j][near[j]] < min) {
                min = cost[j][near[j]];
                k = j;
            }
        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for(j = 1; j <= n; ++j) {
            if (near[j] && cost[j][k] < cost[j][near[j]]) {
                near[j] = k;
            }
        }
    }
    print(t);
}

// union of disjoint sets
Union(int u, int v) {
    if (s[u] < s[v]) {
        s[u] += s[v];
        s[v] = u;
    } else {
        s[v] += s[u];
        s[u] = v;
    }
}

// find parent of node in disjoint sets
int find(int u) {
    int x = u;
    while(s[x] > 0) {
        x = s[x];
    }
    return x;
}

// kruskal's algorithm
int edges[3][e] = {{1, 2, 5, 7, 2}, // e = no. of edges
                   {1, 3, 6, 18, 20},
                   {2, 3, 4, 15, 23}};

int set[e - 1] = {-1, -1, -1, -1, -1, ...};
int included[e] = {0}, t[2][s - 1]; // s = size of graph

void union(int u, int v) {
    if (set[u] < set[v]) {
        set[u] += set[v];
        set[v] = u;
    } else {
        set[v] += set[u];
        set[u] = v;
    }
}

void main() {
    int i = ,0, j, k, n = 4, e = 6, min, u, v;
    while(i < n - 1) {
        min = I;
        for(j = 0; j < e; ++j) {
            if (included[j] == 0 && edges[2][j] < min) {
                min = edges[2][j];
                k = j; u = edges[0][j]; v = edges[i][j];
            }
        }
        if (find(u) != find(v)) {
            t[0][i] = u; t[1][i] = v;
            union(find(u), find(v));
            i++;
        }
        included[k] = 1;
    }

    print(t);
}

//Topological sort
void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
    vis[node] = 1;
    
    for(auto it: adj[node]) {
        if (!vis[it]) {
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int N, vector<int> adj[]) {
    stack<int> st;
    vector<int> vis(N, 0);
    for(int i = 0; i < N; ++i) {
        if (vis[i] == 0) {
            findTopoSort(i, vis, st, adj);
        }
    }
    vector<int> topo;
    while(!st.empty()) {
        topo.push_back(st.top());
        st.pop();
    }
    return topo;
}

// cycle detection in undirected graph
bool checkForCycle(int node, int parent, vector<int> &vis, vector<vector<int>> adj) {
    vis[node] = 1;
    for(auto it: adj[node]) {
        if (!vis[it]) {
            if (checkForCycle(it, node, vis, adj)) {
                return true;
            }
            else if(it != parent) {
                return true;
            }
        }
    }
    return false;
}

bool isCycle(int V, vector<vector<int>> adj) {
    vector<int> vis(V + 1, 0);
    for(int i = 1; i <= V; ++i) {
        if (!vis[i]) {
            if (checkForCycle(i, -1, vis, adj)) {
                return true;
            }
        }
    }
    return false;
}

// cycle detection in directed graph
bool checkForCycle(int node, vector<vector<int>> adj, vector<int> vis, vector<int> dfsVis) {
    vis[node] = 1;
    dfsVis[node] = 1;
    for(auto it: adj[node]) {
        if (!vis[it]) {
            if (checkForCycle(it, adj, vis, dfsVis)) {
                return true;
            }
        }
        else if(dfsVis[it]) {
            return true;
        }
    }

    dfsVis[node] = 0;
    return false;
}

bool isCycle(int N, vector<vector<int>> adj) {
    vector<int> vis(N, 0);
    vector<int> dfsVis(N, 0);

    for(int i = 0; i < N; ++i) {
        if (checkForCycle(i, adj, vis, dfsVis)) {
            return true;
        }
    }
    return false;
}
