class Solution {
public:
    double myPow(double x, int n) {
        long long nn=n;
        if(nn<0)nn=(-1)*nn;
        double ans=1.0;
        while(nn)
        {
            if(nn%2==1)
            {
                ans*=x;
                nn=nn-1;

            }
            if(nn%2==0)
            {
                x=x*x;
                nn=nn/2;
            }

        }
        if(n<0)ans=(double)1.0/(double)ans;
       
        return ans;
    }
};