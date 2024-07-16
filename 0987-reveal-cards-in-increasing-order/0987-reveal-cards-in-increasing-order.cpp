class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n=deck.size();
        vector<int>res(n,0);
        int i=0;
        int j=0;
        bool skip=false;
        sort(begin(deck),end(deck));
        while(i<n){
            if(res[j]==0){
                if(skip==false){
                    res[j]=deck[i];
                    i++;
                }
                
                skip=!skip;
            }
            j=(j+1)%n;

        }
        return res;
    }
};