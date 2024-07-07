class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int n=arr.size();
        int mini=*min_element(begin(arr),end(arr));
        int maxi=*max_element(begin(arr),end(arr));
        int i=0;
        unordered_set<int>st(begin(arr),end(arr));
        if((maxi-mini)%(n-1)!=0)return false;
        int d=(maxi-mini)/(n-1);
        while(i<n){
            int temp=mini+i*d;
            if(st.find(temp)==st.end())return false;
            i++;
        }
        return true;


    }
};