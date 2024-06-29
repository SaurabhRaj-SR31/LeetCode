class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
      
        // Build the graph from the given edges
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
      
        // Prepare the answer in the form of a vector of vectors
        vector<vector<int>> ancestors(n);
      
        // Lambda function for breadth-first search
        auto bfs = [&](int startNode) {
            queue<int> q;
            q.push(startNode);
            vector<bool> visited(n, false);
            visited[startNode] = true;
          
            while (!q.empty()) {
                int currentNode = q.front();
                q.pop();

                // Visit all adjacent nodes
                for (int adjNode : graph[currentNode]) {
                    if (!visited[adjNode]) {
                        visited[adjNode] = true;
                        ancestors[adjNode].push_back(startNode); // Add this node as an ancestor
                        q.push(adjNode);
                    }
                }
            }
        };
      
        // Run BFS for each node to find all ancestors
        for (int i = 0; i < n; ++i) {
            bfs(i);
        }

        return ancestors;
    }
};