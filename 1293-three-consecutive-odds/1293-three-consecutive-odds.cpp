class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n=arr.size();
        if(n<3)return false;
        
        int cnt=0;
        for(int i=0;i<3;i++)
        {
            if(arr[i]%2!=0)cnt++;
            if(cnt==3) return true;
        }
        for(int i=1;i<=n-3;i++)
        {
            if(arr[i-1]%2!=0)cnt--;
            if(arr[i+2]%2!=0)cnt++;
            if(cnt==3) return true;
        }
        return false;
    }
};