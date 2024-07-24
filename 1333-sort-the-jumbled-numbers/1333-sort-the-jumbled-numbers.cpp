class Solution {
public:
 int getnum(int num, vector<int>& mapping) { 
        int mappednum = 0;
        int placeval = 1;
        if(num < 10) {
            return mapping[num];
        }
        while(num) {
            int lastdgt = num % 10;
            int mppval = mapping[lastdgt];
            mappednum += (mppval * placeval);
            placeval *= 10;
            num /= 10;
        }
        return mappednum;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;
        vector<pair<int,int>>temp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int mappednum=getnum(nums[i],mapping);
            temp.push_back({mappednum,i});

        }
        sort(begin(temp),end(temp));
        for(auto &i:temp){
            int idx=i.second;
            ans.push_back(nums[idx]);
        }
        return ans;
    }
};