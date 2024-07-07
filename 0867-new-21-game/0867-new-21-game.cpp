class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double>p(n+1,0.0);
        p[0]=1;
        double probsum=(k==0)?0:1;
        for(int i=1;i<=n;i++){
            p[i]=probsum/maxPts;
            if(i<k)probsum+=p[i];
            if((i-maxPts)>=0 && (i-maxPts)<k)probsum-=p[i-maxPts];
        }
        return accumulate(begin(p)+k,end(p),0.0);
    }
};