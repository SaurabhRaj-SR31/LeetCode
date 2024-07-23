class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
         vector<int> res;
         int n=nums.size();
         unordered_map<int,int>mpp;
          vector<vector<int>>bucket(n+1); 
          for(auto &num:nums)mpp[num]++;
          for(auto &i:mpp){
            int ele=i.first;
            int freq=i.second;
            bucket[freq].push_back(ele);
          }
          for(int i=n;i>=0;i--){
            if(bucket[i].size()==0)continue;
            while(bucket[i].size()>0 && k>0){
                res.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }

          }
          return res;
    }
};