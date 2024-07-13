class Solution {
public:
      vector<int> getnsl(  vector<int>&arr,int n){
        stack<int>st;
        vector<int>res(n);
        for(int i=0;i<n;i++){
             if(st.empty()){
            res[i]=-1;

        }
        else{
            while(!st.empty()&& arr[st.top()]>arr[i])st.pop();
            res[i]=st.empty()?-1:st.top();
        }
        st.push(i);
        }
       
return res;
      }
         vector<int> getnsr(  vector<int>&arr,int n){
        stack<int>st;
        vector<int>res(n);
        for(int i=n-1;i>=0;i--){
             if(st.empty()){
            res[i]=n;

        }
        else{
            while(!st.empty()&& arr[st.top()]>=arr[i])st.pop();
            res[i]=st.empty()?n:st.top();
        }
        st.push(i);
        }
       
return res;
      }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        long long ans=0;
          const int MOD = 1e9 + 7;
           
        vector<int>nsl=getnsl(arr,n);
        vector<int>nsr=getnsr(arr,n);

        

        

        for(int i=0;i<n;i++){
           long long ls = i - nsl[i];
            long long rs = nsr[i] - i;
            long long totways = (ls * rs) % MOD;
            ans = (ans + arr[i] * totways) % MOD;

        }
        return ans;
    }
};