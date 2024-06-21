class Solution {
public:
 long long fn(const vector<int>& arr, int hr) {  
        long long tot = 0;

        for(int banana_count : arr) {
            tot += (banana_count + hr - 1LL) / hr; // Use 1LL to ensure long long arithmetic
        }
        return tot;
    }
    int smallestDivisor(vector<int>& arr, int hr) {
        int n = arr.size();
        int l = 1;
        int h = *max_element(arr.begin(), arr.end());
        int ans=-1;

        while(l <= h) {
            int mid = l + (h - l) / 2;
            if(fn(arr, mid) <= hr) {
                ans=mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }

    };
