class Solution {
public:
    int calculate(string s) {
        int n=s.size();
        int num=0;
        int res=0;
        int sign=1;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(isdigit(s[i])){
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='+'){
                res+=(num*sign);
                num=0;
                sign=1;

            }
             else if(s[i]=='-'){
                 res+=(num*sign);
                num=0;
                sign=-1;
                
            }
             else if(s[i]=='('){
                st.push(res);
                st.push(sign);
                 num=0;
                sign=1;
                res=0;
            }
             else if(s[i]==')'){
                  res+=(num*sign);
                num=0;
                res=(res*st.top());
                st.pop();
                res=res+st.top();
                st.pop();



                
            }
          
        }
         res+=(num*sign);
         return res;
    }
};