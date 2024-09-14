class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int res=0;
        int streak=0;
        int maxvalue=0;
        for(auto &i:nums){
            if(i>maxvalue){
                maxvalue=i;
                streak=0;
                res=0;

            }
            if(i==maxvalue)streak++;
            else streak=0;

        res=max(res,streak);
        }
        return res;
    }
};