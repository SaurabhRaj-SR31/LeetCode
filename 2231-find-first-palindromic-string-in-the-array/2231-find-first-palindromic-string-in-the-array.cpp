class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto &w:words){
            if(equal(w.begin(),w.begin()+w.size()/2,w.rbegin())){
                return w;
            }
        }
            return "";
    }
};