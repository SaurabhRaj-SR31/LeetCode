class Solution {
public:
    bool checkIfPangram(string sentence) {
        int cnt=0;
        vector<int>arr(26,0);

        for(auto &i:sentence)
        {
            int ind=i-'a';
            if(arr[ind]==0)
            {
            arr[ind]++;
            cnt++;
            }
        }
        return cnt==26;
    }
};