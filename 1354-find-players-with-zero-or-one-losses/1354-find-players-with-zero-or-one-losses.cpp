class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int>zero,one;
        unordered_map<int,int>mpp;

        for(int i=0;i<matches.size();i++){
            mpp[matches[i][1]]++;
        }
          for(int i=0;i<matches.size();i++){
            int looser=matches[i][1];
            int winner=matches[i][0];
            if(mpp.find(winner)==mpp.end()){
                zero.push_back(winner);
                mpp[winner]=2;
            }
            if(mpp[looser]==1){
                one.push_back(looser);
            }
        }
        sort(begin(zero),end(zero));
        sort(begin(one),end(one));
        return {zero,one};

    }
};