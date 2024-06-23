class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        multiset<int>st;
        int i=0,j=0;
        int maxlen=0;
        while(j<n)
        {st.insert(nums[j]);
            if(*st.rbegin()-*st.begin()>limit)
            {st.erase(st.find(nums[i]));
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};