class Solution {
public:
 void dfs(vector<vector<int>>& stones, int idx, vector<bool>& vis) {
        vis[idx] = true;
        for (int i = 0; i < stones.size(); i++) {
            if (!vis[i] && (stones[idx][0] == stones[i][0] || stones[idx][1] == stones[i][1])) {
                dfs(stones, i, vis);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        int grp=0;
        vector<bool>vis(n,false);
        for(int i=0;i<stones.size();i++){
            if(vis[i]==true)continue;
            dfs(stones,i,vis);
            grp++;
        }
        return n-grp;
    }
};