class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double tot=0;
        int n=customers.size();
        int curr=customers[0][0];
        for(auto &vec:customers){
            int arr=vec[0];
            int ct=vec[1];
            if(curr<arr){
                curr=arr;
            }
            int wt=curr+ct-arr;
            curr+=ct;
            tot+=wt;
        }
        return tot/n;
    }
};