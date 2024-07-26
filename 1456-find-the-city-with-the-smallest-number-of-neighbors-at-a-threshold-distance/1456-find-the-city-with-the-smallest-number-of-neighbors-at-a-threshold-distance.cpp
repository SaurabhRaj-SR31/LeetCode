class Solution {
public:
int findres(int n,vector<vector<int>>& spm,int d){
    int city=-1;
    int leastdiscnt=INT_MAX;
    for(int i=0;i<n;i++){
        int cnt=0;
            for(int j=0;j<n;j++){
if(i!=j&& spm[i][j]<=d){
    cnt++;
}

            }
            if(cnt<=leastdiscnt){
                leastdiscnt=cnt;
                city=i;
            }
            }
     return city;
}
void floydwarshall(int n,vector<vector<int>>& spm){
    for(int via=0;via<n;via++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                spm[i][j]=min(spm[i][j],spm[i][via]+spm[via][j]);
            }
        }
    }
}
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            adj[u][v]=wt;
            adj[v][u]=wt;



        }
    
     floydwarshall(n,adj);
     return findres(n,adj,distanceThreshold);
        
    }
};