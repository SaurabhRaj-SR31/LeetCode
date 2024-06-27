class Solution {
public:
     void computlps(string &pat,vector<int>&lps)
     {
        int len=0;
        int i=1;
        lps[0]=0;
        while(i<pat.size())
        {
            if(pat[i]==pat[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len!=0)
                {
                   len= lps[len-1];

                }else{
                    lps[i]=0;
                    i++;
                }
            }

            

            
        }
     }
    string longestPrefix(string s) {
        int n=s.size();
        vector<int>lps(n,0);
        computlps(s,lps);
     
      return s.substr(0,lps[n-1]);
        // vector<int>ans;
        // int i=0;
        // int j=0;
        // while(i<n)
        // {
        //     if (s[i]==pat[j])
        //     {
        //         i++;j++;
        //     }
        //     if(j==m)
        //     {ans.push_back(i-j);
        //         j=lps[j-1];
        //     }
        //     else if(s[i]!==pat[j])
        //     {
        //         if(j!=0){
        //             j=lps[j-1];
        //         }
        //         else{
        //             i++;
        //         }
        //     }

        //     }
        // }
        // return res;
    }
};