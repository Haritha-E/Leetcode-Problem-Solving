class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        while(left<right){
            int mid=(left+right)/2;
            int totalHrs=0;
            for(auto pile:piles){
                totalHrs+=(pile/mid)+(pile%mid!=0);
                if(totalHrs>h) 
                    break;
            }
            if(totalHrs<=h)
                right=mid;
            else
                left=mid+1;
        }
        return left;
    }
};