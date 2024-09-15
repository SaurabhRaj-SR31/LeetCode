class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
         vector<vector<int>>matrix(n,vector<int>(n,-1));
        int dir=0;
        int top=0;int down =n-1;
        int left=0;int right=n-1;
        int k=1;
        while(top<=down && left <=right && k<=n*n){
            if(dir==0){
                for(int i=left;i<=right;i++){
                    matrix[top][i]=k++;

                }
                top++;
            }
             if(dir==1){
                for(int i=top;i<=down;i++){
                    matrix[i][right]=k++;
                }
                right--;
            }
             if(dir==2){
                for(int i=right;i>=left;i--){
                    matrix[down][i]=k++;
                }
                down--;
            }
             if(dir==3){
                for(int i=down;i>=top;i--){
                    matrix[i][left]=k++;
                }
                left++;
            }
            dir=(dir+1)%4;
            
        }
        return matrix;
    
    }
};