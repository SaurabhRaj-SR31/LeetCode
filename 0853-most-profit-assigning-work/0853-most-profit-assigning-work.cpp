class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n=difficulty.size();
        int m=worker.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({difficulty[i],profit[i]});

        }
        sort(begin(vec),end(vec));
        for(int i=1;i<vec.size();i++)
        {
            vec[i].second=max(vec[i].second,vec[i-1].second);
        }
        int tot=0;

        for(int i=0;i<m;i++)
        {
             int l=0;
             int maxprofit=0;

        int r=vec.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(vec[mid].first<=worker[i])
            {
                maxprofit=max(maxprofit,vec[mid].second);
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        tot+=maxprofit;

        }
       return tot;
    }
};