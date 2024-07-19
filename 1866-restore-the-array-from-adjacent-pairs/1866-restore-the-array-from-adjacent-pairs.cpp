class Solution {
public:
    vector<int>res;
    void dfs(int start,int prev,unordered_map<int,vector<int>>&adj){
        res.push_back(start);
        for(auto &i:adj[start]){
            if(i!=prev){
                dfs(i,start,adj);
            }
        }
    }
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int,vector<int>>adj;
        for(vector<int>&vec:adjacentPairs){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        int start=-1;
        for(auto& i:adj){
            if(i.second.size()==1){
                start=i.first;
                break;
            }
        }
        dfs(start,INT_MIN,adj);
        return res;
    }
};