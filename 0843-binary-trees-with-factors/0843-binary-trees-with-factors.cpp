class Solution {
public:
int mod=1e9+7;

    int numFactoredBinaryTrees(vector<int>& arr) {
        int n=arr.size();
        sort(begin(arr),end(arr));
        unordered_map<int,long long>mpp;
        mpp[arr[0]]=1;
        long long res=0;

        for(int i=1;i<n;i++){
            int root=arr[i];
            mpp[root]=1;
            for(int j=0;j<i;j++){
                int lc=arr[j];
                if(root%lc==0 && mpp.find(root/lc)!=mpp.end()){
                    mpp[root]+=mpp[lc]*mpp[root/lc];

                }


            }
        }
        for(auto &i:mpp){
            res=(res+i.second)%mod;
        }
        return res;
    }
};