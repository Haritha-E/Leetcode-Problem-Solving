class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int left=0,min=-1;
        int right=*max_element(bloomDay.begin(),bloomDay.end());
        while(left<=right){
            int bc=0,nofB=0;
            int mid=(left+right)/2;
            for(auto bloom:bloomDay){
                if(bloom<=mid)
                    bc++;
                else
                    bc=0;
                if(bc==k){
                    nofB++;
                    bc=0;
                }
            }
            if(nofB >= m)
            {
                min=mid;
                right=mid-1;
            }
            else
                left=mid+1;
        }
        return min;
    }
};