class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto lambda=[&](int a,int b){
            string s1=to_string(a);
            string s2=to_string(b);
            return (s1+s2)>(s2+s1);

        };
        sort(begin(nums),end(nums),lambda);
        if(nums[0]==0)return "0";
        string res="";
        for(auto &i:nums){
            res+=to_string(i);
        }
        return res;
    }
};