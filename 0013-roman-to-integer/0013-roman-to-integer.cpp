class Solution {
public:
    int nums(char s)
    {
        if(s=='I')return 1;
        
        else if(s=='V')return 5;
        else if(s=='X')return 10;

        else if(s=='L')return 50;

        else if(s=='C')return 100;

        else if(s=='D')return 500;
        else return 1000;

    }
    int romanToInt(string s) {
        int n=s.size();
        int sum=0;
        int i=0;

        while(i<n-1)
        {
            if(nums(s[i])<nums(s[i+1])){
                sum-=nums(s[i]);

            }
            else{
                sum+=nums(s[i]);

            }
            i++;
        }
        sum+=nums(s[i]);
        return sum;
    }
};