class Solution {
public:
    bool judgeSquareSum(int c) {
         int num = sqrt(c);
        long sum = 0;
        int l = 0, r = num;
        
        while (l <= r) {
            sum = (long)(l * l) + (long)(r * r);
            if (sum == c) {
                return true;
            } else if (sum < c) {
                l++;
            } else {
                r--;
            }
        }
        return false;
       
    }
};