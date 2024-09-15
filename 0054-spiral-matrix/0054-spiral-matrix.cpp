class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<int> res;
        int m=matrix[0].size();
        int dir=0;
        int top=0;int down =n-1;
        int left=0;int right=m-1;
        while(top<=down && left <=right){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
             if(dir==1){
                for(int i=top;i<=down;i++){
                    res.push_back(matrix[i][right]);
                }
                right--;
            }
             if(dir==2){
                for(int i=right;i>=left;i--){
                    res.push_back(matrix[down][i]);
                }
                down--;
            }
             if(dir==3){
                for(int i=down;i>=top;i--){
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
            dir=(dir+1)%4;
        }
        return res;
    }
};