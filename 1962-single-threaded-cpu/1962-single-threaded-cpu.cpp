class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
          vector<int> res;
          int n=tasks.size();
          vector<array<int,3>>sortedtask;
          for(int i=0;i<n;i++){
            sortedtask.push_back({tasks[i][0],tasks[i][1],i});

          }
          sort(begin(sortedtask),end(sortedtask));
          long long cur=0;
          int i=0;
          priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
          while(i<n || !pq.empty()){
            if(pq.empty() && cur<sortedtask[i][0]){
                cur=sortedtask[i][0];
                }
            while(i<n && sortedtask[i][0]<=cur){
                pq.push({sortedtask[i][1],sortedtask[i][2]});
                i++;
            }
               

                
            
            pair<int,int> temp=pq.top();
            pq.pop();
            cur+=temp.first;
             res.push_back(temp.second);
            

          }
          return res;
    }
};