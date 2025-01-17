class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {int x=0;
        for(auto &num :derived){
            x^=num;
        }
        return x==0?true:false;
    }
};