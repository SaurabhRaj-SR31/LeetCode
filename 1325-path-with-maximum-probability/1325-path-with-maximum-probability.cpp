class Solution {
public:
    typedef pair<double,int> P;

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>adj;
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            double prob=succProb[i];
            adj[u].push_back({v,prob});
            adj[v].push_back({u,prob});
        }
        priority_queue<P>pq;
        vector<double> res(n, 0.0);
        res[start_node] = 1.0;
        pq.push({1.0, start_node});
        while(!pq.empty()){

            int curnode=pq.top().second;
           double curprob=pq.top().first;
           pq.pop();
           for(auto &neigh:adj[curnode]){
            // int neighnode=neigh.first;
            // double neighprob=neigh.second;
            if(res[neigh.first]<curprob*neigh.second){
                res[neigh.first]=curprob*neigh.second;
                pq.push({res[neigh.first],neigh.first});
            }
           }
             
        }
return res[end_node];
    }
};