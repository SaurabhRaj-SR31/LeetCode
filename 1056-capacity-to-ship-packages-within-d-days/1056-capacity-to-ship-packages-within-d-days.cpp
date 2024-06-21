class Solution {
public:
    int fn(vector<int>& wts, int cap)
    {
        int n=wts.size();
        int load=0;
        int day=1;
        for(int i=0;i<n;i++)
        {
            if(load+wts[i]>cap)
            {
                day+=1;
                load=wts[i];
            }
            else load+=wts[i];
        }
    return day;

    }
    int shipWithinDays(vector<int>& wts, int days) {
        int n=wts.size();
        int l=*max_element(wts.begin(), wts.end());
        int h=0;

        for(int i=0;i<n;i++)
        {
            h+=wts[i];
        }
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(fn(wts,mid)<=days)
            {
                h=mid-1;
            }
            else l=mid+1;
        }
        return l;
    }
};