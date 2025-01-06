class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int tp=0,btm=matrix.size()-1;
        int k=1;
        int left=0,right=matrix[0].size()-1;
        while(left<=right&&tp<=btm){
            for(int i=left;i<=right;i++){
                matrix[tp][i]=k;
                k++;
            }
            tp++;
            for(int i=tp;i<=btm;i++){
                matrix[i][right]=k;
                k++;
            }
            right--;
            if(tp<=btm){
            for(int i=right;i>=left;i--){
                matrix[btm][i]=k;
                k++;
            }
            btm--;
            }
            if(left<=right){
            for(int i=btm;i>=tp;i--){
               matrix[i][left]=k;
               k++;
            }
            left++;
            }

        }
        return matrix;
    }
};