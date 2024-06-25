class Solution {
public:
    string orderlyQueue(string s, int k) {
        if(k>1){
            sort(begin(s),end(s));
            return s;
        }
        string res=s;

        for(int i=1;i<=s.size()-1;i++)
        {
            string temp=s.substr(i)+s.substr(0,i);
            res=min(temp,res);
        }
        return res;
    }
};