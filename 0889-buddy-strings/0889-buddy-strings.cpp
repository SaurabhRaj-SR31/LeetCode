class Solution {
public:
    bool checkfreq(string &s)
    {
        vector<int>arr(26,0);
        for(auto &ch:s)
        {
            arr[ch-'a']++;
            if(arr[ch-'a']>1)return true;
        }
        return false;
    }
    bool buddyStrings(string s, string goal) {
        int n=s.size();
        int m=goal.size();
        if(n!=m)return false;
        vector<int>ind;
        if(s==goal)
        {
            return checkfreq(s);
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]!=goal[i]){
                ind.push_back(i);
            }

            

        }
        if(ind.size()!=2)return false;
        swap(s[ind[0]],s[ind[1]]);
        return s==goal;

    }
};