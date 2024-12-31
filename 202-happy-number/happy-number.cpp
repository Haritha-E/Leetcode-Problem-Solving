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
        do{
            n=compute(n);
        }while(n!=1 && n!=4);
        if(n==1)
            return true;
        else
            return false;
    }
};