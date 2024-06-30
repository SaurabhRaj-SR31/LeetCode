class Solution {
public:
     bool isvowel(char ch){
        ch=tolower(ch);
        return (ch=='a'|| ch=='e'||ch=='i'||ch=='o'||ch=='u');
     }
    string sortVowels(string s) {
        int n=s.size();
        unordered_map<char,int>mpp;
        string temp="AEIOUaeiou";
        for(int i=0;i<n;i++)
        {if(isvowel(s[i]))
            mpp[s[i]]++;
        }
        int j=0;
        for(int i=0;i<n;i++)
{
    if(isvowel(s[i])){
        while(mpp[temp[j]]==0)j++;
        s[i]=temp[j];
        mpp[temp[j]]--;

    }
    
}
return s;
    }
};