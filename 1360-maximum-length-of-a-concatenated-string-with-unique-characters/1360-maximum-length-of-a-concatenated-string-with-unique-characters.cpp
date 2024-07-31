class Solution {
public:unordered_map<string,int>mp;
bool hasduplicate(string &s1,string &s2){
    vector<int>vec(26,0);
    for(auto &ch:s1){
        if(vec[ch-'a']>0)return true;
        vec[ch-'a']++;
    }
    for(auto&ch:s2){
        if(vec[ch-'a']>0)return true;
    }
    return false;
}
    int solve(int i,string temp,vector<string>&arr,int n){
        if(i>=n)return temp.size();
        int include=0;
        int exclude=0;
        if(mp.find(temp)!=mp.end())return mp[temp];

        if(hasduplicate(arr[i],temp)){
            exclude=solve(i+1,temp,arr,n);
        }
        else{
            exclude=solve(i+1,temp,arr,n);
            include=solve(i+1,(temp+arr[i]),arr,n);



        }
        return mp[temp]=max(include,exclude);
        
        
           }
    int maxLength(vector<string>& arr) {
        int n=arr.size();
        string temp="";
        return solve(0,temp,arr,n);
    }
};