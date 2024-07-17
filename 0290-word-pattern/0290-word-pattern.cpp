class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,int>chartoidx;
        unordered_map<string,int>stringtoidx;
        int count=0;
        int i=0;
        stringstream ss(s);
        string token;
        int n=pattern.size();
        while(ss>>token){
            count++;
            if(i==n || chartoidx[pattern[i]]!=stringtoidx[token])return false;
            chartoidx[pattern[i]]=i+1;
            stringtoidx[token]=i+1;
            i++;
        }
        if(count != n || i!=n)return false;
        return true;

    }
};