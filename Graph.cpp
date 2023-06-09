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

// Prims algo (return sum of mst weight)
// if the path is required, carry parent
//graph = {{{node2, weight}, {node5, weight}}, {{node3, weight},..},...}
int prim(int V, vector<vector<int>> graph[]) {
    priority_queue<pair<int, int>> pq;
    vector<int> vis(V, 0);

    pq.push({0, 0});
    int sum = 0;
    while(!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int weight = it.first;

        if (vis[node] != 1) {
            vis[node] = 1;
            sum += 1;
            for(auto it: graph[node]) {
                int adjNode = it[1];
                int adjWeight = it[0];
                if (!vis[adjNode]) {
                    pq.push({adjWeight, adjNode});
                }
            }
        }
    }

    return sum;
}

//Union and find in Disjoint Set
DisjointSet(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }
}
int findUPar(int node) {
    if (node == parent[node])
        return node;
    return parent[node] = findUPar(parent[node]);
}
void unionByRank(int u, int v) {
    int ulp_u = findUPar(u);
    int ulp_v = findUPar(v);
    if (ulp_u == ulp_v) return;
    if (rank[ulp_u] < rank[ulp_v]) {
        parent[ulp_u] = ulp_v;
    }
    else if (rank[ulp_v] < rank[ulp_u]) {
        parent[ulp_v] = ulp_u;
    }
    else {
        parent[ulp_v] = ulp_u;
        rank[ulp_u]++;
    }
}

// kruskal's algorithm
/* edgelist[V][V] = [[weight, node1, node2],
                   [w, n3, n5],
                   [w, n1, n3]]
*/
// f the path is required, carry parent
class DSU {
    int* parent;
    int* rank;
 
public:
    DSU(int n)
    {
        parent = new int[n];
        rank = new int[n];
 
        for (int i = 0; i < n; i++) {
            parent[i] = -1;
            rank[i] = 1;
        }
    }
 
    int find(int i)
    {
        if (parent[i] == -1)
            return i;
 
        return parent[i] = find(parent[i]);
    }
 
    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
 
        if (s1 != s2) {
            if (rank[s1] < rank[s2]) {
                parent[s1] = s2;
            }
            else if (rank[s1] > rank[s2]) {
                parent[s2] = s1;
            }
            else {
                parent[s2] = s1;
                rank[s1] += 1;
            }
        }
    }
};
 
void kruskals_mst(vector<vector<int>> edgelist, int V) {
    // Sort all edges
    sort(edgelist.begin(), edgelist.end());

    // Initialize the DSU
    DSU s(V);
    int ans = 0;
    for (auto edge : edgelist) {
        int w = edge[0];
        int x = edge[1];
        int y = edge[2];

        // Take this edge in MST if it does
        // not forms a cycle
        if (s.find(x) != s.find(y)) {
            s.unite(x, y);
            ans += w;
        }
    }
    return ans;
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
