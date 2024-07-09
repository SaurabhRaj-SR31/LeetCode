class Solution {
public:
    int pivotInteger(int n) {
        int tot=n*(n+1)/2;
         int p=sqrt(tot);
         if(pow(p,2)==tot)return p;
         return -1;
    }
};