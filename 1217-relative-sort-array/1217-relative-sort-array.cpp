class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int>mp;
        for(int i=0;i<arr2.size();i++)
        {
            mp[arr2[i]]=i;
        }
        for(auto &i:arr1)
        {
            if(!mp.count(i))

            {
                mp[i]=1e9;
            }
        }
        auto lambda=[&](int n1,int n2)
        {
            if(mp[n1]==mp[n2])
            {
                return n1<n2;
            }
            return mp[n1]<mp[n2];
        };
        sort(arr1.begin(),arr1.end(),lambda);
        return arr1;
    }
};