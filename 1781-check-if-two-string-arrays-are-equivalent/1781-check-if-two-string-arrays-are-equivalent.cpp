class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int n=word1.size();
        int m=word2.size();
        int w1=0;
        int w2=0;
        int i=0;
        int j=0;
        while(w1<n && w2<m)
        {
            if(word1[w1][i]!=word2[w2][j])return false;
            i++;j++;
            if(i==word1[w1].size())
            {
                i=0;
                w1++;
            }
            if(j==word2[w2].size())
            {
                j=0;
                w2++;
            }
           
        }
         if(w1==n &&w2==m)return true ;
            else return false;
    }
    
};