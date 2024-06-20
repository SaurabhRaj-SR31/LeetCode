class Solution {
public:
    bool possible(int midf,vector<int>&position,int m)
    {
        int prev=position[0];
        int cnt=1;
        for(int i=1;i<position.size();i++)
        {
            int cur=position[i];
            if(cur-prev>=midf)
            {
                cnt++;
                prev=cur;
            }
            
            if(cnt==m)break;
        }
        return cnt==m;
    }
    int maxDistance(vector<int>& position, int m) {
        int l=1;
        int res=0;
        int n=position.size();
        sort(position.begin(),position.end());
        int h=position[n-1]-position[0];
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(possible(mid,position,m)){
                res=mid;
                l=mid+1;
            }
            else h=mid-1;
        }
        return res;
    }
};