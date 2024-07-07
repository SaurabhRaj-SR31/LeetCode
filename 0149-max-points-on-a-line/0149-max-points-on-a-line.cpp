class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n==1)return 1;
        int res=0;
        for(int i=0;i<n;i++){
            unordered_map<double,int>mp;
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                double theta=atan2(dy,dx);
                mp[theta]++;


            }
            for(auto &i:mp){

            res=max(res,i.second+1);
            }
        }
        return res;
    }
};