class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int min_time=max(abs(fx-sx),abs(fy-sy));
        if(abs(fx-sx)==0 && abs(fy-sy)==0 && t==1)return false;
        if(t<min_time)return false;
        return true;
    }
};