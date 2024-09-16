class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n=timePoints.size();
        vector<int> num(n);
        for(int i=0;i<n;i++){
            string time=timePoints[i];
            string hrs=time.substr(0,2);
            string mins=time.substr(3);
            int hr=stoi(hrs);
            int minutes=stoi(mins);
            num[i]=(hr*60 +minutes);

        }
        int res=INT_MAX;
        sort(begin(num),end(num));
        for(int i=1;i<n;i++){
            res=min(res,num[i]-num[i-1]);
        }
        return min(res,(1440-num[n-1])+num[0]);
    }
};