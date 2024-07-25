class Solution {
public:
typedef pair<int,char> p;
    string reorganizeString(string s) {
        string res;
        int n=s.size();
        vector<int>arr(26,0);
        for(auto &ch:s){
            arr[ch-'a']++;
            if(arr[ch-'a']>(n+1)/2)return "";
        }
        priority_queue<p,vector<p>>pq;
        for(char ch='a';ch<='z';ch++){
           if (arr[ch-'a']>0)
           pq.push({arr[ch-'a'],ch});
        }
        while(pq.size()>=2){
            auto p1=pq.top();
            pq.pop();
              auto p2=pq.top();
            pq.pop();
            res.push_back(p1.second);p1.first--;
            res.push_back(p2.second);p2.first--;
            if(p1.first>0)pq.push(p1);
            if(p2.first>0)pq.push(p2);




        }
        if(!pq.empty())res.push_back(pq.top().second);
return res;
    }
};