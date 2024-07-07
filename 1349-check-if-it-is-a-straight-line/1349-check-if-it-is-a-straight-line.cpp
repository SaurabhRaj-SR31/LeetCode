class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
         if (coordinates.size()==1) {
            return true;
        }
        int dy=coordinates[1][1]-coordinates[0][1];
        int dx=coordinates[1][0]-coordinates[0][0];
        for(int i=2;i<n;i++){
            int dy_=coordinates[i][1]-coordinates[0][1];
        int dx_=coordinates[i][0]-coordinates[0][0];
        if(dy*dx_!=dy_*dx)return false;
        }
        return true;

    }
};