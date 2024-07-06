class Solution {
public:
    int passThePillow(int n, int time) {
        int dir=time/(n-1);
        int pos=-1;
        if(dir%2==0){
            pos=time%(n-1)+1;
        }
        else{
            pos=n-time%(n-1);

        }
        return pos;
    }
};