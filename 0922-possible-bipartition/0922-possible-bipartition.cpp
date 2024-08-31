class Solution {
public:
bool checkbip(unordered_map<int,vector<int>>&adj,int node,vector<int>&color){
    queue<int>q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto &neigh: adj[u]){
            if(color[neigh]==color[u])return false;
            if(color[neigh]==-1){
                q.push(neigh);
                color[neigh]=1-color[u];
            }
        }
    }
    return true;
}
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>adj;
        for(auto &vec:dislikes){
            int u=vec[0];
            int v=vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);

        }
        vector<int>color(n+1,-1);
        for(int i=1;i<=n;i++){
            if(color[i]==-1){
                if(checkbip(adj,i,color)==false)return false;
            }
        }
        return true;
    }
};