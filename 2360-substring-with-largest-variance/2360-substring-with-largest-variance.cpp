class Solution {
public:
    int largestVariance(string s) {
        int res=0;
        vector<int>arr(26,0);
        for(auto &ch:s)
        {
            arr[ch-'a']=1;
        }
        for(char first='a';first<='z';first++)
        {
        for(char sec='a';sec<='z';sec++)
        {
            if(arr[first-'a']==0 || arr[sec-'a']==0)continue;
            int f1=0;
            int f2=0;
            bool past=false;
            for(auto &ch:s)
            {
                if(ch==first)f1++;
                if(ch==sec)f2++;
                if(f2>f1){
                    f2=0;f1=0;past=true;
                }
                if(f2>0)
                {
                    res=max(res,f1-f2);
                }
                else{
                    if(past==true){
                    res=max(res,f1-1);

                    }
                }


            }
            
        }

        }
        return res;
    }
};