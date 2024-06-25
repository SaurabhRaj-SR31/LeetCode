class Solution {
public:

bool isvowel(char ch) {
    ch = std::tolower(ch);  // Convert character to lowercase
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
    bool halvesAreAlike(string s) {
        int n=s.size();
        int i=0;
        int l=0,r=0;
        int j=n/2;
        while(i<n/2 && j<n){
            if(isvowel(s[i]))l++;
            if(isvowel(s[j]))r++;
i++;j++;

        }
        return l==r;
    }
};