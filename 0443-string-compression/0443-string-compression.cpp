class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
       
        int i=0;
        int ind=0;
        while(i<n)
        {
           char cur=chars[i];
            int cnt=0;
            while(i<n && chars[i]==cur)
            {
                cnt++;i++;
            }
            chars[ind++]=cur;
            if(cnt>1)
            {
  string str=to_string(cnt);
            for(char &i:str)
            {
                chars[ind++]=i;

            }
            }
          
                    }
                    return ind;
    }
};