class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {int n=customers.size();
        int maxunsat=0;
        int unsat=0;
        for(int i=0;i<minutes;i++)
        {
            unsat+=customers[i]*grumpy[i];
        }
        maxunsat=unsat;
        int i=0;
        int j=minutes;
        while(j<n)
        {
             unsat+=customers[j]*grumpy[j];
              unsat-=customers[i]*grumpy[i];
              maxunsat=max(maxunsat,unsat);
              i++;j++;

        }
        int tot=0;
        tot=maxunsat;
        for(int i=0;i<n;i++)
        {
            tot+=customers[i]*(1-grumpy[i]);
        }
        return tot;
    }
};