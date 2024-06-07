class Solution {
public:
    string replaceWords(vector<string>& dict, string sent) {
        set<string>s;
        for(auto &i:dict)
        {
            s.insert(i);

        }
        sent.push_back(' ');
        string ans="";
        string temp="";
        int n=sent.size();
        for(int i=0;i<n;i++)
        {
            if(sent[i]==' ')
            {
                ans+=temp;
                ans+=(char)' ';
                temp="";
            }
            else
            {
                temp+=(char)sent[i];
                if(s.count(temp))
                {
                    ans+=temp;
                ans+=(char)' ';
                temp="";
                while(sent[i]!=' ')i++;
                }
            }
        }
        ans.pop_back();
        return ans;
    }
};