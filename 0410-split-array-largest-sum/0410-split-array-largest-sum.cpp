class Solution {
public:
    int fn(vector<int>& nums, int pages)
    {
        int n=nums.size();
        int stu=1;
        int pagecnt=0;
        for(int i=0;i<n;i++)
        {
            if(pagecnt+nums[i]<=pages)
            {
                pagecnt+=nums[i];
            }
            else {
                stu++;
                pagecnt=nums[i];
            }
        }
        return stu;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int h=0;
        for(auto &it:nums)
        {
            h+=it;
        }
        while(l<=h)
       {int mid=l+(h-l)/2;
       if(fn(nums,mid)>k)
       {l=mid+1;

       }
       else{
        h=mid-1;
       }

       }
       return l;
    }
};