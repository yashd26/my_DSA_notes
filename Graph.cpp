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

//Topological sort using DFS
void findTopoSort(int node, vector<int> &vis, stack<int> &st, vector<vector<int>> adj) {
    vis[node] = 1;
    
    for(auto it: adj[node]) {
        if (!vis[it]) {
            findTopoSort(it, vis, st, adj);
        }
    }
    st.push(node);
}

vector<int> topoSort(int N, vector<vector<int>> ad) {
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

// Kahn's algo
vector<int> topoSort(int V, vector<vector<int>> adj) {
    int indegree[V] = {0};
    for(int i = 0; i < V; ++i) {
        for(auto it: adj[i]) {
            indegree[it]++;
        }
    }

    queue<int> q;
    for(int i = 0; i < V; ++i) {
        if (!indegree[i]) {
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        todo.push_back(node);

        for(auto it: adj[node]) {
            indegree[it]--;
            if (!indegree[it]) {
                q.push(it);
            }
        }
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

// Dijkstra's algo
//graph = {{{node2, weight}, {node5, weight}}, {{node3, weight},..},...} 
vector<int> dijkstra(vector<vector<int>> graph[], int V, int startNode) {
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);

    st.insert({0, startNode});
    dist[0] = 0;

    while(!st.empty()) {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;

        for(auto it: graph[node]) {
            int adjNode = it.second;
            int adjDis = it.first;

            if (dis + adjDis < dist[adjNode]) {
                if (dist[adjNode] != 1e9) {
                    st.erase(dist[adjNode], adjNode);
                }
                dist[adjNode] = adjDis + dis;
                st.insert(dist[adjNode], adjNode);
            }
        }
    }

    return dist;
}

// Bellman ford algo && also check for negative cycle
// graph = {{node1, node1, weight}, {node2, node5, weight},...}
vector<int> bellmanFord(vector<vector<int> graph, int V, int startNode) {
    vector<int> dist(V, 1e9);
    dist[0] = 0;

    for(int i = 0; i < V - 1; ++i) {
        for(auto it: graph) {
            int node1 = it[0];
            int node2 = it[1];
            int weight = it[2];

            if (dist[u] != 1e9 && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    //detect negative cycle
    for(auto it: graph) {
        int node1 = it[0];
        int node2 = it[1];
        int weight = it[2];

        if (dist[u] != 1e9 && dist[u] + weight < dist[v]) {
            //true
            return {-1};
        }
    }

    return dist;
}

//Floyd warshall algo && detect negative cycle
/* matrix[V][V] = [[0, 1, 5],
                   [-1, 0, -1],
                   [-1, 9, 0]]
*/// (where matrix[i][i] = 0 && matrix[i][j] = -1 implies no edge
void floyd(vector<vector<int>> matrix) {
    int n = matrix.size();

    for(int i = 0; i < n; ++i) {
        for(int k = 0; k < n; ++k) {
            for(int j = 0; j < n; ++j) {
                matrix[k][j] = min(matrix[k][j], matrix[k][i] + matrix[i][j]);
            }
        }
    }

    //detect negative cycle
    for(int i = 0; i < n; ++i) {
        if (matrix[i][i] < 0) {
            //true
        }
    }
}
