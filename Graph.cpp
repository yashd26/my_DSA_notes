/* graph = [[0, 0, 0, 0, 0], 
            [0, 0, 1, 1, 1], 
            [0, 1, 0, 0, 1], 
            [0, 1, 0, 0, 1], 
            [0, 1, 1, 1, 0]] 
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


