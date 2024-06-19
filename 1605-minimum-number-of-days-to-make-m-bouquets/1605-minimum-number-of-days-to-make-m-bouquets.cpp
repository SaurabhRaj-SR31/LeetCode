class Solution {
public:
    bool possible(vector<int>& bloomDay, int day, int m, int k) {
        int n = bloomDay.size();
        int cnt = 0;
        int b = 0;

        for (int i = 0; i < n; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                b += cnt / k;
                cnt = 0;
            }
        }
        b += cnt / k;
        return b >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long val=m*1LL*k*1LL;
        if (val > n) return -1;

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            mini = min(mini, bloomDay[i]);
            maxi = max(maxi, bloomDay[i]);
        }

        int l = mini;
        int h = maxi;
        int ans = h;

        while (l <= h) {
            int mid = l + (h - l) / 2;
            if (possible(bloomDay, mid, m, k)) {
                ans = mid;
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
