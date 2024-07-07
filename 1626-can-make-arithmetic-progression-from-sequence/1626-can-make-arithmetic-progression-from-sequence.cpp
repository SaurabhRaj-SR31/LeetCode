class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
           int n=arr.size();
           if(n==2)return true;
        int mini=*min_element(begin(arr),end(arr));
        int maxi=*max_element(begin(arr),end(arr));
        if((maxi-mini)%(n-1)!=0)return false;
        int d=(maxi-mini)/(n-1);
        int i=0;
        while(i<n){
            if(arr[i]==(mini+(i)*d))i++;
            else{
            int j=(arr[i]-mini)/d;

                   if(arr[i]==arr[j])return false;
        if((arr[i]-mini)%d!=0)return false;
            swap(arr[i],arr[j]);
            }
         



        }
        return true;
    
    }
};