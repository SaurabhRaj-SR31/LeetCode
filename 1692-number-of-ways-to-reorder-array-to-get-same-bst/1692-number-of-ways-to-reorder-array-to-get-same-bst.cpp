class Solution {
public:
    typedef long long ll;
    ll mod=1e9+7;
    vector<vector<ll>>pt;
    ll solve(vector<int>& nums){
        int n=nums.size();
        vector<int>left,right;
        if(n<3)return 1;
        int root=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<root){
                left.push_back(nums[i]);
            }
            else{
                right.push_back(nums[i]);

            }
            
        }
        ll x=solve(left)%mod;
            ll y=solve(right)%mod;
            ll z=pt[n-1][left.size()];
            return (((x*y)%mod *z)%mod);

    }

    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pt.resize(n+1);
        for(int i=0;i<=n;i++){
            pt[i]=vector<ll>(i+1,1);
            for(int j=1;j<i;j++){
                pt[i][j]=(pt[i-1][j]+pt[i-1][j-1])%mod;
            }
        }
        return (solve(nums)-1)%mod;


    }
};