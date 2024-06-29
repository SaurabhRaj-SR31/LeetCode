class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        map<char,vector<int>>mpp;
        for(int i=0;i<m;i++)
        {
            mpp[t[i]].push_back(i);
        }
        int prev=-1;
        for(int i=0;i<n;i++)
        {char ch=s[i];
            if(mpp.find(ch)==mpp.end())return false;
            vector<int>indices=mpp[ch];
            auto up=upper_bound(indices.begin(),indices.end(),prev);
            if(up==indices.end())return false;
            prev=*up;
        }
        return true;
        

    }
};