class Solution {
public:
    int compute(int n){
        int s=0;
        while(n!=0){
            s=s+((n%10)*(n%10));
            n/=10;
        }
        return s;
    }
    bool isHappy(int n) {
        int slow=n, fast=n;
        do{
            slow=compute(slow);
            fast=compute(fast);
            fast=compute(fast);
        }while(slow!=fast);
        if(slow==1)
            return true;
        else
            return false;
    }
};