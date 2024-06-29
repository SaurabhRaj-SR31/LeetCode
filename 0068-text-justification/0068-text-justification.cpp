class Solution {
public:
    string findline(int i,int j,int howmanyspacespergadha,int extraspace,vector<string>&words,int maxWidth)
    {string line;
        for(int k=i;k<j;k++)
        {
            line+=words[k];
            if(k==j-1)continue;
            for(int g=1;g<=howmanyspacespergadha;g++)
            {line+=" ";

            }
            if(extraspace>0)
            {line+=" ";
                extraspace--;
            }
            

            
    

        }
        while(line.size()<maxWidth){
            line+=" ";

            }
            return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int n=words.size();
        int i=0;
        while(i<n)
        {   int lettercnt=words[i].length();
            int j=i+1;
            int gadhe=0;
            while(j<n && (words[j].length()+1+lettercnt+gadhe)<=maxWidth)
            {
                 lettercnt+=words[j].length();
                 gadhe+=1;
                 j++;
            }
            int remainig=maxWidth-lettercnt;
            int howmanyspacespergadha=gadhe==0?0:remainig/gadhe;
            int extraspace=gadhe==0?0:remainig%gadhe;
            if(j==n)
            {
                 howmanyspacespergadha=1;
             extraspace=0;
            }
            string line=findline(i,j,howmanyspacespergadha,extraspace,words, maxWidth);
            res.push_back(line);
            i=j;



        }
        return res;
    }
};
