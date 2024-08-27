class Solution {
public:
    vector<vector<int>> directions{{0,1},{1,0},{0,-1},{-1,0}};

    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int steps = 0;

        while (!q.empty()) {
            int N = q.size();
            while (N--) {
                auto [i, j] = q.front();
                q.pop();
                
                // Check if this is an exit (but not the entrance)
                if ((i != entrance[0] || j != entrance[1]) && (i == 0 || j == 0 || i == n - 1 || j == m - 1)) {
                    return steps;
                }

                // Explore all four directions
                for (auto &dir : directions) {
                    int newi = i + dir[0];
                    int newj = j + dir[1];
                    
                    // Check bounds and if the cell is not visited
                    if (newi >= 0 && newi < n && newj >= 0 && newj < m && maze[newi][newj] == '.') {
                        q.push({newi, newj});
                        maze[newi][newj] = '+'; // Mark as visited
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};