class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int t) {
        int m=matrix.size();
        int n=matrix[0].size();
        int rowidx=m-1, colidx=0;
        while(rowidx>=0 && colidx<n){
            if(matrix[rowidx][colidx]==t)
                return true;
            else if(matrix[rowidx][colidx]<t)
                colidx++;
            else
                rowidx--;
        }
        return false;
    }
};