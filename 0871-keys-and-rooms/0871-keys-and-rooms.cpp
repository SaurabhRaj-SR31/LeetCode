class Solution {
public:
void dfs(vector<vector<int>>& rooms,int node ,vector<bool>&vis){
    vis[node]=true;
    for(auto &neigh:rooms[node]){
        if(!vis[neigh])dfs(rooms,neigh,vis);
    }
}
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
      vector<bool>vis(n,false);
      dfs(rooms,0,vis);
      for(bool x:vis){
        if(x==false)return false;
        
      }
      return true;
    }
};