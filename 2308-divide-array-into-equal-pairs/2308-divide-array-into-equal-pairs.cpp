class Solution {
public:
   bool divideArray(vector<int>& nums) {
        vector<bool> paired(501, true); 
        //paird[i] = true , means ith element is present in pairs

        for(int &x : nums) {
            paired[x] = !paired[x];
        }

        for(int i = 0; i < 501; i++) {
            if(paired[i] == false) {
                return false;
            }
        }

        return true;


    }
    
};