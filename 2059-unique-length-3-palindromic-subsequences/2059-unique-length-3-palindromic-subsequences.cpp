class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        vector<pair<int,int>>arr(26,{-1,-1});
        for(int i=0;i<n;i++)
        {
            char ch=s[i];
            if(arr[ch-'a'].first==-1){
                arr[ch-'a'].first=i;
            }
            arr[ch-'a'].second=i;
        }
        int res=0;
        int left;
        int right;
        for(int i=0;i<26;i++){
         left=arr[i].first;
         right=arr[i].second;
         if(left==-1)continue;
        
        unordered_set<char>st;
        for(int k=left+1;k<=right-1;k++){
            st.insert(s[k]);
        }
        res+=st.size();}
        return res;

    }
};