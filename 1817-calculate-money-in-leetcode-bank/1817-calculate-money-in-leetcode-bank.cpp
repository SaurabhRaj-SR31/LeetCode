class Solution {
public:
    int totalMoney(int n) {
        int res=0;
        int terms=n/7;
        int first=28;
        int last=first+(terms-1)*7;
      res=terms*(first+last)/2;
            int last_first=terms+1;
        for(int i=1;i<=(n%7);i++){
            res+=last_first;
            last_first++;
        }
        
        return res;
    }
};