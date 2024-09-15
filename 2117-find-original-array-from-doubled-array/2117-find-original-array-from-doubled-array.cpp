class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n=changed.size();
         vector<int>res;

        if(n&1==1 )return {};
        sort(begin(changed),end(changed));
        unordered_map<int,int>mp;
        for(auto &num:changed){
            mp[num]++;
        }
        for(auto &num:changed){
            int twice=num*2;
            if(mp[num]==0)continue;

           else  if(mp.find(twice)==mp.end() || mp[twice]==0)return {};
            else {
                mp[num]--;
                mp[twice]--;
                res.push_back(num);
            }
        }
        return res;
    }
};