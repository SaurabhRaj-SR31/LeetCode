class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n=positions.size();
        vector<int>actual_idx(n);
        iota(begin(actual_idx),end(actual_idx),0);
        auto lambda=[&](int i,int j){
            return positions[i]<positions[j];
        };
        sort(begin(actual_idx),end(actual_idx),lambda);vector<int>ans;
        stack<int>st;
        for(auto &cur_idx:actual_idx){
            if(directions[cur_idx]=='R'){
                st.push(cur_idx);
            }
            else{
                while(!st.empty()&& healths[cur_idx]>0){
                    int top_idx=st.top();
                    st.pop();
                    if(healths[top_idx]> healths[cur_idx]){
                         healths[cur_idx]=0;
                         healths[top_idx]-=1;
                         st.push(top_idx);

                    }
                    else if(healths[top_idx]<healths[cur_idx] ){
                         healths[cur_idx]-=1;
                         healths[top_idx]=0;
                    }
                    else {
                         healths[cur_idx]=0;
                         healths[top_idx]=0;
                    }
                }
            }

        }
       
        for(auto &i:healths){
            if(i>0)ans.push_back(i);
        }
return ans;
        
    }
};