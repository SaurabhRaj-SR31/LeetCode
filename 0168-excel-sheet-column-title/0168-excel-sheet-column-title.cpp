class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res="";
        int remainder=-1;

        while(columnNumber>0){
            columnNumber--;
            remainder=columnNumber%26;
            res.push_back(remainder+'A');
            columnNumber=columnNumber/26;

        }
        reverse(res.begin(),res.end());
        return res;
    }
};