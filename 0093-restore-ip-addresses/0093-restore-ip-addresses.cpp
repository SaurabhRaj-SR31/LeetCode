class Solution {
public:
        vector<string>ans;

    bool isvalid(const string& s) {
        if (s.size() > 3 || s.size() == 0) return false;
        if (s[0] == '0' && s.size() > 1) return false;
        int val = stoi(s);
        return val >= 0 && val <= 255;
    }
   void solve(string s,int idx,int parts, string cur){
     int n=s.size();
       
       

        if(idx==n && parts==4)
        {
            cur.pop_back();
            ans.push_back(cur);
        }
        if(idx+1<=n)
        {
            solve(s,idx+1,parts +1, cur+s.substr(idx,1)+".");
        }
        if(idx+2<=n && isvalid(s.substr(idx,2)))
        {
            solve(s,idx+2,parts +1, cur+s.substr(idx,2)+".");
        }
        if(idx+3<=n &&  isvalid(s.substr(idx,3)))
        {
            solve(s,idx+3,parts +1, cur+s.substr(idx,3)+".");
        }
       
}
    vector<string> restoreIpAddresses(string s) {
       int parts=0;
       string cur="";
       int n=s.size();
        if(n>12)return {};
       solve(s,0,parts,cur);
return ans;
    }
};