class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int left=0, right=m*n-1;
        while(left<=right){
            int mid=(left+right) / 2;
            int rowidx = mid / n;
            int colidx = mid % n;
            if(matrix[rowidx][colidx]==target)
                return true;
            else if(matrix[rowidx][colidx]<target)
                left=mid+1;
            else
                right=mid-1;
        }
        return false;
    }
};